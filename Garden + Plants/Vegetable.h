#ifndef VEGETABLE
#define VEGETABLE
#include "Plant.h"

class Vegetable : public Plant {
    protected:
        int waterUsage;
    public: 
        Vegetable();
        void endDay();              //to be run when the day ends, adds growth and reduces water level
        void displayPlant();        //displays waterusage, growth and waterlevel


};



#endif