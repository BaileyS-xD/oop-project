#ifndef BLUEBERRY
#define BLUEBERRY
#include "Fruit.h"

class Blueberry : public Fruit{
    protected:
        
    public:
        Blueberry();
        Blueberry(bool bug);
        Blueberry(bool bug, double grow, float water);
        int harvest();
};



#endif