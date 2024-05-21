#ifndef VEGETABLE
#define VEGETABLE
#include "Plant.h"

using namespace std;

class Vegetable : public Plant {
    protected:
        int waterUsage;
    public:
        Vegetable(); 
        Vegetable(string n, int i, int val);
        Vegetable(string n, int i, int val, bool plant, double grow, float water);
        void endDay();              //to be run when the day ends, adds growth and reduces water level
        void displayPlant();        //displays waterusage, growth and waterlevel
        int getWaterUsage();
        bool getBugRepellentStatus();
};



#endif