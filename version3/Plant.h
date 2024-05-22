#ifndef PLANT
#define PLANT
#include <iostream>
#include <string>

using namespace std;

class Plant{
    protected:
        double growth;             //percentage of plant growth
        float waterLevel;          //percentage the plant is watered
        bool isPlanted;             //if the plant is planted or not
        int value;                  // value of plant
        string name;                // name of plant
    public: 
        Plant();                    //constructor
        Plant(bool planted);        //creates an 'empty' or planted plant
        void waterPlant();          //sets water level to 100
        virtual void endDay();      //advances the growth of the plant by a day and has additional functionality for fruits
        virtual int harvest();     //harvests the plant and adds money to inventory
        double getGrowth();         //Getters
        float getWaterLevel();
        bool getPlanted();
        int getValue();
        virtual bool getBugRepellentStatus() = 0;
        virtual int getWaterUsage() = 0;
        void setPlanted(bool planted);
        string getName();
        virtual void displayPlant();
        

};




#endif