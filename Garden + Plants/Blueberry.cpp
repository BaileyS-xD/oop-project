#include "Blueberry.h"

Blueberry::Blueberry() : Fruit(){};

void Blueberry::endDay() {growth = growth + 25;
waterLevel = waterLevel - waterUsage;
}

int Blueberry::harvest() { if (growth == 100){
    growth = 50; 
    std::cout << "This crop has been harvested but is still growing." << std::endl;
    return value;
 }else{
    std::cout << "This crop isn't ready for harvest!" << std::endl;
    return 0;
 } 
 }
