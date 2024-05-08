#include "Shop.h"
#include "Farmer.h"

Shop::Shop(){
    FruitFert* ffert = new FruitFert;
    VegFert* vfert = new VegFert;
    BugRepel* brepel = new BugRepel;
    items = new Item*[3];
    items[0] = ffert;
    items[1] = vfert;
    items[2] = brepel;
}

Item** Shop::get_Items(){
    return items;
}

void Shop::buyItem(string n){
    switch (n) {
        case "Fruit Fertiliser":
            
            break;
        case "Vegetable Fertiliser":

            break;
        case "Bug Repellent":

            break;
    }
}

void Shop::buyPlant(){

}

void Shop::sellPlant(int pos){

}

void Shop::upgradeGarden(){

}

void Shop::upgradeWater(){

}