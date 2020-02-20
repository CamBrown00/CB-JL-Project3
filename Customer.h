#include <iostream>
#include <vector>
#include "Isle.h"

using namespace std;

#ifndef CB_JL_PROJECT3_CUSTOMER_H
#define CB_JL_PROJECT3_CUSTOMER_H

class Customer{
private:
    double funds;
    vector<item> purchasedItems;

public:

    //Constructors
    Customer();
    Customer(double wallet);

    //Getters and setters
    double getWallet();
    vector<item> getPurchasedItems();
    void setFunds(double wallet);

};

#endif //CB_JL_PROJECT3_CUSTOMER_H
