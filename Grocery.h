#include <vector>
#include "Store.h"

#ifndef CB_JL_PROJECT3_GROCERY_H
#define CB_JL_PROJECT3_GROCERY_H
class Grocery: public Store {
private:
    //By default there is no price modification
    double priceDifference = 1;
public:
    //Constructors
    Grocery();
    Grocery(vector<Isle> isles);

    //Non-trivial methods
    void logBusinessDay();

    //Getters and setters
    double getPriceDifference();
    void setPriceDifference(double diff);
};
#endif //CB_JL_PROJECT3_GROCERY_H
