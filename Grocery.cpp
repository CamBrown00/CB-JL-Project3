#include "Grocery.h"

//Constructors
Grocery::Grocery(): Store() {
    this->isles = isles;
    totalEarnings = 0.0;
    customerCount = 0;
    businessDay b;
    currentBusinessDay = b;
}

Grocery::Grocery(vector<Isle> isles):Store() {
    this->isles = isles;
    totalEarnings = 0.0;
    customerCount = 0;
    businessDay b;
    currentBusinessDay = b;
}

//Non-trivial methods
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