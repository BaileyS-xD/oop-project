#include "Garden.h"

Garden::Garden() { 
    plants.resize(2);
    sizeOfGarden = 2;
    plants[0] = new Vegetable;
    plants[1] = new Fruit;
}

int Garden::removePlant(int location)  //removes plant at location
{
    if (plants[location]->getName() == "Blueberry"){
        return plants[location]->harvest();
    } else {
        plants[location]->setPlanted(false);
        return plants[location]->getValue();
    }
}

bool Garden::addPlant(Plant* p, int location) {

        if (location >= sizeOfGarden){
            cout << "ERROR, Invalid positon!" << endl;
            return false;
        } else if (plants[location]->getPlanted() == false){
            plants[location] = p;
            return true;
        } else {
            cout << "There is already a plant here!" << endl;
            return false;
        }
} 

vector<Plant*> Garden::getGarden() { return plants; }

void Garden::displayLocation(int location) {
    plants[location]->displayPlant();
   
}

void Garden::dayEnd() {
    int count = 0;
    for(int i = 0; i < sizeOfGarden; i++){
        plants[count]->endDay();
        count++;
    }
}

void Garden::waterLocation(int location) {
    plants[location]->waterPlant();
}

int Garden::getSize(){
    return sizeOfGarden;
}

void Garden::resizeGarden(int n){
    plants.resize(n);
    sizeOfGarden = n;
    plants.push_back(new Fruit);
}

void Garden::writeFile(ofstream& output) {
    // Write the size of the garden to the file
    output << sizeOfGarden << endl;

    // Write each plant to the file
    for (int i = 0; i < sizeOfGarden; ++i) {
        // Serialize the plant and write it to the file
        output << plants[i]->getName() << endl; // Write plant name
        output << plants[i]->getWaterLevel() << endl;
        output << plants[i]->getPlanted() << endl; // Write whether plant is planted or not
        if (plants[i]->getName() == "Blueberry" || plants[i]->getName() == "Strawberry"){
            output << plants[i]->getBugRepellentStatus() << endl;
        }
        output << plants[i]->getValue() << endl; // Write plant value
        output << plants[i]->getWaterUsage() << endl; // Write plant water usage
        output << plants[i]->getGrowth() << endl; // Write plant growth
    }
}

void Garden::readFile(ifstream& input) {
    // Read the size of the garden from the file
    input >> sizeOfGarden;
    plants.resize(sizeOfGarden);
    // Read each plant from the file
    for (int i = 0; i < sizeOfGarden; i++) {
        string plantName;
        input >> plantName;
        float waterLevel;
        input >> waterLevel;
        bool isPlanted;
        input >> isPlanted;
        int value;
        input >> value;
        int waterUsage;
        input >> waterUsage; 
        double growth;
        input >> growth;
        if (plantName == "Blueberry"){
            bool hasBugRepellent;
            input >> hasBugRepellent;
            plants[i] = new Blueberry(hasBugRepellent, growth, waterLevel);
        }else if (plantName == "Strawberry"){
            bool hasBugRepellent;
            input >> hasBugRepellent;
            plants[i] = new Fruit(plantName, waterUsage, value, hasBugRepellent, growth, isPlanted, waterLevel); 
        } else if (plantName == "Carrot" || plantName == "Potato") {
            plants[i] = new Vegetable(plantName, waterUsage, value, isPlanted, growth, waterLevel);
        }
    }
}