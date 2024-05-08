#include "Item.h"
#include "BugRepel.h"
#include "FruitFert.h"
#include "VegFert.h"
#include "Shop.h"
#include <iostream>

using namespace std;

int main(){
    Shop* shop = new Shop;
    Item** items = shop->get_Items();
    cout << items[0]->get_name() << endl;
    cout << items[1]->get_name() << endl;
    cout << items[2]->get_name() << endl;
    return 0;
}