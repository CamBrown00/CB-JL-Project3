/*
 * This is the parent class for the project.
 * This class is meant to model a grocery store for the purpose of simulating business days and transactions.
 * There are functions in this class for making sales, adding isles to the store, logging business days, etc.
 * This class also contains a struct for business days that keeps track of earnings and the customer count.
 */

#include <iostream>
#include <vector>
#include "Isle.h"

using namespace std;

#ifndef CB_JL_PROJECT3_STORE_H
#define CB_JL_PROJECT3_STORE_H


struct businessDay{
    double earnings;
    int customerCount;

    //Constructors
    businessDay();
    businessDay(double earnings, int customerCount);

    //Overloaded Operators
    friend ostream& operator << (ostream& outs, const businessDay &bd);
    friend bool operator > (businessDay &lhs, businessDay &rhs);
    friend bool operator < (businessDay &lhs, businessDay &rhs);
    friend bool operator == (businessDay &lhs, businessDay &rhs);
};

class Store{
protected:
    vector<Isle> isles;
    vector<Isle> islesBackup;
    vector<businessDay> businessDays;
    businessDay currentBusinessDay;
    double totalEarnings;
    int customerCount;

public:

    //Constructors
    Store();
    Store(vector<Isle> isles);

    //Non-trivial methods
    void addIsle(Isle is);
    virtual void logBusinessDay();
    void makeSale(item it);
    void makeSales(vector<item> items);
    void printStore();
    void restockIsles();

    //Getters and setters
    vector<Isle> getIsles();
    vector<businessDay> getBusinessDays();
    businessDay getCurrentBusinessDay();
    double getTotalEarnings();
    int getCustomerCount();

};

#endif //CB_JL_PROJECT3_STORE_H
