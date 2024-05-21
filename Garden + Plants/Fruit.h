#ifndef FRUIT
#define FRUIT
#include "Plant.h"


class Fruit : public Plant{
    protected:
        int waterUsage;
        bool hasBugRepellent;
    public: 
        Fruit();
        Fruit(bool bugRepel);
        bool getBugRepellentStatus();
        void endDay();
        void displayPlant();
};

#endif