#include "Item.h"
#include "BugRepel.h"
#include "FruitFert.h"
#include "VegFert.h"
#include "Shop.h"
#include "Farmer.h"

#include <iostream>
#include <unistd.h>   

using namespace std;

int main(){
    Farmer f;
    string name;
    int p1 = 1;
    int p2 = 1;
    int option;
// Introduction
    cout << "Welcome! Please choose a name." << endl;
    cin >> name;
    
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
//

// Gameplay
    while (p1 == 1){
        cout << endl;
        cout << "Choose your option:" << endl;
        cin >> option;

        switch (option){
            case 1 : { // Accessing Shopfront
                p2 = 1;
                while(p2 == 1) {
                    f.shopfront();
                    cout << "Type the number of the item you want to purchase, type 8 to see the options again, or type 9 to return to the main menu." << endl;
                    cin >> option;
                    cout << endl;
                    if (option < 8){
                        f.buy(option);
                        cout << "Would you like to continue shopping? Y = 1, N = 0" << endl;
                        cin >> p2;
                        cout << endl;
                    } else if (option == 8){
                        p2 = 1;
                    } else if (option == 9){
                        p2 = 0;
                        cout << endl;
                        f.help();
                        break;
                    } else {
                        cout << "ERROR! INVALID INPUT!" << endl;
                    }
                }
                break;
            }
            case 2 : {
                f.showGarden();
                break;
            }
            case 3 : {
                // water plants
            }
            case 4 : {
                f.endDay();
                // end day
            }
            case 5 : {
                cout << endl;
                f.help();
            }
        }
    }
//
}

// TODO:
// Buy Plants
// View Garden
// Water Plants
// End Day