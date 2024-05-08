#include "Item.h"

Item::Item(){
    name = "NULL";
    cost = 0;
}

int Item::get_cost(){
    return cost;
}

string Item::get_name(){
    return name;
}