#include "Garden.h"

int main(){

Garden g1;

g1.addPlant(new Vegetable, 1);
g1.addPlant(new Blueberry, 2);

g1.displayLocation(1);
g1.displayLocation(2);

g1.dayEnd();

g1.displayLocation(1);
g1.displayLocation(2);


    return 0;
}