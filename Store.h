#include <iostream>
#include <vector>
#include "Isle.h"

using namespace std;

#ifndef CB_JL_PROJECT3_STORE_H
#define CB_JL_PROJECT3_STORE_H

/*
 *
 */

struct businessDay{
    double earnings;
    int customerCount;
    string topItem;
    int date;

    //Constructors
    businessDay();
    businessDay(double earnings, int customerCount, string topItem, int date);

    //Overloaded Operators
    friend ostream& operator << (ostream& outs, const businessDay &bD);
    friend bool operator > (businessDay &lhs, businessDay &rhs);
    friend bool operator < (businessDay &lhs, businessDay &rhs);
    friend bool operator == (businessDay &lhs, businessDay &rhs);
};

class Store{
private:
    vector<vector<Isle>> isles;
    vector<businessDay> businessDays;
    int totalCost;
    int totalEarnings;
    int customerCount;

public:

    //Constructors
    Store();
    Store(vector<vector<Isle>>);

    //Non-trivial methods
    void logDay();
    void clearCurrentDay();
    void makeSale();
    void printStore();


};

#endif //CB_JL_PROJECT3_STORE_H
