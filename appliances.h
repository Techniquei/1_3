#ifndef APPLIANCES_H
#define APPLIANCES_H

#include <kitchenfurniture.h>
#include <QObject>

class Appliances : public KitchenFurniture
{
public:
    Appliances();
    Appliances(float heightSet, float lengthSet, float widthSet,
                        float coordZSet, float coordYSet,float coordXSet, string nameSet);

};

#endif // APPLIANCES_H
