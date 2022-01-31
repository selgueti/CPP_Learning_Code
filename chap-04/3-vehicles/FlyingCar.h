#pragma once

#include "Car.h"

class FlyingCar : Car
{
public:
    FlyingCar(const Driver& driver, unsigned int speed)
        : Car(driver, speed)
    {}

    unsigned int drive() const override
    {
        if (_driver.has_flying_licence())
        {
            std::cout << "Sweeesh!" << std::endl;
            return 10 * _speed;
        }
        else
        {
            return Car::drive();
        }
    }
};