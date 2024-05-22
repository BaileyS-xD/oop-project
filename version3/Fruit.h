#ifndef FRUIT
#define FRUIT
#include "Plant.h"


class Fruit : public Plant{
    protected:
        int waterUsage;         // stores water usage of fruit
        bool hasBugRepellent;   // stores if the fruit has bug repellent
    public: 
        Fruit();
        Fruit(string n, int i, int val);
        Fruit(string n, int i, int val, bool bugRepel);
        Fruit(string n, int i, int val, bool bugRepel, double grow, bool plant, float water);
        bool getBugRepellentStatus();
        int getWaterUsage();
        void endDay();
        void displayPlant();
};

#endif