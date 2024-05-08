#include "Farmer.h"

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

void Farmer::addInv(string n){
    switch (n) {
        case "Fruit Fertiliser":
            FruitFert* ffert = new FruitFert;
            inventory[invPos] = ffert;
            invPos++;
            break;
        case "Vegetable Fertiliser":
            VegFert* vfert = new VegFert;
            inventory[invPos] = vfert;
            invPos++;
            break;
        case "Bug Repellent":
            BugRepel* brepel = new BugRepel;
            inventory[invPos] = brepel;
            invPos++;
            break;
    }
}
