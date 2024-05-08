#ifndef FARMER
#define FARMER

#include "Item.h"
#include "BugRepel.h"
#include "FruitFert.h"
#include "VegFert.h"
#include "Shop.h"

class Farmer {
    protected:
        int money;
        int invPos;
        Item** inventory;
        string name;
        int dayNum;
        //Garden* garden;
        Shop* shop;
    public:
        Farmer();
        void waterPlant(int pos);
        Item** get_Inventory();
        string get_Name();
        int get_DayNum();
        int get_Money();
        void endDay();
        void addInv(string n);
}

#endif