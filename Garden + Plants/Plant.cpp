#include "Plant.h"

Plant::Plant(){growth = 0; waterLevel = 100; isPlanted = false; value = 0;}
Plant::Plant(bool planted){ growth = 0; waterLevel = 100; isPlanted = planted; value = 0;}

void Plant::waterPlant() { waterLevel = 100;}

int Plant::harvest() { if (growth == 100){
    isPlanted = false;
    return value;
 }else{
    std::cout << "This crop isn't ready for harvest!" << std::endl;
    return 0;
 } 
}

// Getters
double Plant::getGrowth() { return growth; }
float Plant::getWaterLevel() { return waterLevel; }
bool Plant::getPlanted() { return isPlanted; }

void Plant::displayPlant() {
   std::cout << "Growth = "  << growth << "   waterLevel = " << waterLevel << std::endl;
}

void Plant::endDay() {}
