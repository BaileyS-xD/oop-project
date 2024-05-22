#include "Fruit.h"
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

Fruit::Fruit():Plant(){ // default constructor, null values
    name = "NULL";
    value = 0;
    waterUsage = 50;
}

Fruit::Fruit(string n, int i, int val, bool bugRepel):Plant(){  // value constructor
    name = n;
    waterUsage = i;
    isPlanted = true;
    value = val;
    hasBugRepellent = bugRepel;
}

Fruit::Fruit(string n, int i, int val, bool bugRepel, double grow, bool plant, float water):Plant(){ // loading from save constructor
    name = n;
    waterUsage = i;
    waterLevel = water;
    isPlanted = plant;
    value = val;
    hasBugRepellent = bugRepel;
    growth = grow;
}


Fruit::Fruit(string n, int i, int val):Plant(){ // no bug repel constructor
    name = n;
    waterUsage = i;
    isPlanted = true;
    value = val;
    hasBugRepellent = false;
}

bool Fruit::getBugRepellentStatus() { return hasBugRepellent; } // return if fruit has bug repel

void Fruit::endDay() {  // end day,
    if (isPlanted == true){ // if the plant is planted, 
        int randNum;
        bool die = false;
        if (hasBugRepellent == false){    // if plant doesnt have bug repel, roll a random number to die 1 in 10 chance
            srand(time(NULL));
            randNum = rand() % 10;
            if (randNum == 1){
                die = true;
            }
        }
        growth = growth + 25;   // grow the plant
        if (growth >= 100){     // ensure growth doesnt exceed 100
            growth = 100;
        }
        if (waterLevel <= 0 || die == true){    // if the waterlevel is lessthan or equal to 0 or the plant died, isplanted is false
            isPlanted = false;
            std::cout << "A Fruit has died :(" << std::endl;
        }
        waterLevel = waterLevel - waterUsage;   // lower water level of the plant
    }
}

void Fruit::displayPlant() {        // outputs status of the plant
    std::cout << "Growth = "  << growth << "   waterLevel = " << waterLevel << 
    "   Water usage = " << waterUsage << "   Bug Repellent Status = " << hasBugRepellent <<  std::endl;
}

int Fruit::getWaterUsage() {        // returns water usage
    return waterUsage;
}


