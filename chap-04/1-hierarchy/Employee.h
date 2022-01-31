#pragma once
#include "Rank.h"

#include <string>

class Employee
{

public:
    Employee(std::string_view name, std::string_view surname, unsigned int salary, Rank rank)
        : _name { name }
        , _surname { surname }
        , _salary { salary }
        , _rank { rank }
    {}

    const std::string& get_name() const { return _name; }
    const std::string& get_surname() const { return _surname; }
    unsigned int       get_salary() const { return _salary; }
    Rank               get_rank() const { return _rank; }
    void               increase_salary(unsigned int raise) { _salary += raise; }

private:
    const std::string _name;
    const std::string _surname;
    unsigned int      _salary;
    Rank              _rank;
};