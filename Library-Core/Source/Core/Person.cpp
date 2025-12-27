#include "Person.hpp"

#include <iostream>

namespace Core {

void Person::libraryCard() const
{
    std::cout << "Library card: " << (isMember ? "Active\n" : "Not active\n");
}

void Person::becomeMember()
{
    std::cout << "Become a member? (1 = yes, 0 = no): ";
    int choice{};
    std::cin >> choice;
    if (choice == 1)
    {
        isMember = true;
        std::cout << "You're now a member!\n";
    }
}

}
