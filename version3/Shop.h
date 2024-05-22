#ifndef SHOP
#define SHOP

#include "Item.h"
#include "BugRepel.h"
#include "FruitFert.h"
#include "VegFert.h"

using namespace std;

class Shop {
    protected:
        Item** items;       // array of items

    public:
        Shop();
        Item* buyItem(int n);
        Item** get_Items();
};

#endif