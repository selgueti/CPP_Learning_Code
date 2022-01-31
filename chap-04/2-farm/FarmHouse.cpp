#include "Animal.h"
#include "Cat.h"
#include "Chicken.h"
#include "Cow.h"
#include "Dog.h"
#include "Opera.h"

#include <vector>

void sing_a_lot(const Animal& animal, unsigned int times)
{
    if (times > 0)
    {
        while (--times > 0)
        {
            animal.sing(' ');
        }

        animal.sing('\n');
    }
}

void sing_chronus(const std::vector<Animal*>& animals)
{
    for (const auto* animal : animals)
    {
        animal->sing(' ');
    }
    std::cout << std ::endl;
}

int main()
{
    Cat     cat;
    Chicken chicken;
    Dog     dog;
    Cow     cow;

    std::vector<Animal*> animals {};

    animals.emplace_back(&cat);
    animals.emplace_back(&chicken);
    animals.emplace_back(&dog);
    animals.emplace_back(&cow);

    sing_a_lot(cat, 2u);
    sing_a_lot(dog, 1u);
    sing_a_lot(cow, 3u);
    sing_a_lot(dog, 1u);
    sing_a_lot(chicken, 2u);

    sing_chronus(animals);

    Opera opera;

    opera.sing();
    return 0;
}
