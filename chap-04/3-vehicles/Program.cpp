#include "Car.h"
#include "FlyingCar.h"
#include "Scooter.h"
#include "Vehicle.h"

#include <iostream>

int main()
{
    Driver    car_driver;
    Car       car { car_driver, 60u };
    FlyingCar fcar { car_driver, 70u };

    const auto distance_in_car = car.drive();
    std::cout << distance_in_car << " km in a car." << std::endl;

    Driver     mini_gangster;
    Scooter    scooter { mini_gangster, 180u };
    const auto distance_in_scooter = scooter.drive();
    std::cout << distance_in_scooter << " km with a scooter." << std::endl;

    std::cout << "no licence" << std::endl;
    auto distance_in_fcar = fcar.drive();
    std::cout << distance_in_fcar << " km in a car." << std::endl;

    car_driver.pass_car_licence_exam();
    std::cout << "car licence" << std::endl;
    distance_in_fcar = fcar.drive();
    std::cout << distance_in_fcar << " km in a car." << std::endl;

    car_driver.pass_flying_licence_exam();
    std::cout << "flying licence" << std::endl;
    distance_in_fcar = fcar.drive();
    std::cout << distance_in_fcar << " km in a car." << std::endl;

    // Vehicle v { car_driver };
    return 0;
}