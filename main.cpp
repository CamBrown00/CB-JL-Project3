#include <iostream>
#include <iomanip>
#include <vector>
#include "Store.h"
#include "Isle.h"
#include "Customer.h"
#include "Grocery.h"

using namespace std;

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

    g1.makeSale(i1);
    g1.logBusinessDay();

    //Print results
    g1.printStore();

    cout << g1.getBusinessDays()[0] << endl;
    cout << g1.getTotalEarnings() << endl;




    return 0;
}