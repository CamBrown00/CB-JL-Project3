
The classes we designed for this project are the Store class (parent), the Grocery class (child), the Isle
class (component), and the Customer class (unrelated). The driving idea behind this project was to create a general
model for a store that could be used to simulate transactions with customers and log the data in an organized fashion.
We decided on creating a grocery store for the child class because it made sense to us to modify the way in which
earnings for the store are calculated (grocery items are taxed less). We didn't feel the need to make the
grocery class stray too far from the parent class, because we wanted the main program to be compatible with any
children of the store class, as well as the store parent class itself. Changing too much of the logic in the Grocery
class would have meant modifying the main program to accommodate it. This decision made sense to us because most
stores are pretty similar at the fundamental level. The additional field for the Grocery class is meant to store
the price difference value for the store, which is used to adjust the earnings for the grocery store in the modified
logBusinessDay function. The component class, or the Isle class, is used to represent the isles in a store by storing
a vector of item structs that can be added to and removed from. The isle class also stores data regarding the total
value of the isle. I implemented the isle class by storing a vector of them as a field in the Store class, which uses
the makeSale method to subtract items from them in the main program. The unrelated class, or the Customer class, is
used in the main program to remove items from the isles of the store in a controlled fashion, and add to the total
earnings of the Store (via modifying currentBusinessDay fields) using the purchaseItem method. In the main program,
a random number of customer objects less than the limit given by the user are created and made to purchase items from
the store within their budget (represented by the wallet field). I also want to mention that there are a number of
methods that are unused within the main program, but I kept them in each of the classes because I think they would
come in handy for convenience sake if we're allowed to reuse this code for a later project.
