#include <iostream>
#include <iomanip>
#include <vector>
#include "Store.h"
#include "Isle.h"
#include "Customer.h"

using namespace std;

int main() {
    //Initialize Items
    item i1("tuna", .50, 2.50, 6);
    item i2("porkchop", .75, 6.50, 10);
    item i3("sausage", .60, 4.41, 20);
    item i4("bananas", .20, 1.50, 30);
    item i5("apples", .15, 1.10, 25);
    item i6("grapes", .42, 1.65, 65);
    item i7("ravioli", .80, 8.40, 8);
    item i8("alfredo", .72, 6.54, 9);
    item i9("spaghetti", .63, 5.36, 21);

    //Initialize each Isle with a name and a vector of items
    Isle is1("Meats", {i1, i2, i3});
    Isle is2("Fruits", {i4, i5, i6});
    Isle is3("Pasta", {i7, i8, i9});

    //Declare vector<Isle> and push Isles onto it
    vector<Isle> isles;
    isles.push_back(is1);
    isles.push_back(is2);
    isles.push_back(is3);

    Store s1(isles);
    s1.makeSale(i1);
    s1.printStore();
    s1.logBusinessDay();
    cout << s1.getTotalEarnings() << endl;
    cout << "Justin, stayed up pretty late this morning working on this so I didn't have time to write\nmany comments,"
            "text me on facebook messenger when you read this with any questions you have and I'll brief you on the\n"
            "child class you'll be making and explain the code I wrote. I still need to finish the main.cpp program"
            "and finish implementing the customer class. The Store class is the parent class and the Store has-a"
            "isle class (vector of isle classes actually). Think of it like a grocery store." << endl;



    return 0;
}