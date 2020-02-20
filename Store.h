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
private:
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
    void logBusinessDay();
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
