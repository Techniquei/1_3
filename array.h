#ifndef ARRAY_H
#define ARRAY_H
#include "kitchenfurniture.h"
#include "furniture.h"
#include <vector>

class Array
{
private:
    vector<KitchenFurniture> array;
    int size;
public:
    Array();
    ~Array() {
        array.clear();
    };
    Array(float heightSet, float lengthSet, float widthSet,
          float coordZSet, float coordYSet,float coordXSet, string nameSet, string materialSet);
    Array(const Array& A);
    void addElement(KitchenFurniture i);
    void addElement(Furniture);
    void addElement(float heightSet, float lengthSet, float widthSet,
               float coordZSet, float coordYSet,float coordXSet, string nameSet, string materialSet);
    void addFurniture(float heightSet, float lengthSet, float widthSet,
               float coordZSet, float coordYSet,float coordXSet, string nameSet, string materialSet);
    void addAppliances(float heightSet, float lengthSet, float widthSet,
                       float coordZSet, float coordYSet,float coordXSet, string nameSet);
    void deleteElement(int index);
    void cleanVector();
    int getSize();
    vector<KitchenFurniture> getVector();
    KitchenFurniture indexSearch(int index);
    bool arrayCheck();
    bool compare(Array arr1, Array arr2);
    int toFile(string path);

};

#endif // ARRAY_H
