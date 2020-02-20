#include <iostream>
#include <vector>

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
    vector<vector<string>> isles;

public:


};

#endif //CB_JL_PROJECT3_STORE_H
