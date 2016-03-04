#include <CONTROL/Interpret.h>

Interpret::Interpret() 
{
    pdi.setCaliber(255, 300, 100);
}

Interpret::~Interpret() {}

void Interpret::updatePattern()
{
    clasificator.loadPatterns();
}

string Interpret::interpretSing(Mat img, int brithness, 
                                       double contrast, 
                                       double gamma)
{
    pdi.setCaliber(brithness, contrast, gamma);
    tmp = pdi.preImprovement(img);
    imshow("Control", tmp);
    pdi.setContours(tmp);
    dist = pdi.getDist();

    // for (size_t i = 0; i < dist.size(); i++)
    // {
    //     cout << dist[i] << endl;
    // }

    // cout << endl;
    // cout << endl;

    character = "";
    character += clasificator.distanceMin(dist);

    return character;
}