#include "Farmer.h"
#include <unistd.h>

#include <fstream>

using namespace std;

Farmer::Farmer(){           // default constructor, sets initial values
    inventory.resize(9);
    money = 500;
    name = "NULL";
    garden = new Garden;
    dayNum = 1;
    shop = new Shop;
    invPos = 0;
    waterCapacity = 100;
    waterTank = waterCapacity;
}

void Farmer::waterPlant(){      // waters plants, user inputs a position and the plant at that position is watered
    vector<Plant*> tempPlants = garden->getGarden();
    int pos;
    float water;
    showGarden();
    cout << "Your water tank currently has " << waterTank << "L" << endl;
    cout << "Please enter the number of the plant you wish to water." << endl;
    cin >> pos;
    pos--;
    water = tempPlants[pos]->getWaterLevel();       // gets the current water level,
    water = 100 - water;                            // sets the difference of that water level to 100
    garden->waterLocation(pos);                  
    waterTank -= water;                             // takes the difference from the water tank
}

vector<Item*> Farmer::get_Inventory(){ // returns inventory vector
    return inventory;
}

Item* Farmer::get_Inventory(int n){   // returns item at inventory[n]
    return inventory[n];
}

string Farmer::get_Name(){          // returns name
    return name;
}

int Farmer::get_DayNum(){           // returns dayNum
    return dayNum;
}
int Farmer::get_Money(){            // returns money
    return money;
}

void Farmer::endDay(){              // ends the day, refill water tank, grow all the plants, increase day num and save the game
    waterTank = waterCapacity;
    garden->dayEnd();
    dayNum++;
    writeFile();
    readFile();
    cout << "Welcome to Day " << dayNum << " " << name << "! Check out your garden to see how things are going." << endl;
    help();

}

void Farmer::buy(int n){        // buy function, user can buy items from the shop
    int pos;
    if (n < 4){                 // buying items that will go into your inventory
        Item* tempItem = shop->buyItem(n);

        if (money >= tempItem->get_cost()) {
            money -= tempItem->get_cost();
            inventory[invPos] = tempItem;
            invPos++;
            cout << "Purchase Successful!" << endl;
        } else {
            cout << "ERROR, NOT ENOUGH FUNDS!" << endl;
        }
    } else if (n == 4){         // buying plants, 
        Plant* tempPlant = new Vegetable("Potato", 34, 50);
        if (hasFertiliser("Vegetable Fertiliser") == true){
            if (money >= tempPlant->getValue()){
                cout << "Please enter the position of where you would like the plant to be planted" << endl;
                cin >> pos;
                pos--;
                if (garden->addPlant(tempPlant, pos) == true){
                    money -= tempPlant->getValue();
                    cout << "Planting Successful!" << endl;
                    //sleep(1);
                }
            } else {        // error checking for funds
                cout << "ERROR, NOT ENOUGH FUNDS!" << endl;
            }
        } else {            // error checking for fertiliser, required to plant.
            cout << "ERROR, YOU DON'T HAVE ANY FERTILISER! BUY SOME FROM THE SHOP!" << endl;
        }
    } else if (n == 5){
        Plant* tempPlant = new Vegetable("Carrot", 40, 60);
        if (hasFertiliser("Vegetable Fertiliser") == true){
            if (money >= tempPlant->getValue()){
                cout << "Please enter the position of where you would like the plant to be planted" << endl;
                cin >> pos;
                pos--;
                if (garden->addPlant(tempPlant, pos) == true){
                    money -= tempPlant->getValue();
                    cout << "Planting Successful!" << endl;
                    //sleep(1);
                }
            } else {
                cout << "ERROR, NOT ENOUGH FUNDS!" << endl;
            }
        } else {
            cout << "ERROR, YOU DON'T HAVE ANY FERTILISER! BUY SOME FROM THE SHOP!" << endl;
        }
    } else if (n == 6){
        Plant* tempPlant;
        if (hasBugRepel() == true){     // if a user has bug repellent in their inventory, its added to the fruit
            tempPlant = new Blueberry(true);
            cout << "Bug Repellent Used!" << endl;
        } else {
            tempPlant = new Blueberry();
        }
        if (hasFertiliser("Fruit Fertiliser") == true){
            if (money >= tempPlant->getValue()){
                cout << "Please enter the position of where you would like the plant to be planted" << endl;
                cin >> pos;
                pos--;
                if (garden->addPlant(tempPlant, pos) == true){
                    money -= tempPlant->getValue();
                    cout << "Planting Successful!" << endl;
                    //sleep(1);
                }
            } else {
                cout << "ERROR, NOT ENOUGH FUNDS!" << endl;
            }
        } else {
            cout << "ERROR, YOU DON'T HAVE ANY FERTILISER! BUY SOME FROM THE SHOP!" << endl;
        }
    } else if (n == 7){
        Plant* tempPlant;
        if (hasBugRepel() == true){
            tempPlant = new Fruit("Strawberry", 40, 55, true);
            cout << "Bug Repellent Used!" << endl;
        } else {
            tempPlant = new Fruit("Strawberry", 40, 55);
        }
        if (hasFertiliser("Fruit Fertiliser") == true){
            if (money >= tempPlant->getValue()){
                cout << "Please enter the position of where you would like the plant to be planted" << endl;
                cin >> pos;
                pos--;
                if (garden->addPlant(tempPlant, pos) == true){
                    money -= tempPlant->getValue();
                    cout << "Planting Successful!" << endl;
                    //sleep(1);
                }
            } else {
                cout << "ERROR, NOT ENOUGH FUNDS!" << endl;
            }
        } else {
            cout << "ERROR, YOU DON'T HAVE ANY FERTILISER! BUY SOME FROM THE SHOP!" << endl;
        }
    } else if (n == 8){     // buy increased water capacity
        if (money >= 400){
            waterCapacity += 100;
            cout << "Water Tank Capacity successfully increased by 100L" << endl;
            money -= 400;
        } else {
            cout << "ERROR! NOT ENOUGH FUNDS!" << endl;
        }
    } else if (n == 9){     // increase garden size
        if (money >= 200){
            int n = (garden->getSize() + 1);
            garden->resizeGarden(n);
            cout << "Garden Size increased by 1!" << endl;
        } else {
            cout << "ERROR! NOT ENOUGH FUNDS!" << endl;
        }
    }
}

