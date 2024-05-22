#include "Garden.h"

Garden::Garden() { // default constructor, creates a garden of size 2
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

bool Garden::addPlant(Plant* p, int location) {     // sets the location in the plants array to the pointer p

        if (location >= sizeOfGarden || location < 0){      // error checking
            cout << "ERROR, Invalid positon!" << endl;
            return false;
        } else if (plants[location]->getPlanted() == false){    // checks if there is a plant there already
            plants[location] = p;
            return true;
        } else {        // else returns false
            cout << "There is already a plant here!" << endl;
            return false;
        }
} 

vector<Plant*> Garden::getGarden() { return plants; }       // return plants vector

void Garden::displayLocation(int location) {        // display data for plant at location
    plants[location]->displayPlant();
   
}

void Garden::dayEnd() {     // ends day, ends day for each plant
    int count = 0;
    for(int i = 0; i < sizeOfGarden; i++){
        plants[count]->endDay();
        count++;
    }
}

void Garden::waterLocation(int location) {  // water plant at location
    if (location < 0 || location >= sizeOfGarden){
        cout << "Error! Invalid Location" << endl;
    } else {
        plants[location]->waterPlant();
    }
}

int Garden::getSize(){              // return size
    return sizeOfGarden;
}

void Garden::resizeGarden(int n){       // resize garden when being upgraded
    plants.resize(n);
    sizeOfGarden = n;
    plants[n-1] = new Fruit;
}

void Garden::writeFile(ofstream& output) {  // writing garden to file
    output << sizeOfGarden << endl;
    for (int i = 0; i < sizeOfGarden; ++i) {    // writing each plant to file
        if (plants[i]->getName() != "NULL"){    // if the plant exists,
            output << plants[i]->getName() << endl; // write all the variables of that plant
            output << plants[i]->getWaterLevel() << endl;
            output << plants[i]->getPlanted() << endl;
            output << plants[i]->getValue() << endl;
            output << plants[i]->getWaterUsage() << endl;
            output << plants[i]->getGrowth() << endl;
            if (plants[i]->getName() == "Blueberry" || plants[i]->getName() == "Strawberry"){   // if its a fruit, write bug repel status
                output << plants[i]->getBugRepellentStatus() << endl;
            }
        }
    }
}

void Garden::readFile(ifstream& input) {    // reading to garden from file
    plants.clear(); // clearing the plants vector
    std::string plantName;
    float waterLevel;
    bool isPlanted;
    int value;
    int waterUsage; 
    double growth;
    bool hasBugRepellent;

    input >> sizeOfGarden;
    plants.resize(sizeOfGarden); // setting plants to size of sizeOfGarden
    for (int i = 0; i < sizeOfGarden; i++){ // initialising values 
        plants[i] = new Vegetable;
    }
    for (int i = 0; i < sizeOfGarden; i++) {    // for each plant, input its data
        input >> plantName;
        input >> waterLevel;
        input >> isPlanted;
        input >> value;
        input >> waterUsage; 
        input >> growth;
        if (plantName == "Blueberry"){  // if blueberry, call blueberry constructor and store
            input >> hasBugRepellent;
            plants[i] = new Blueberry(hasBugRepellent, growth, waterLevel, isPlanted);
        }else if (plantName == "Strawberry"){   // strawberry, strawberry constructor and store
            input >> hasBugRepellent;
            plants[i] = new Fruit(plantName, waterUsage, value, hasBugRepellent, growth, isPlanted, waterLevel); 
        } else if (plantName == "Carrot" || plantName == "Potato") {    // vegetable, vegetable constructor and store
            plants[i] = new Vegetable(plantName, waterUsage, value, isPlanted, growth, waterLevel);
        }
    }
}