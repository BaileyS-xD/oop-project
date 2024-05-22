#include "Vegetable.h"
#include <string>

using namespace std;

Vegetable::Vegetable():Plant(){ // default constructor, null values
    name = "NULL";
    waterUsage = 0;
}

Vegetable::Vegetable(string n, int i, int val):Plant(){ // value constructor
    name = n;
    waterUsage = i;
    isPlanted = true;
    value = val;
}

Vegetable::Vegetable(string n, int i, int val, bool plant, double grow, float water):Plant(){   // loading from save constructor
    name = n;
    waterUsage = i;
    waterLevel = water;
    isPlanted = plant;
    value = val;
    growth = grow;
}

void Vegetable::endDay(){   // end day, increases growth
    growth = growth + 20;
    if (growth >= 100){ // ensures growth is max 100
        growth = 100;
    }
    waterLevel = waterLevel - waterUsage;   // lowers water level
    if (waterLevel <= 0){   // if no water, dies.
        isPlanted = 0;
        cout << "A plant has died due to lack of water!" << endl;
    }
}

void Vegetable::displayPlant() {    // displays vegetable info
    std::cout << "Growth = "  << growth << "   waterLevel = " << waterLevel << 
    "   Water usage = " << waterUsage << std::endl;
}

int Vegetable::getWaterUsage() {    // return water usage
    return waterUsage;
}

bool Vegetable::getBugRepellentStatus(){ return false;} // virtual,