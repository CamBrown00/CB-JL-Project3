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
void Customer::purchaseItem(item it, Store &s, int quantity) {
    item tempItem(it.name, it.unitCost, it.unitPrice, quantity);
    purchasedItems.push_back(it);
    wallet -= (it.unitPrice * it.quantity);
    s.makeSale(tempItem);
}
void Customer::purchaseItems(vector<item> items, Store &s, int quantity) {
    for (int i = 0; i < items.size(); ++i){
        purchaseItem(items[i], s, quantity);
    }
}

//Getters and setters
double Customer::getWallet() {
    return wallet;
}

vector<item> Customer::getPurchasedItems() {
    return purchasedItems;
}

void Customer::setWallet(double wallet) {
    this->wallet = wallet;
}

void Customer::setWalletBackup(double wallet) {
    walletBackup = wallet;
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

