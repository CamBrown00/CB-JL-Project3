#include "Isle.h"
#include <vector>
#include <iostream>
#include <iomanip>

//Item Struct

item::item() : name("spam"), unitCost(.99), unitPrice(1.99), quantity(1) {
}

item::item(string name, double unitCost, double unitPrice, int quantity) : name(name), unitCost(unitCost), unitPrice(unitPrice), quantity(quantity) {
}

ostream& operator << (ostream& outs, const item &it) {
    string itemName = it.name + " x " + to_string(it.quantity);
    outs << left << setw(20) << itemName << right << " | ";
    return outs;
}

bool operator == (item &lhs, item &rhs) {
    return (lhs.name == rhs.name) && (lhs.quantity == rhs.quantity) && (lhs.unitCost == rhs.unitCost) && (lhs.unitPrice == rhs.unitPrice);
}

//Isle Class

//Constructors
Isle::Isle() : name("Misc"), items({}), isleCost(0.0), islePrice(0.0), itemQuantity(0), isleEarnings(0) {
}

Isle::Isle(string name, vector<item> items) : name(name), items(items) , isleCost(0.0), islePrice(0.0), itemQuantity(0), isleEarnings(0) {
    refreshIsle();
}


//Non-trivial methods
void Isle::refreshIsle() {
    for (int i = 0; i < items.size(); ++i) {
        if (items[i].quantity < 0){
            items[i].quantity = 0;
        }
        isleCost += (items[i].unitCost * items[i].quantity);
        islePrice += (items[i].unitPrice * items[i].quantity);
        itemQuantity += items[i].quantity;
        /*
        if (items[i].quantity < 0){
            items.erase(items.begin() + i);
        }
         */
    }
}

void Isle::addItem(item it) {
    items.push_back(it);
    refreshIsle();
}

void Isle::addItems(vector<item> items) {
    for (int i = 0; i < items.size(); ++i) {
        this->items.push_back(items[i]);
    }
    refreshIsle();
}

void Isle::removeItem(item it) {
    for (int i = 0; i < items.size(); ++i) {
        if (items[i].name == it.name){
            isleEarnings += ((items[i].unitPrice - items[i].unitCost) * items[i].quantity);
            items[i].quantity -= it.quantity;
            refreshIsle();
        }
    }
}


//Getters and setters
string Isle::getName() {
    return name;
}

vector<item> Isle::getItems() {
    return items;
}

double Isle::getIsleCost() {
    return isleCost;
}

double Isle::getIslePrice() {
    return islePrice;
}

int Isle::getItemQuantity() {
    return itemQuantity;
}

double Isle::getIsleEarnings() {
    return isleEarnings;
}

void Isle::setName(string name) {
    this->name = name;
}

//Overloaded Operators
ostream& operator << (ostream& outs, const Isle &is) {
    string isleName = is.name + " Isle:";
    outs << left << setw(15) << isleName;
    for(int i = 0; i < is.items.size(); ++i) {
        outs << setw(30) << left << is.items[i];
    }
    return outs;
}