#include <iostream>
#include <vector>

using namespace std;

#ifndef CB_JL_PROJECT3_ISLE_H
#define CB_JL_PROJECT3_ISLE_H

struct item{
    string name;
    double unitCost;
    double unitPrice;
    int quantity;

    //Constructors
    item();
    item(string name, double unitCost, double unitPrice, int quantity);

    //Overloaded Operators
    friend ostream& operator << (ostream& outs, const item &bD);
    friend bool operator == (item &lhs, item &rhs);
};

class Isle{
private:
    string name;
    vector<item> items;
    double isleCost;
    double islePrice;
    int itemQuantity;

public:

    //Constructors
    Isle();
    Isle(string name, vector<item> items);

    //Non-trivial methods
    void addItem(item it);
    void addItems(vector<item> items);
    void removeItem(item it);
    void refreshIsle();

    //Getters and Setters
    string getName();
    vector<item> getItems();
    double getIsleCost();
    double getIslePrice();
    int getItemQuantity();
    void setName(string name);
};

#endif //CB_JL_PROJECT3_ISLE_H
