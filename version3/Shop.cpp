#include "Shop.h"

Shop::Shop(){   // default shop constructor, sets items as the different possible items
    FruitFert* ffert = new FruitFert;
    VegFert* vfert = new VegFert;
    BugRepel* brepel = new BugRepel;
    items = new Item*[3];
    items[0] = ffert;
    items[1] = vfert;
    items[2] = brepel;
}

Item** Shop::get_Items(){   // returns items
    return items;
}

Item* Shop::buyItem(int n){     // buy item, returns a pointer to the selected item
    switch (n) {
        case 1: { // fruit
            return items[0];
        }
        case 2: { // veg
            return items[1];
        }
        case 3: { // bug
            return items[2];
        }
        default: {
            return items[0];
        }
    }
}