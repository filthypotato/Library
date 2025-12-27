#include "Core/Library.hpp"
#include "Core/Person.hpp"

int main()
{
    Core::Library library;
    Core::Person person;

    library.mainMenu(person);

    return 0;
}