#pragma once

#include "MinuteHand.h"

class SecondHand
{
public:
    SecondHand(MinuteHand&);
    int  get_seconds() const;
    void advance();

private:
    int         _seconds;
    MinuteHand& _min_hand;
};
