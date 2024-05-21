#include "Blueberry.h"

Blueberry::Blueberry() : Fruit(){    
   name = "Blueberry";
   waterUsage = 50;
   isPlanted = true;
   value = 100;
};

Blueberry::Blueberry(bool bug) : Fruit(){    
   name = "Blueberry";
   waterUsage = 50;
   isPlanted = true;
   value = 100;
   hasBugRepellent = bug;
};

Blueberry::Blueberry(bool bug, double grow, float water) : Fruit(){    
   name = "Blueberry";
   waterUsage = 50;
   isPlanted = true;
   value = 100;
   hasBugRepellent = bug;
   growth = grow;
   waterLevel = water;
};

int Blueberry::harvest() { if (growth == 100){
    growth = 50; 
    std::cout << "This crop has been harvested but is still growing." << std::endl;
    return value;
 }else{
    std::cout << "This crop isn't ready for harvest!" << std::endl;
    return 0;
 } 
 }
