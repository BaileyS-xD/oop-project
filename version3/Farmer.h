#ifndef FARMER
#define FARMER

#include "Item.h"
#include "BugRepel.h"
#include "FruitFert.h"
#include "VegFert.h"
#include "Shop.h"
#include "Plant.h"
#include "Vegetable.h"
#include "Fruit.h"
#include "Blueberry.h"
#include "Garden.h"

#include <iostream>
#include <vector>

class Farmer { // Farmer class, acts as a class to store everything for the player
    protected: // protected variables,
        int money;                      // stores the users money
        int invPos;                     // stores the current inventory positon
        vector<Item*> inventory;        // stores the inventory vector
        string name;                    // stores the player name
        int dayNum;                     // stores the current day number
        Garden* garden;                 // stores the garden class
        Shop* shop;                     // stores the shop class
        int waterCapacity;              // stores the max capacity of the tank
        int waterTank;                  // stores the amount of water
    public: // Appropriate getters for variables, along with functions that the player will use to interact with the game.
        Farmer();
        void waterPlant();
        vector<Item*> get_Inventory();
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
        bool hasFertiliser(string s);
        bool hasBugRepel();

        bool readFile();
        bool writeFile();
};

#endif