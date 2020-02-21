/*
 * This is the unrelated class for the project.
 * This class is meant to model a customer in the store who is going to purchase items from the isles.
 * There are functions in this class for making a purchase, updating wallet, etc.
 */

#include <iostream>
#include <vector>
#include "Isle.h"
#include "Store.h"

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
    void purchaseItem(item it, Store &s, int quantity);
    void purchaseItems(vector<item> items, Store &s, int quantity);

    //Getters and setters
    double getWallet();
    vector<item> getPurchasedItems();
    void setWallet(double wallet);
    void setWalletBackup(double wallet);

    //Overloaded Operators
    friend ostream& operator << (ostream& outs, const Customer &c);

};

#endif //CB_JL_PROJECT3_CUSTOMER_H
