#include <MODEL/PDI.h>

PDI::PDI()
{
    brightness = 0;
    contrast = 0.0;
    gamma = 0.0;
}

PDI::~PDI(){}

void PDI::setCaliber(int brightness,
                     double contrast,
                     double gamma)
{
    this->brightness = brightness - 255.0;
    this->contrast = contrast / 200.0;
    this->gamma = gamma / 200.0;
}

Mat PDI::preImprovement(Mat img)
{
    Mat lut_matrix(1, 256, CV_8UC1);
    uchar *ptr = lut_matrix.ptr();

    for(size_t i = 0; i < 256; i++)
    {
        ptr[i] = (int)(pow(i / 255.0, gamma) * 255.0);
    }

    LUT(img, lut_matrix, tmp);

    tmp.convertTo(tmp, -1, contrast, brightness);
    return tmp;
}

double PDI::distPoint(Point p1, Point p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
double PDI::slope(Point p1, Point p2)
{
    return (p1.y - p2.y) / ((p1.x - p2.x) * 1.0);
}
double PDI::distPerpendicular(Point p1, Point p2, double m)
{
    return m * (p1.x - p2.x) + (p2.y - p1.y) / sqrt(m * m + 1);
}
double PDI::angle2Line(Point p1, double m1, Point p2, double m2)
{
    short signeX = (p1.x - p2.x);
    short signeY = (p1.y - p2.y);

    if (signeX == 0)
    {
        signeX = 1;
    }
    else
    {
        signeX /= abs(signeX);
    }

    if (signeY == 0)
    {
        signeY = 1;
    }
    else
    {
        signeY /= abs(signeY);
    }

    double m = (m1 - m2) / (1 + m1*m2);
    double angle = atan(abs(m));

    angle *= 180 / M_PI;

    if (signeX == -1 && signeY == 1)
    {
        angle = 180 - angle;
    }
    else if (signeX == -1 && signeY == -1)
    {
        angle = 270 - angle;
    }
    else if (signeX == 1 && signeY == -1)
    {
        angle = 360 - angle;
    }

    return angle;
}

vector<size_t> PDI::orderVector(vector<double> data)
{
    size_t value1;
    size_t i, j, k;
    size_t vectorSize = data.size();

    double value2;

    vector<size_t> item(vectorSize);

    for (size_t i = 0; i < item.size(); i++)
    {
        item[i] = i;
    }

    for (i = vectorSize / 2; i > 0; i /= 2)
    {
        for (j = i; j < vectorSize; j++)
        {
            value1 = item[j];
            value2 = data[j];
            for (k = j; k >= i; k -= i)
            {
                if (value2 > data[k - i])
                {
                    item[k] = item[k - i];
                    data[k] = data[k - i];
                }
                else
                {
                    break;
                }
            }
            item[k] = value1;
            data[k] = value2;
        }
    }

    return item;
}

void PDI::swapDataVector(vector<size_t> item, 
                         vector<Point> point)
{
    vector<Point> swap(point.size());
    size_t index;

    for (size_t i = 0; i < item.size(); i++)
    {
        index = item[i];
        swap[i] = point[index];
    }
}

vector<Point> PDI::filterContours(double threshold)
{
    vector<Point> pointClear;

    for (size_t i = 0; i < contours.size(); i++)
    {
        if (arcLength(contours[i], false) > threshold)
        {
            for (size_t j = 0; j < contours[i].size(); j++)
            {
                pointClear.push_back(contours[i][j]);
            }
        }
    }


    return pointClear;
}

 vector<Point2f> PDI::rectImg(vector<Point> point)
{
    vector<Point> hull;
    vector<Point2f> pointsRect(5);
    Point2f points[4];

    RotatedRect rect;

    convexHull(Mat(point), hull, true);
    rect = minAreaRect(Mat(hull));
    rect.points(points);
    rect = fitEllipse(Mat(hull));

    for (size_t i = 0; i < 4; i++)
    {
        pointsRect[i] = points[i];
    }

    pointsRect[4] = rect.center;

    return pointsRect;
}

Mat PDI::rotImg(Mat img, Point2f center, double angle)
{
    Mat rotated;
    Mat rot_mat = getRotationMatrix2D(center, angle, 1.0);
    warpAffine(img, rotated, rot_mat, img.size());

    return rotated;
}

Mat PDI::cutImg(Mat img, Point p1, Point p2)
{
    int alto = abs(p2.y - p1.y);
    int ancho = abs(p2.x - p1.x);
    Mat cut;
    Mat scala;
    Size size(100, 100);

    Rect rect(p2.x, p2.y, ancho, alto);
    Mat (img, rect).copyTo(cut);
    resize(cut, scala, size);
    return scala;
}

void PDI::setContours(Mat img)
{
    contours.clear();
    hierarchy.clear();

    // cvtColor(img, tmp, CV_BGR2HSV);
    // inRange(tmp, Scalar(50, 0, 0), Scalar(100, 255, 255), tmp2);

    cvtColor(img, tmp, CV_BGR2GRAY);
    // tmp = tmp2;
    gray = tmp;
    imshow("Proceso3", tmp);
    threshold(tmp, tmp2, 128, 255, THRESH_BINARY);
    tmp = tmp2;

    medianBlur(tmp, tmp2, 3);
    tmp = tmp2;

    dilate(tmp, tmp2, element);
    tmp = tmp2;
    erode(tmp, tmp2, element);
    tmp = tmp2;

    Canny(tmp, tmp2, 50, 200, 3);
    tmp = tmp2;
    rot = tmp2;

    imshow("Canny", tmp);

    findContours(tmp, contours, 
                 hierarchy, 
                 CV_RETR_CCOMP,
                 CV_CHAIN_APPROX_SIMPLE,
                 Point(0, 0));

    point = filterContours(200.0);

    Mat drawing;
    drawing = Mat::zeros(img.size(), CV_8UC3);
    vector<vector<Point> > drawPoint;
    drawPoint.clear();
    drawPoint.resize(1);
    for (size_t i = 0; i < point.size(); i++)
    {
        drawPoint[0].push_back(point[i]);
    }

    drawContours(drawing, drawPoint, 0, Scalar(0, 255, 0), 1, 8, 
                 hierarchy, 0, Point());

     imshow("filtrado2", drawing);

    try
    {
    //     rectPoint = rectImg(point);
    //     m = slope(rectPoint[0], rectPoint[1]);
    //     if (rectPoint[0] != rectPoint[1])
    //     {
    //         angle = angle2Line(rectPoint[0], m, rectPoint[1], 0.0) - 90;
    //     }
    //     else
    //     {
    //         angle = 0.0;
    //     }

        // angle = 0.0;
        // tmp = rotImg(rot, rectPoint[4], angle);

        // findContours(tmp, contours, 
        //              hierarchy, 
        //              CV_RETR_CCOMP,
        //              CV_CHAIN_APPROX_SIMPLE,
        //              Point(0, 0));

        point = filterContours(0.1);
        rectPoint = rectImg(point);

        pointX.clear();
        pointY.clear();

        // for (size_t i = 0; i < 4; i++)
        // {
        //     pointX.push_back(rectPoint[i].x);
        //     pointY.push_back(rectPoint[i].y);
        // }
        for (size_t i = 0; i < point.size(); i++)
        {
            pointX.push_back(point[i].x * 1.0);
            pointY.push_back(point[i].y * 1.0);
        }

        itemX = orderVector(pointX);
        itemY = orderVector(pointY);

        pointCut1 = Point(Point(pointX[itemX[0]], 
                                pointY[itemY[0]]));

        pointCut2 = Point(Point(pointX[itemX[itemX.size() - 1]], 
                                pointY[itemY[itemY.size() - 1]]));

        imshow("Cut", gray);
        threshold(gray, tmp, 128, 255, THRESH_BINARY);
        tmp2 = cutImg(tmp, pointCut1, pointCut2);
        tmp = tmp2;
        medianBlur(tmp, tmp2, 3);
        tmp = tmp2;
        erode(tmp, tmp2, element);
        tmp = tmp2;
        erode(tmp, tmp2, element);
        tmp = tmp2;
        dilate(tmp, tmp2, element);
        tmp = tmp2;
        dilate(tmp, tmp2, element);
        tmp = tmp2;
        Canny(tmp, tmp2, 50, 200, 3);
        tmp = tmp2;
        imshow("Cut2", tmp2);


        findContours(tmp, contours, 
                     hierarchy, 
                     CV_RETR_CCOMP,
                     CV_CHAIN_APPROX_SIMPLE,
                     Point(0, 0));
        point = filterContours(100.0);

        pointY.clear();
        for (size_t i = 0; i < point.size(); i++)
        {
            pointY.push_back(point[i].y * 1.0);
        }

        itemY = orderVector(pointY);
        swapDataVector(itemY, point);



        dist.clear();
        for (size_t i = 0; i < point.size(); i++)
        {
            dist.push_back(distPoint(rectPoint[4], point[i]));
        }
        drawPoint.clear();
        drawPoint.resize(1);

        for (size_t i = 0; i < point.size(); i++)
        {
            drawPoint[0].push_back(point[i]);
        }
        drawing = Mat::zeros(tmp.size(), CV_8UC3);
        drawContours(drawing, drawPoint, 0, Scalar(0, 255, 0), 1, 8, 
                     hierarchy, 0, Point());
        // circle(drawing, rectPoint[4], 50, Scalar(0, 0, 255), 1, 8);

        imshow("rotate", drawing);
    }
    catch(...){}
}

vector<vector<Point> > PDI::getContours()
{
    return contours;
}

vector<Vec4i> PDI::getHierarchy()
{
    return hierarchy;
}

vector<double> PDI::getDist()
{
    return dist;
}