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
        void buyItem(string n);
        void sellPlant(int pos);
        void upgradeGarden();
        void upgradeWater();
        Item** get_Items();
        void buyPlant();
};