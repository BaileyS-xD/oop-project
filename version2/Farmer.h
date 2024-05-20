#ifndef FARMER
#define FARMER

#include "Item.h"
#include "BugRepel.h"
#include "FruitFert.h"
#include "VegFert.h"
#include "Shop.h"
#include <iostream>

class Farmer { // Farmer class, acts as a class to store everything for the player
    protected: // protected variables,
        int money;
        int invPos;
        Item** inventory;
        string name;
        int dayNum;
        //Garden* garden;
        Shop* shop;
    public: // Appropriate getters for variables, along with functions that the player will use to interact with the game.
        Farmer();
        void waterPlant(int pos);
        Item** get_Inventory();
        Item*  get_Inventory(int n);
        string get_Name();
        void set_name(string n);
        int get_DayNum();
        int get_Money();

        void showGarden();
        void shopfront();
        void endDay();
        void buy(int n);
        void help();
};

#endif