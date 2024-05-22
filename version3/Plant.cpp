#include "Plant.h"

Plant::Plant(){growth = 0; waterLevel = 100; isPlanted = false; value = 0;}   // default constructor
Plant::Plant(bool planted){ growth = 0; waterLevel = 100; isPlanted = planted; value = 0;}   // planted constructor

void Plant::waterPlant() { // water plant, sets water level to 100
   waterLevel = 100;
   cout << "Watering Successful!" << endl;
   cout << endl;
}

int Plant::harvest() { if (growth == 100){   // if the growth is 100, plant isnt planted and returns value
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
int Plant::getValue() { return value; }
string Plant::getName(){
   return name;
}

int Plant::getWaterUsage(){ 
   return 0;
}

bool Plant::getBugRepellentStatus() {return false;}

// Setters
void Plant::setPlanted(bool planted) { isPlanted = planted; }

void Plant::displayPlant() {  // displays plant info
   std::cout << "Growth = "  << growth << "   waterLevel = " << waterLevel << std::endl;
}

void Plant::endDay() {} // end day, virtual function

