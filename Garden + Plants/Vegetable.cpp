#include "Vegetable.h"

Vegetable::Vegetable():Plant(){waterUsage = 34;}

void Vegetable::endDay(){
    growth = growth + 20;
    waterLevel = waterLevel - waterUsage;
}

void Vegetable::displayPlant() {
    std::cout << "Growth = "  << growth << "   waterLevel = " << waterLevel << 
    "   Water usage = " << waterUsage << std::endl;
}
