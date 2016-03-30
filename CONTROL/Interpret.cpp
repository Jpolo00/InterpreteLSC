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

    character = "No Found...";

    if (dist.size() != 0)
    {
        character = clasificator.dtw(dist);
    }

    return character;
}