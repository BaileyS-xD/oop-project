#include "Item.h"

Item::Item(){   // default constructor
    name = "NULL";
    cost = 0;
}

int Item::get_cost(){   // return cost
    return cost;
}

string Item::get_name(){    // return name
    return name;
}