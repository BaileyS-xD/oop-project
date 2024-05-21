#include "Fruit.h"

Fruit::Fruit():Plant(){waterUsage = 50;}

Fruit::Fruit(bool bugRepel):Plant(){waterUsage = 50; hasBugRepellent = bugRepel;}

bool Fruit::getBugRepellentStatus() { return hasBugRepellent; }

void Fruit::endDay() {
    growth = growth + 25;
    if (waterLevel == 0 || hasBugRepellent == false){
        std::cout << "A Fruit has died :(" << std::endl;
    }
    waterLevel = waterLevel - waterUsage;
}

void Fruit::displayPlant() {
    std::cout << "Growth = "  << growth << "   waterLevel = " << waterLevel << 
    "   Water usage = " << waterUsage << "   Bug Repellent Status = " << hasBugRepellent <<  std::endl;
}


