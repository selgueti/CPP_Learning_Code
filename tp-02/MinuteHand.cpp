#include "MinuteHand.h"

#include "Clock.h"

#include <iostream>

int MinuteHand::get_minutes() const
{
    return _minutes;
}

void MinuteHand::advance()
{
    if (_minutes == 59)
    {
        _minutes = 0;
    }
    else
    {
        _minutes++;
    }
}

/*
int main()
{
    Clock clock {};

    for (auto i = 0u; i < 64; i++)
    {
        std::cout << clock << std::endl;
        clock.tick();
    }
    return 0;
}
*/