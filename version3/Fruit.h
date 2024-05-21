#ifndef FRUIT
#define FRUIT
#include "Plant.h"


class Fruit : public Plant{
    protected:
        int waterUsage;
        bool hasBugRepellent;
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