/*
 * This is the child class of Store.cpp.
 * This class features a modified version the logBusinessDay method from Store.cpp,
 * as well as some modified logic for determining the store earnings.
 */

#include "Grocery.h"

//Constructors
Grocery::Grocery(): Store() {
    this->isles = isles;
    totalEarnings = 0.0;
    customerCount = 0;
    businessDay b;
    currentBusinessDay = b;
    priceDifference = .9825;
}

Grocery::Grocery(vector<Isle> isles):Store() {
    this->isles = isles;
    islesBackup = isles;
    totalEarnings = 0.0;
    customerCount = 0;
    businessDay b;
    currentBusinessDay = b;
    priceDifference = .9825;
}

//Non-trivial methods

//Modified version of the logBusinessDay function from Store.cpp to better fit the grocery store model
void Grocery::logBusinessDay() {
    //Calculate earnings for the current business day based on sum of earnings values stored in each isle object
    for (int i = 0; i < isles.size(); ++i) {
        currentBusinessDay.earnings += isles[i].getIsleEarnings();
    }
    //Add current business day data to Store total fields
    customerCount += currentBusinessDay.customerCount;
    //Multiply earnings by the store's price difference
    totalEarnings += currentBusinessDay.earnings * priceDifference;

    //Reset business day after pushing to vector of business days
    businessDays.push_back(currentBusinessDay);
    businessDay b;
    currentBusinessDay = b;
}

//Getters and setters
double Grocery::getPriceDifference() {
    return priceDifference;
}
void Grocery::setPriceDifference(double diff) {
    priceDifference = diff;
}