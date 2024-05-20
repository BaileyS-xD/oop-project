#include "Farmer.h"
#include <unistd.h>

using namespace std;

Farmer::Farmer(){
    inventory = new Item*[9];
    money = 500;
    name = "NULL";
    dayNum = 1;
    shop = new Shop;
    invPos = 0;
}

void Farmer::waterPlant(int pos){

}

Item** Farmer::get_Inventory(){
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
    dayNum++;    
}

void Farmer::buy(int n){
    if (n < 4){
        Item* tempItem = shop->buyItem(n);

        if (money >= tempItem->get_cost()) {
            money -= tempItem->get_cost();
            inventory[invPos] = tempItem;
            cout << "Purchase Successful!" << endl;
        } else {
            cout << "ERROR, NOT ENOUGH FUNDS!" << endl;
        }
    } else {
        // buy plants
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
    sleep(2);
    cout << "For Sale:" << endl;
    cout << "1. Fruit Fertiliser: $100" << endl;
    cout << "2. Vegetable Fertiliser: $50" << endl;
    cout << "3. Bug Repellent: $25" << endl;
    cout << "4. Potatoes: $50" << endl;
    cout << "5. Carrots: $60" << endl;
    cout << "6. Blueberries: $55" << endl;
    cout << "7. Apple Tree: $100" << endl;
    cout << "Hint: Without Bug Repellent, your fruit has a chance to die each day!" << endl;
    cout << endl;
    sleep(2);
}

void Farmer::showGarden(){
    
}