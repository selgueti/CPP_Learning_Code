#include "SecondHand.h"

SecondHand::SecondHand(MinuteHand& mh)
    : _seconds { 0 }
    , _min_hand { mh }
{}

int SecondHand::get_seconds() const
{
    return _seconds;
}

void SecondHand::advance()
{
    if (_seconds == 59)
    {
        _seconds = 0;
        _min_hand.advance();
    }
    else
    {
        _seconds++;
    }
}