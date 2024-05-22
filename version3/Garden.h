#ifndef GARDEN
#define GARDEN
#include "Plant.h"
#include "Fruit.h"
#include "Vegetable.h"
#include "Blueberry.h"
#include <vector>
#include <fstream>
#include <string>

class Garden {
    protected: 
        vector<Plant*> plants;                    //array of Plants
        int sizeOfGarden;                   //how big the garden is
    public:
        Garden();                           //constructor
        int removePlant(int location);     //removes plant at location in the garden
        bool addPlant(Plant* p, int location); //adds plant to a slot in the garden
        vector<Plant*> getGarden();                // returns the array of plants
        void displayLocation(int location); 
        void dayEnd();
        void waterLocation(int location);
        int getSize();
        void resizeGarden(int n);
        void writeFile(ofstream& output);
        void readFile(ifstream& input);

};


#endif 