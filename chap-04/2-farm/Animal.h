#pragma once

#include <iostream>

class Animal
{
public:
    virtual void sing(char separator) const { std::cout << "..." << separator; }
    virtual ~Animal() {}
};
