#include "Garden.h"

Garden::Garden() { plants[2] = new Plant; sizeOfGarden = 2;}

void Garden::removePlant(int location)  //removes plant at location
{
    plants[location] = new Plant();
}

void Garden::addPlant(Plant* p,int location) {

        if (plants[location]->getPlanted() == false){
            plants[location] = p;
        }
}

Plant** Garden::getGarden() { return plants; }

void Garden::displayLocation(int location) {
    plants[location]->displayPlant();
   
}

void Garden::dayEnd() {
    int count = 0;
    for(int i = 0; i < sizeOfGarden; i++){
        count++;
        plants[count]->endDay();
    }
}

void Garden::waterLocation(int location) {
    plants[location]->waterPlant();
}
