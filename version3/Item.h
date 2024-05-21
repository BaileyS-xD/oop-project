#ifndef ITEM
#define ITEM

#include <string>

using namespace std;

class Item {
    protected:
        int cost;
        string name;
    public:
        Item();
        int get_cost();
        string get_name();
};


#endif