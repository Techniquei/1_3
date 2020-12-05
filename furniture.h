#ifndef FURNITURE_H
#define FURNITURE_H

#include <QObject>
#include <kitchenfurniture.h>

class Furniture : public KitchenFurniture
{
public:
    Furniture();
    Furniture(float heightSet, float lengthSet, float widthSet,
                        float coordZSet, float coordYSet,float coordXSet, string nameSet, string material);
};

#endif // FURNITURE_H
