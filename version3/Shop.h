#ifndef SHOP
#define SHOP

#include "Item.h"
#include "BugRepel.h"
#include "FruitFert.h"
#include "VegFert.h"

using namespace std;

class Shop {
    protected:
        Item** items;

    public:
        Shop();
        Item* buyItem(int n);
        void sellPlant(int pos);
        void upgradeGarden();
        void upgradeWater();
        Item** get_Items();
        void buyPlant();
};

#endif