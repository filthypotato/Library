#pragma once

#include <string>

namespace Core {

class Person
{
public:
    std::string name{};
    bool isMember{false};

    void libraryCard() const;
    void becomeMember();
};

}
