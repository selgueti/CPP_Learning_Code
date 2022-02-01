#pragma once

#include <iostream>
#include <string>
#include <string_view>

class Person
{
public:
    Person(std::string_view name, int position)
        : _name { name }
        , _position { position }
    {}

    void answer_phone() const { std::cout << "Hi! " << _name << " on the phone!" << std::endl; }

    int get_position() const { return _position; }

    void set_position(int position) { _position = position; }

    const std::string& get_name() const { return _name; }

private:
    const std::string _name;
    int               _position = 0;
};
