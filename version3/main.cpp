#include "Item.h"
#include "BugRepel.h"
#include "FruitFert.h"
#include "VegFert.h"
#include "Shop.h"
#include "Farmer.h"
#include "Plant.h"
#include "Vegetable.h"
#include "Fruit.h"
#include "Garden.h"

#include <iostream>
#include <unistd.h>
#include <vector>
#include <limits>
#include <fstream>


using namespace std;

int main(){
    Farmer f;
    string name;
    int p1 = 1;
    int p2 = 1;
    int opt1;
    int opt2;
    int load;
    fstream input;

// Loading File
    cout << "Load Save? (1/0)" << endl;
    cin >> load;
    input.open("save.txt");
    if (input && load == 1){
        f.readFile();
        cout << "Welcome back " << f.get_Name() << "! You're currently on day " << f.get_DayNum() << endl;
        f.help();
    } else 
//

// Introduction
    {
    cout << "Welcome! Please choose a name." << endl;
    cin >> name;
    f.set_name(name);
    cout << "Nice to meet you " << name << "!" << endl << endl;
    //sleep(1);
    cout << "The aim of the game is to make as much money as possible, " << endl << "each day you have a limited amount of water to water your plants." << endl << "You need to make choices as to which plants you choose to water, " << endl << "as well as which ones you want to buy and sell. Good Luck!" << endl << endl;
    //sleep(5);
    cout << "Here in the main menu, you can interact with the game through typing the following numbers:" << endl;
    //sleep(2);
    cout << "View Shop: 1" << endl;
    cout << "View Garden: 2" << endl;
    cout << "Water Plants: 3" << endl;
    cout << "End Day: 4" << endl;
    cout << "Help Menu: 5" << endl << endl;
    //sleep(2);
    cout << "Checkout the shop to get started, you can do this by typing 1, here you will be able to buy and sell plants, fertilisers and bug repellent." << endl;
    }
//

// Gameplay
    while (p1 == 1){
        cout << endl;
        cout << "Choose your option:" << endl;
        cin >> opt1;

        switch (opt1){
            case 1 : { // Accessing Shopfront
                p2 = 1;
                while(p2 == 1) {
                    f.shopfront();
                    cout << "Type the number of the item you want to purchase, type 10 to see the options again, or type 11 to return to the main menu." << endl;
                    cin >> opt2;
                    cout << endl;
                    if (opt2 == 1 || opt2 == 2 || opt2 == 3 || opt2 == 4 || opt2 == 5 || opt2 == 6 || opt2 == 7 || opt2 == 8 || opt2 == 9){
                        f.buy(opt2);
                        cout << endl;
                    } else if (opt2 == 10){
                        p2 = 1;
                    } else if (opt2 == 11){
                        p2 = 0;
                        cout << endl;
                        f.help();
                        break;
                    } else { // Error Handling
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "ERROR! INVALID INPUT!" << endl;
                        cout << endl;
                    }
                }
                break;
            }
            case 2 : {
                f.showGarden();
                sleep(3);
                f.help();
                break;
            }
            case 3 : {
                f.waterPlant();
                f.help();
                break;
            }
            case 4 : {
                f.endDay();
                break;
                // end day
            }
            case 5 : {
                cout << endl;
                f.help();
                break;
            }
            default : { // Error Handling
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ERROR! INVALID INPUT!" << endl;
                cout << endl;
                f.help();
                break;
            }
        }
    }
//
}

// TODO:
// Buy / Sell Plants (DONE)
// View Garden (DONE)
// Upgrade stuff under shop (done)
// Water Plants (DONE)
// End Day (DONE)

// FIX SAVE !!!!