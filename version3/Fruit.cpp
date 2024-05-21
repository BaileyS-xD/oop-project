#include "Fruit.h"
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

Fruit::Fruit():Plant(){waterUsage = 50;}

Fruit::Fruit(string n, int i, int val, bool bugRepel):Plant(){
    name = n;
    waterUsage = i;
    isPlanted = true;
    value = val;
    hasBugRepellent = bugRepel;
}

Fruit::Fruit(string n, int i, int val, bool bugRepel, double grow, bool plant, float water):Plant(){
    name = n;
    waterUsage = i;
    waterLevel = water;
    isPlanted = plant;
    value = val;
    hasBugRepellent = bugRepel;
    growth = grow;
}


Fruit::Fruit(string n, int i, int val):Plant(){
    name = n;
    waterUsage = i;
    isPlanted = true;
    value = val;
    hasBugRepellent = false;
}

bool Fruit::getBugRepellentStatus() { return hasBugRepellent; }

void Fruit::endDay() {
    if (isPlanted == true){
        int randNum;
        bool die = false;
        srand(time(NULL));
        randNum = rand() % 10;
        if (randNum == 1){
            die = true;
        }
        growth = growth + 25;
        if (waterLevel == 0 || die == true){
            isPlanted = false;
            std::cout << "A Fruit has died :(" << std::endl;
        }
        waterLevel = waterLevel - waterUsage;
    }
}

void Fruit::displayPlant() {
    std::cout << "Growth = "  << growth << "   waterLevel = " << waterLevel << 
    "   Water usage = " << waterUsage << "   Bug Repellent Status = " << hasBugRepellent <<  std::endl;
}

int Fruit::getWaterUsage() {
    return waterUsage;
}


