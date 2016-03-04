#include <CONTROL/Patron.h>

Patron::Patron(){}
Patron::~Patron(){}


void Patron::addPattern()
{
    dist = pdi.getDist();
    createPattern.addVector(dist);
}

void Patron::setCharacter(string character)
{
    createPattern.setCharacter(character);
}

void Patron::create()
{
    createPattern.average();
    createPattern.createPatron();
}

void Patron::setImg(Mat img, int brithness, double contrast, double gamma)
{
    pdi.setCaliber(brithness, contrast, gamma);
    tmp = pdi.preImprovement(img);
    imshow("Control", tmp);
    pdi.setContours(tmp);
}