#include <iostream>
#include <vector>
#include "Isle.h"

using namespace std;

#ifndef CB_JL_PROJECT3_CUSTOMER_H
#define CB_JL_PROJECT3_CUSTOMER_H

class Customer{
private:
    double wallet;
    double walletBackup;
    vector<item> purchasedItems;

public:

    //Constructors
    Customer();
    Customer(double wallet);

    //Non-trivial Methods
    void purchaseItem(item it);
    void purchaseItems(vector<item> items);

    //Getters and setters
    double getWallet();
    vector<item> getPurchasedItems();
    void setFunds(double wallet);

    //Overloaded Operators
    friend ostream& operator << (ostream& outs, const Customer &c);

};

#endif //CB_JL_PROJECT3_CUSTOMER_H
