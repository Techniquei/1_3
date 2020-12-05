#include "furniture.h"

Furniture::Furniture()
{
    this->height = 1;
    this->length = 1;
    this->width = 1;
    this->coordZ = 0;
    this->coordY = 0;
    this->coordX = 0;
    this->name = "untitled";
    this->material = "empty";
    cout<<"\nDefault object Furniture is created. Cordinates by default 0,0,0. dimensions 1,1,1 by default.";
}
Furniture::Furniture(float heightSet, float lengthSet, float widthSet,
                                 float coordZSet, float coordYSet, float coordXSet, string nameSet, string materialSet)
{
    this->setData(heightSet, lengthSet, widthSet, coordZSet, coordYSet, coordXSet, nameSet, materialSet);
}
