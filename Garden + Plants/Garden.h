#ifndef GARDEN
#define GARDEN
#include "Plant.h"
#include "Fruit.h"
#include "Vegetable.h"
#include "Blueberry.h"

class Garden {
    protected: 
        Plant** plants;                     //array of Plants
        int sizeOfGarden;                   //how big the garden is
    public:
        Garden();                           //constructor
        void removePlant(int location);     //removes plant at location in the garden
        void addPlant(Plant* p, int location); //adds plant to a slot in the garden
        Plant** getGarden();                // returns the array of plants
        void displayLocation(int location); 
        void dayEnd();
        void waterLocation(int location);

};


#endif 