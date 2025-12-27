#pragma once

#include "Person.hpp"

#include <vector>
#include <string>

namespace Core {

// Library Management system
class Library
{
public:
    std::vector<std::string> books{}; // Vector for checked out books

    void mainMenu(Person &person);
    void currentCheckout() const;
    void checkoutSystem(Person &person);
};

}
