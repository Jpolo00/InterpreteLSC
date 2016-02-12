#include <CONTROL/Interpret.h>

Interpret::Interpret() 
{
    pdi.setCaliber(30, 1.0, 1.0);
}

Interpret::~Interpret() {}

void Interpret::updatePattern()
{
    clasificator.loadPatterns();
}

string Interpret::interpretSing(Mat img, int brithness, 
                                       double contrast, 
                                       double gamma, 
                                       double alpha)
{
    pdi.setCaliber(brithness - 255, contrast / 300.0, gamma / 100.0);
    tmp = pdi.preImprovement(img);
    tmp = pdi.convertColorSpace(tmp);
    contours.clear();
    contours = pdi.segmentation(tmp);
    contours = pdi.filterContours(contours);
    momentsHu.clear();
    momentsHu = pdi.characteristic(contours);

    character = "";
    for (size_t i = 0; i < momentsHu.size(); i++)
    {
        character += clasificator.distanceMin(momentsHu, alpha);
    }

    return character;
}