#ifndef PLANT
#define PLANT
#include <iostream>

class Plant{
    protected:
        double growth;             //percentage of plant growth
        float waterLevel;          //percentage the plant is watered
        bool isPlanted;             //if the plant is planted or not
        int value;
    public:
        Plant();                    //constructor
        Plant(bool planted);        //creates an 'empty' or planted plant
        void waterPlant();          //sets water level to 100
        virtual void endDay();      //advances the growth of the plant by a day and has additional functionality for fruits
        virtual int harvest();     //harvests the plant and adds money to inventory
        double getGrowth();         //Getters
        float getWaterLevel();
        bool getPlanted();
        virtual void displayPlant();
        

};




#endif