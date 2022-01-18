#pragma once
#include "Event.h"
#include "MinuteHand.h"
#include "SecondHand.h"

#include <map>
#include <ostream>
#include <vector>

class Clock
{
    friend std::ostream& operator<<(std::ostream& stream, const Clock&);

public:
    void tick();
    void add_event(const Event& event);

private:
    MinuteHand _minute_hand = {};
    SecondHand _second_hand = { _minute_hand };
    // std::vector<Event> _events {};
    std::map<Time, Event> _events {};
};
