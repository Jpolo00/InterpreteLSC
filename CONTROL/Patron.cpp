#include <CONTROL/Patron.h>

Patron::Patron(){}
Patron::~Patron(){}

//void Patron::addPattern(Mat img, int brithness, double contrast, double gamma)
void Patron::addPattern()
{
    // pdi.setCaliber(brithness - 255, contrast / 300.0, gamma / 100.0);
    // tmp = pdi.preImprovement(img);
    // tmp = pdi.convertColorSpace(tmp);
    // contours.clear();
    // contours = pdi.segmentation(tmp);
    // momentsHu.clear();
    // momentsHu = pdi.characteristic(contours);

    createPattern.addVector(momentsHu);
}

void Patron::setCharacter(string character){

    createPattern.setCharacter(character);
}

void Patron::create(){
    createPattern.average();
    createPattern.createPatron();
}

void Patron::drawContour(Mat img, int brithness, double contrast, double gamma)
{
    pdi.setCaliber(brithness - 255, contrast / 300.0, gamma / 100.0);
    tmp = pdi.preImprovement(img);
    tmp = pdi.convertColorSpace(tmp);
    contours.clear();
    contours = pdi.segmentation(tmp);
    contours = pdi.filterContours(contours);
    momentsHu.clear();
    momentsHu = pdi.characteristic(contours);
}