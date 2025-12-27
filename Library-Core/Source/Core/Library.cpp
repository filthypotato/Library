#include "Library.hpp"

#include <iostream>

namespace Core {

void Library::mainMenu(Person &person)
{
    std::cout << "[1] Checkout books\n";
    std::cout << "[2] Become member\n";
    std::cout << "[3] Exit\n";

    int choice{};
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        checkoutSystem(person);
        currentCheckout();
        break;
    case 2:
        person.becomeMember();
        mainMenu(person);
        break;
    case 3:
        // Auto exits
        break;
    }
}

void Library::currentCheckout() const
{
    if (books.empty())
    {
        std::cout << "You have no books checked out to you. Get on it!\n";
    }
    else
    {
        std::cout << "You currently have these books checked out:\n";
        for (const auto& b : books)
            std::cout << " - " << b << "\n";
    }
}

void Library::checkoutSystem(Person& person)
{
    if (!person.isMember)
    {
        std::cout << "You do not have a library card. Please become a member first.\n";
        return;
    }

    std::cout << "How many books did you want to checkout? ";
    int bookAmount{};
    std::cin >> bookAmount;

    for (int i = 0; i < bookAmount; ++i)
    {
        std::cout << "Enter title for book #" << (i + 1) << ": ";
        std::string title{};
        std::getline(std::cin >> std::ws, title);
        books.push_back(title);
    }
    std::cout << "Checkout complete, please see us again!\n";
}

}
