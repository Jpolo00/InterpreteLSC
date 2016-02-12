#include <MODEL/PDI.h>

PDI::PDI()
{
    brightness = 0;
    contrast = 0.0;
    gamma = 0.0;
}

PDI::PDI(int brightness,
         double contrast,
         double gamma)
{
    this->brightness = brightness;
    this->contrast = contrast;
    this->gamma = gamma;
}

PDI::~PDI(){}

void PDI::setCaliber(int brightness,
                     double contrast,
                     double gamma)
{
    this->brightness = brightness;
    this->contrast = contrast;
    this->gamma = gamma;
}

Mat PDI::convertColorSpace(Mat img)
{
    cvtColor(img, tmp, CV_BGR2HSV);
    return tmp;
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

    //imshow("Improvement", tmp);
    return tmp;
}

vector<vector<Point> > PDI::segmentation(Mat img)
{
    //tmp = groupColorRang(img);
    tmp = img;
    threshold(tmp, tmp2, 128, 255, THRESH_BINARY); //THRESH_BINARY_INV
    tmp = tmp2;

    cvtColor(tmp, tmp2, CV_RGB2GRAY);
    tmp = tmp2;
    threshold(tmp, tmp2, 100, 255, THRESH_BINARY);
    tmp = tmp2;

    // imshow("Thres", tmp);

    //medianBlur(tmp, tmp2, 3);
    medianBlur(tmp, tmp2, 7);
    tmp = tmp2;

    // GaussianBlur(tmp, tmp2, Size(5, 5), 5, 10);
    // tmp = tmp2;


    // dilate(tmp, tmp2, element);
    // tmp = tmp2;
    // dilate(tmp, tmp2, element);
    // tmp = tmp2;
    // erode(tmp, tmp2, element);
    // tmp = tmp2;
    // erode(tmp, tmp2, element);
    // tmp = tmp2;

    imshow("Erode- Dilate", tmp);

    //Canny(tmp, tmp2, 200, 255, 3);
    Canny(tmp, tmp2, 50, 200, 3);
    tmp = tmp2;

    imshow("Canny", tmp);

    contours.resize(0);
    hierarchy.resize(0);

    findContours(tmp, contours, 
                      hierarchy, 
                      CV_RETR_CCOMP, //CV_RETR_TREE, //CV_RETR_EXTERNAL, //CV_RETR_LIST 
                      CV_CHAIN_APPROX_SIMPLE, //CV_CHAIN_APPROX_TC89_KCOS, //CV_CHAIN_APPROX_TC89_L1, //CV_CHAIN_APPROX_NONE, 
                      Point(0, 0));

    return contours;
}

vector<vector<Point> > PDI::filterContours(vector<vector<Point> > contours)
{
    contours2.clear();
    contours2.resize(0);

    if(!contours.empty())
    {
        contours2.resize(1);
    }

    for (size_t i = 0; i < contours.size(); i++)
    {
        if (arcLength(contours[i], false) >= 200.0)
        {
            for (size_t j = 0; j < contours[i].size(); j++)
            {
                contours2[0].push_back(contours[i][j]);
            }
        }
    }

    drawing = Mat::zeros(tmp.size(), CV_8UC3);
    drawContours(drawing, contours2, 0, Scalar(255, 0, 0), 1, 8, hierarchy, 0, Point());

    imshow("contorno", drawing);

    return contours2;
}

Mat PDI::groupColorRang(Mat img)
{
    for (size_t j = 0; j < sizeMatColorRang; j++)
    {
        for (size_t i = 0; i < sizeColorRang; i += 2)
        {
            inRange(img, colorRang[i], colorRang[i + 1], matColorRang[j]);
        }
    }

    tmp =  matColorRang[0];

    for (size_t i = 1; i < sizeMatColorRang ; i++)
    {
        addWeighted(tmp.clone(), 1.0, matColorRang[i], 1.0, 0.0, tmp);
    }

    return tmp;
}

vector<double> PDI::characteristic(vector<vector<Point> > contours)
{
    arrayMomentsHu.clear();

    try
    {
        for (size_t i = 0; i < contours.size(); i++)
        {
            mnts = moments(contours[i]);
            HuMoments(mnts, momentsHu);

            for (size_t j = 0; j < 7; j++)
            {
                arrayMomentsHu.push_back(momentsHu[j]);
            }
        }
    }
    catch(...)
    {
        for (size_t j = 0; j < 7; j++)
        {
            arrayMomentsHu.push_back(0);
        }
    }

    return arrayMomentsHu;
}