#include "Staff.h"

#include <iostream>
#include <iomanip>

//-----------------------------------------------------------------
//  Constructor: Sets up the list of staff members.
//-----------------------------------------------------------------
Staff::Staff()
    : tony("Tony", "123 Main Line", "555-0469", "123-45-6789", 2423.07),
      paulie("Paulie", "456 Off Line", "555-0101", "987-65-4321", 1246.15),
      vito("Vito", "789 Off Rocker", "555-0000", "010-20-3040", 1169.23),
      michael("Michael", "678 Fifth Ave.", "555-0690", "958-47-3625", 10.55),
      adrianna("Adrianna", "987 Babe Blvd.", "555-8374"),
      benny("Benny", "321 Duds Lane", "555-7282") {

    // Store addresses of the named objects above. A StaffMember* can point
    // at any kind of StaffMember -- this is what makes pay() polymorphic.
    staffList = { &tony, &paulie, &vito, &michael, &adrianna, &benny };

    // The objects are already the right type, so no Java-style cast is needed
    // to call the subclass-specific methods.
    tony.awardBonus(500.00);
    michael.addHours(40);
}

//-----------------------------------------------------------------
//  Pays all staff members.
//-----------------------------------------------------------------
void Staff::payday() {
    double amount;

    for (std::size_t count = 0; count < staffList.size(); count++) {
        // Java printed the object directly (calling toString()). In C++ we
        // call toString() ourselves.
        std::cout << staffList[count]->toString() << std::endl;

        amount = staffList[count]->pay();  // polymorphic

        if (amount == 0.0) {
            std::cout << "Thanks!" << std::endl;
        } else {
            // Java's "Paid: " + amount prints a plain double. We format money
            // with 2 decimals via <iomanip>; this prints e.g. 422.00 where
            // Java would print 422.0.
            std::cout << "Paid: " << std::fixed << std::setprecision(2)
                      << amount << std::endl;
        }

        std::cout << "-----------------------------------" << std::endl;
    }
}
