#include "Farmer.h"
#include <unistd.h>

#include <fstream>

using namespace std;

Farmer::Farmer(){
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

void Farmer::waterPlant(){
    vector<Plant*> tempPlants = garden->getGarden();
    int pos;
    showGarden();
    cout << "Your water tank currently has " << waterTank << "L" << endl;
    cout << "Please enter the number of the plant you wish to water." << endl;
    cin >> pos;
    pos--;
    garden->waterLocation(pos);
    waterTank -= tempPlants[pos]->getWaterUsage();
}

vector<Item*> Farmer::get_Inventory(){
    return inventory;
}

Item* Farmer::get_Inventory(int n){
    return inventory[n];
}

string Farmer::get_Name(){
    return name;
}

int Farmer::get_DayNum(){
    return dayNum;
}
int Farmer::get_Money(){
    return money;
}

void Farmer::endDay(){
    waterTank = waterCapacity;
    garden->dayEnd();
    dayNum++;
    writeFile();
    readFile();
    cout << "Welcome to Day " << dayNum << " " << name << "! Check out your garden to see how things are going." << endl;
    help();

}

void Farmer::buy(int n){
    int pos;
    if (n < 4){
        Item* tempItem = shop->buyItem(n);

        if (money >= tempItem->get_cost()) {
            money -= tempItem->get_cost();
            inventory[invPos] = tempItem;
            invPos++;
            cout << "Purchase Successful!" << endl;
        } else {
            cout << "ERROR, NOT ENOUGH FUNDS!" << endl;
        }
    } else if (n == 4){
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
            } else {
                cout << "ERROR, NOT ENOUGH FUNDS!" << endl;
            }
        } else {
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
        if (hasBugRepel() == true){
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
    } else if (n == 8){
        if (money >= 400){
            waterCapacity += 100;
            cout << "Water Tank Capacity successfully increased by 100L" << endl;
            money -= 400;
        } else {
            cout << "ERROR! NOT ENOUGH FUNDS!" << endl;
        }
    } else if (n == 9){
        if (money >= 200){
            int n = garden->getSize() + 1;
            garden->resizeGarden(n);
            cout << "Garden Size increased by 1!" << endl;
        } else {
            cout << "ERROR! NOT ENOUGH FUNDS!" << endl;
        }
    }
}

void Farmer::set_name(string n){
    name = n;
}

void Farmer::help(){
    cout << "Welcome to the Main Menu!" << endl;
    cout << "View Shop: 1" << endl;
    cout << "View Garden: 2" << endl;
    cout << "Water Plants: 3" << endl;
    cout << "End Day: 4" << endl;
    cout << endl;
}

void Farmer::shopfront(){
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

void Farmer::showGarden(){
    bool harv;
    int pos;
    int val;
    vector<Plant*> tempPlants = garden->getGarden();
    cout << "Your Garden currently has " << garden->getSize() << " spots." << endl;
    for (int i = 0; i < garden->getSize(); i++){
        if (tempPlants[i]->getPlanted() == true){
            cout << "In spot " << (i+1) << " there is a " << tempPlants[i]->getName() << endl;
            tempPlants[i]->displayPlant();
            if (tempPlants[i]->getGrowth() == 100){
                cout << "This plant is ready for harvest, type " << (i+1) <<  " to harvest!" << endl;
                harv = true;
            }
            cout << endl;
        } else {
            cout << "There is nothing in spot " << (i+1) << endl;
            cout << endl;
        }
        if (harv == true){
            cin >> pos;
            pos--;
            val = garden->removePlant(pos);
            money = money + val;
            cout << "Harvest Successful! $" << val << " has been added to your account!" << endl;
        }
    }
}

bool Farmer::hasFertiliser(string s){
    for (int i = 0; i < invPos; i++){
        if (inventory[i]->get_name() == s){
            inventory[i] = new Item;
            return true;
        }
    }
    return false;
}

bool Farmer::hasBugRepel(){
    for (int i = 0; i < invPos; i++){
        if (inventory[i]->get_name() == "Bug Repellent"){
            inventory[i] = new Item;
            return true;
        }
    }
    return false;
}

bool Farmer::readFile() {
    ifstream input("save.txt"); // Open the file for reading
    if (input.is_open()) {
        // Read farmer data first
        input >> money;
        input >> invPos;
        inventory.resize(invPos);
        for (int i = 0; i < invPos; ++i) {
            string itemName;
            int itemCost;
            input >> itemName >> itemCost;
            if (itemName == "Fruit Fertiliser") {
                inventory[i] = new FruitFert;
            } else if (itemName == "Vegetable Fertiliser") {
                inventory[i] = new VegFert;
            } else if (itemName == "Bug Repellent") {
                inventory[i] = new BugRepel;
            }
        }
        input >> name;
        input >> dayNum;
        garden->readFile(input); // Read garden contents
        input >> waterCapacity;
        input >> waterTank;

        input.close(); // Close the file
        return true; // Return true indicating successful read
    } else {
        cout << "Unable to open file." << endl; // Display error message if unable to open file
        return false; // Return false indicating unsuccessful read
    }
}

bool Farmer::writeFile(){
    ofstream output ("save.txt"); // Open the file for writing
    if (output.is_open()) {
        // Write each variable to the file, separated by newlines or other delimiters
        output << money << endl; // Write money
        output << invPos << endl; // Write invPos
        for (int i = 0; i < invPos; ++i) {
            // Write each item in the inventory
            output << inventory[i]->get_name() << endl; // Write item name
            output << inventory[i]->get_cost() << endl; // Write item cost
        }
        output << name << endl; // Write name
        output << dayNum << endl; // Write dayNum
        garden->writeFile(output); // Write garden contents
        output << waterCapacity << endl; // Write waterCapacity
        output << waterTank << endl; // Write waterTank

        output.close(); // Close the file
        return true; // Return true indicating successful write
    } else {
        cout << "Unable to open file." << endl; // Display error message if unable to open file
        return false; // Return false indicating unsuccessful write
    }
}