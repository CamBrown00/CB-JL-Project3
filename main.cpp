/*
 * This program was created by Cameron Brown and Justin Lai
 * The main purpose of this program is to simulate business within a store, specifically a grocery store
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include "Store.h"
#include "Isle.h"
#include "Customer.h"
#include "Grocery.h"

using namespace std;

//Global functions
void beginSimulation(Store store);
void simulateBusinessDay(Store &store, int customerLimit);
int getInput();

int main() {
    //Initialize Items
    item i1("tuna", .50, 2.50, 800);
    item i2("porkchop", .75, 6.50, 500);
    item i3("sausage", .60, 4.41, 800);
    item i4("bananas", .20, 1.50, 700);
    item i5("apples", .15, 1.10, 550);
    item i6("grapes", .42, 1.65, 650);
    item i7("ravioli", .80, 8.40, 180);
    item i8("alfredo", .72, 6.54, 190);
    item i9("spaghetti", .63, 5.36, 500);
    item i10("utensils", 1.5, 15.00, 200);
    item i11("pots", 1.0, 20.0, 300);
    item i12("pans", 1.1, 21.0, 300);

    //Initialize each Isle with a name and a vector of items
    Isle is1("Meats", {i1, i2, i3});
    Isle is2("Fruits", {i4, i5, i6});
    Isle is3("Pasta", {i7, i8, i9});
    Isle is4("Kitchenware", {i10, i11, i12});

    //Declare vector<Isle> and push Isles onto it
    vector<Isle> isles;
    isles.push_back(is1);
    isles.push_back(is2);
    isles.push_back(is3);
    isles.push_back(is4);

    //Declare Store obj and begin making sales/logging business days
    Grocery g1(isles);

    //Begin simulation
    beginSimulation(g1);

    //This is a commented-out example of how to use the store class
    /*
    item i14("tuna", .50, 2.50, 1);

    g1.makeSale(i14);
    g1.logBusinessDay();
    g1.printStore();

    cout << g1.getBusinessDays()[0] << endl;
    cout << g1.getTotalEarnings() << endl;
     */

    return 0;
}

//Runs an interactive simulation for a desired number of business days for a store, which logs results of each day
void beginSimulation(Store store) {
    int choice;

    cout << "\n********************************" << endl;
    cout << "Welcome to the Store Simulator!" << endl;
    cout << "********************************" << endl;
    while (choice != 0) {
        cout << "\nOPTIONS: " << endl;
        cout << "Run simulation automatically (1)\n" << "Run manual business day simulation (2)\n"
        << "Display Business Day logs (3)\n" << "Restock Store (4)\n" << "Cancel simulation (0)\n" << endl;
        store.printStore();
        cout << "\nPlease input your choice here:";
        choice = getInput();

        //Perform actions based on user choice
        switch (choice) {
            case 0:
                break;
            case 1: {
                int cycleLength = 0;
                int customerLimit = 0;
                while (cycleLength <= 0) {
                    cout << "Please input the number of business days you would like to simulate:";
                    cycleLength = getInput();
                    cout << endl;
                }
                while (customerLimit <= 0) {
                    cout << "Please enter the customer limit for each day:";
                    customerLimit = getInput();
                    cout << endl;
                }
                for (int i = 0; i < cycleLength; ++i) {
                    simulateBusinessDay(store, customerLimit);
                }
                cout << "Simulation Complete! It's recommended that you now view the store data/business day logs" << endl;
                break;
            }
            case 2: {
                int customerLimit = 0;
                while (customerLimit <= 0) {
                    cout << "Please enter the customer limit for today:";
                    customerLimit = getInput();
                    cout << endl;
                }
                simulateBusinessDay(store, customerLimit);
                break;
            }
            case 3: {
                cout << "Business Days:" << endl;
                cout << "------------------------" << endl;
                for (int i = 0; i < store.getBusinessDays().size(); ++i) {
                    cout << "\nDay " << to_string(i + 1) << ": " << endl;
                    cout << store.getBusinessDays()[i] << endl;
                }
                cout << "------------------------" << endl;
            }
            case 4: {
                store.restockIsles();
                break;
            }
        }

    }
}

//Function simulates a single business day within the store
void simulateBusinessDay(Store &store, int customerLimit) {

    //Generate customers
    vector<Customer> customers;
    Customer tempCustomer;
    int randTotalCustomers;
    int randWallet;
    int randIsleId;
    int randItemId;
    int randItemQuantity;
    int randMaxPurchaseAttempts;
    int attemptedPurchases;

    randTotalCustomers = rand() % customerLimit + 1;
    for (int i = 0; i < randTotalCustomers; ++i) {
        randWallet = rand() % 50 + 10.0;
        tempCustomer.setWallet(randWallet);
        tempCustomer.setWalletBackup(randWallet);
        customers.push_back(tempCustomer);
        //cout << customers[i] << endl;
    }

    //Make purchases for each customer
    for (int i = 0; i < customers.size(); ++i) {
        attemptedPurchases = 0;
        randMaxPurchaseAttempts = rand() % 15 + 1;
        while (attemptedPurchases < randMaxPurchaseAttempts) {
            randIsleId = rand() % store.getIsles().size();
            randItemId = rand() % store.getIsles()[randIsleId].getItems().size();
            randItemQuantity = rand() % 3 + 1;
            if (store.getIsles()[randIsleId].getItems()[randItemId].unitPrice * randItemQuantity < customers[i].getWallet()) {
                customers[i].purchaseItem(store.getIsles()[randIsleId].getItems()[randItemId], store, randItemQuantity);
            }
            ++attemptedPurchases;
        }
    }
    store.logBusinessDay();
}

//Gets and sanitizes int input from user
int getInput() {
    int input;

    //Remove junk characters from input, return
    while (!(cin >> input)) {
        cin.clear();
        string junk;
        getline(cin, junk);
    }
    return input;
}