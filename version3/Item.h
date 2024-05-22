#ifndef ITEM
#define ITEM

#include <string>

using namespace std;

class Item {
    protected:
        int cost;       //cost of item
        string name;    //name of item
    public:
        Item();
        int get_cost();
        string get_name();
};


#endif