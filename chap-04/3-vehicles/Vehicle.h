#pragma once

#include <iostream>

class Driver
{
public:
    void pass_car_licence_exam() { _has_car_licence = true; }
    bool has_car_licence() const { return _has_car_licence; }

    void pass_flying_licence_exam() { _has_flying_licence = true; }
    bool has_flying_licence() const { return _has_flying_licence; }

private:
    bool _has_car_licence    = false;
    bool _has_flying_licence = false;
};

class Vehicle
{
public:
    virtual ~Vehicle() {}
    Vehicle(const Driver& driver)
        : _driver { driver }
    {}

    virtual unsigned int drive() const = 0;

protected:
    const Driver& _driver;
};
