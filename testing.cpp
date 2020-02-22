#include <vector>
#include <iostream>
#include <iomanip>
#include "Customer.h"
#include "isle.h"
#include "Store.h"
#include "Grocery.h"

using namespace std;

bool test_helper(string message, Store testStore, item testItem, int testItemQuantity, Customer testCustomer, double expectedTotalEarnings);
bool store_tester();

int main()
{
    if (store_tester()) cout << "Passed all test cases!" << endl;
    return 0;
}

//Calls test_helper to make test cases and keeps track of the failed test cases
bool store_tester(){

    //Create Store and populate with starter items for testing
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
    item i13("bowls", 1.0, 19.0, 100);

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

    //Declare Store objs and begin making sales/logging business days
    Grocery g1(isles);
    Store s1(isles);

    //Declare Customer objects
    Customer c1(100.0);

    /***** Store Test Cases *****/
    int fails = 0;

    cout << "\nRunning Test Cases...\n" << endl;
    fails += 1 * !(test_helper("Basic test case.", s1, i1, 5, c1, 10.0));
    fails += 1 * !(test_helper("Attempt to purchase 0 quantity item.", s1, i1, 0, c1, 0.0));
    fails += 1 * !(test_helper("Attempt to purchase a item not in the store.", s1, i13, 0, c1, 0.0));

    /***** Grocery Store Test Cases *****/
    fails += 1 * !(test_helper("Basic test case.", g1, i1, 5, c1, 10.0));
    fails += 1 * !(test_helper("Attempt to purchase 0 quantity item.", g1, i1, 0, c1, 0.0));
    fails += 1 * !(test_helper("Attempt to purchase a item not in the store.", g1, i13, 0, c1, 0.0));

    cout << "# of failed test cases: " << fails << endl;
    return (fails == 0);
}

//Function to run a test case by purchasing an item from the store with given customer and item parameters
bool test_helper(string message, Store testStore, item testItem, int testItemQuantity, Customer testCustomer, double expectedTotalEarnings){
    testCustomer.purchaseItem(testItem, testStore, testItemQuantity);
    testStore.logBusinessDay();
    if (testStore.getTotalEarnings() != expectedTotalEarnings){
        cout << "\nFailed test case: " << message << endl;
        cout << "Expected Earnings: $" << expectedTotalEarnings << "\t Actual Earnings: $" << testStore.getTotalEarnings() << "\n" << endl;
        return false;
    }
    return true;
}





