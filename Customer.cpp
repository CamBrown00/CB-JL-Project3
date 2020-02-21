#include "Customer.h"
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

//Constructors
Customer::Customer() : wallet(0), walletBackup(0), purchasedItems({}) {
}

Customer::Customer(double wallet) : wallet(wallet), walletBackup(wallet), purchasedItems({}) {
}

//Non-trivial Methods
void Customer::purchaseItem(item it) {
    purchasedItems.push_back(it);
    wallet -= (it.unitPrice * it.quantity);
}
void Customer::purchaseItems(vector<item> items) {
    for (int i = 0; i < items.size(); ++i){
        purchaseItem(items[i]);
    }
}

//Getters and setters
double Customer::getWallet() {
    return wallet;
}

vector<item> Customer::getPurchasedItems() {
    return purchasedItems;
}

void Customer::setFunds(double wallet) {
    this->wallet = wallet;
}

//Overloaded Operators
ostream& operator << (ostream& outs, const Customer &c) {
    string itemId;
    string walletInfo = "Starting wallet: $" + to_string(c.walletBackup) + "|\tEnding Wallet: $" + to_string(c.wallet) + "\n";
    outs << left << walletInfo;
    for(int i = 0; i < c.purchasedItems.size(); ++i) {
        outs << setw(30) << left << c.purchasedItems[i];
    }
    return outs;
}

