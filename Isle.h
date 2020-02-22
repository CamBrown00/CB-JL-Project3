/*
 * This is the Component class for the project.
 * This class is meant to model the isles within the Store.cpp, contains a vector of items to models items on shelves
 * There are functions in this class for removing items from isles, adding items, assessing isle data, etc.
 * This class also contains a struct for items that holds an item name, price data and quantity
 */

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
    friend ostream& operator << (ostream& outs, const item &it);
    friend bool operator == (item &lhs, item &rhs);
};

class Isle{
private:
    string name;
    vector<item> items;
    double isleCost;
    double islePrice;
    double isleEarnings;
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
    double getIsleEarnings();
    void setName(string name);

    //Overloaded Operators
    friend ostream& operator << (ostream& outs, const Isle &is);
};

#endif //CB_JL_PROJECT3_ISLE_H
