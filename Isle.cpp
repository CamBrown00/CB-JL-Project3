#include "Isle.h"
#include <vector>
#include <iostream>

//Item Struct

item::item() : name("spam"), unitCost(.99), unitPrice(1.99), quantity(1) {
}

item::item(string name, double unitCost, double unitPrice, int quantity) : name(name), unitCost(unitCost), unitPrice(unitPrice), quantity(quantity) {
}

ostream& operator << (ostream& outs, const item &it) {
    outs << "Item name: " << it.name << "\tQuantity: " << it.quantity;
    return outs;
}

bool operator == (item &lhs, item &rhs) {
    return (lhs.name == rhs.name) && (lhs.quantity == rhs.quantity) && (lhs.unitCost == rhs.unitCost) && (lhs.unitPrice == rhs.unitPrice);
}

//Isle Class

Isle::Isle() : name("Misc"), items({}), isleCost(0.0), islePrice(0.0), itemQuantity(0) {
}

Isle::Isle(string name, vector<item> items) : name(name), items(items) , isleCost(0.0), islePrice(0.0), itemQuantity(0) {
}

void Isle::refreshIsle() {
    for (int i = 0; i < items.size(); ++i) {
        isleCost += (items[i].unitCost * items[i].quantity);
        islePrice += (items[i].unitPrice * items[i].quantity);
        itemQuantity += items[i].quantity;
        if (items[i].quantity <= 0){
            items.erase(items.begin() + i);
        }
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
            items[i].quantity -= it.quantity;
        }
    }
    refreshIsle();
}

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

void Isle::setName(string name) {
    this->name = name;
}