#include "Vegetable.h"
#include <string>

using namespace std;

Vegetable::Vegetable():Plant(){
    name = "NULL";
    waterUsage = 0;
}

Vegetable::Vegetable(string n, int i, int val):Plant(){
    name = n;
    waterUsage = i;
    isPlanted = true;
    value = val;
}

Vegetable::Vegetable(string n, int i, int val, bool plant, double grow, float water):Plant(){
    name = n;
    waterUsage = i;
    waterLevel = water;
    isPlanted = plant;
    value = val;
    growth = grow;
}

void Vegetable::endDay(){
    growth = growth + 20;
    waterLevel = waterLevel - waterUsage;
}

void Vegetable::displayPlant() {
    std::cout << "Growth = "  << growth << "   waterLevel = " << waterLevel << 
    "   Water usage = " << waterUsage << std::endl;
}

int Vegetable::getWaterUsage() {
    return waterUsage;
}

bool Vegetable::getBugRepellentStatus(){ return false;}