void Farmer::set_name(string n){        // set name
    name = n;
}

void Farmer::help(){        // help function, displays list of options
    cout << "Welcome to the Main Menu!" << endl;
    cout << "View Shop: 1" << endl;
    cout << "View Garden: 2" << endl;
    cout << "Water Plants: 3" << endl;
    cout << "End Day: 4" << endl;
    cout << endl;
}

void Farmer::shopfront(){   // shop front, displays all the items available in the shop and your money
    cout << "Welcome to the Shop Front!" << endl;
    cout << "You currently have: $" << money << endl;
    //sleep(2);
    cout << "For Sale:" << endl;
    cout << "1. Fruit Fertiliser: $100" << endl;
    cout << "2. Vegetable Fertiliser: $50" << endl;
    cout << "3. Bug Repellent: $25" << endl;
    cout << "4. Potatoes: $50" << endl;
    cout << "5. Carrots: $60" << endl;
    cout << "6. Blueberries: $100" << endl;
    cout << "7. Strawberries: $55" << endl;
    cout << "8. Upgrade Water Tank: $400" << endl;
    cout << "9. Upgrade Garden Size by 1: $200" << endl;
    cout << "Hint: Without Bug Repellent, your fruit has a chance to die each day!" << endl;
    cout << "Hint: To sell your plants, view your Garden." << endl;
    cout << endl;
    //sleep(2);
}

void Farmer::showGarden(){      // displays garden, also where you can harvest plants
    bool harv;
    int pos;
    int val;
    vector<Plant*> tempPlants = garden->getGarden();
    cout << "Your Garden currently has " << garden->getSize() << " spots." << endl;
    for (int i = 0; i < garden->getSize(); i++){    // display the name of each plant and its details
        if (tempPlants[i]->getPlanted() == true){
            cout << "In spot " << (i+1) << " there is a " << tempPlants[i]->getName() << endl;
            tempPlants[i]->displayPlant();
            if (tempPlants[i]->getGrowth() == 100){     // if a plant is fully grown, user can harvest
                cout << "This plant is ready for harvest, type " << (i+1) <<  " to harvest!" << endl;
                harv = true;
            }
            cout << endl;
        } else {
            cout << "There is nothing in spot " << (i+1) << endl;
            cout << endl;
        }
    }
    if (harv == true){      // if there is a plant to harvest, user can input the position of the plant they want to harvest
        cin >> pos;
        pos--;
        if (tempPlants[pos]->getGrowth() == 100){ // error checking to make sure the plant selected is fully grown
            val = garden->removePlant(pos);
            money = money + val;
            cout << "Harvest Successful! $" << val << " has been added to your account!" << endl;
        } else {
            cout << "Invalid Input! Harvest Failed!" << endl;
        }
    }
}

bool Farmer::hasFertiliser(string s){       // check to see if a user has fertiliser in their inventory
    for (int i = 0; i < invPos; i++){
        if (inventory[i]->get_name() == s){
            inventory[i] = new Item;
            invPos--;
            return true;
        }
    }
    return false;
}

bool Farmer::hasBugRepel(){                 // check to see if bug repellent in inv
    for (int i = 0; i < invPos; i++){
        if (inventory[i]->get_name() == "Bug Repellent"){
            inventory[i] = new Item;
            invPos--;
            return true;
        }
    }
    return false;
}

bool Farmer::readFile() {               // file loading
    ifstream input; // open the file
    input.open("save.txt", ios::in);
    if (input.is_open()) {              // error checking, ensure file is open before beginning to read
        // Read farmer data first
        input >> money;
        input >> invPos;
        inventory.resize(9);            // input variables
        for (int i = 0; i < 9; ++i) {   // input each inventory item
            inventory[i] = new Item;
            string itemName;
            int itemCost;
            if (invPos > 0){
                input >> itemName >> itemCost;
                if (itemName == "Fruit Fertiliser") {
                    inventory[i] = new FruitFert;
                } else if (itemName == "Vegetable Fertiliser") {
                    inventory[i] = new VegFert;
                } else if (itemName == "Bug Repellent") {
                    inventory[i] = new BugRepel;
                }
            }
        }
        input >> name;
        input >> dayNum;
        garden->readFile(input); // input garden data
        input >> waterCapacity;

        input.close(); // close the file
        return true;
    } else {
        cout << "Unable to open file." << endl;
        return false;
    }
}

bool Farmer::writeFile(){       // file saving
    ofstream output;    // output file,
    output.open("save.txt", ios::out);
    if (output) {   // error checking
        output << money << endl;
        output << invPos << endl; // writing variables
        for (int i = 0; i < invPos; ++i) {      // writing each inventory item
            if (inventory[i]->get_name() != "NULL"){
            output << inventory[i]->get_name() << endl;
            output << inventory[i]->get_cost() << endl;
            }
        }
        output << name << endl;
        output << dayNum << endl;
        garden->writeFile(output); // write garden data
        output << waterCapacity << endl;

        output.close();
        return true;
    } else {
        cout << "Unable to open file." << endl;
        return false;
    }
}