#include "Clock.h"

/*
void Clock::tick()
{
    _second_hand.advance();

    for (auto i = 0u; i < _events.size(); i++)
    {
        if (_events[i].notify_time(_minute_hand.get_minutes(), _second_hand.get_seconds()))
        {
            if (i != _events.size() - 1)
            {
                auto tmp                    = _events[_events.size() - 1];
                _events[_events.size() - 1] = _events[i];
                _events[i]                  = tmp;
                i--;
            }
            _events.pop_back();
        }
    }
}
*/

void Clock::tick()
{
    _second_hand.advance();

    auto min  = _minute_hand.get_minutes();
    auto sec  = _second_hand.get_seconds();
    auto time = Time { min, sec };
    if (_events.count(time) > 0)
    {
        _events[time].notify_time(min, sec);
        _events.erase(time);
    }
}

std::ostream& operator<<(std::ostream& stream, const Clock& clock)
{
    return stream << clock._minute_hand.get_minutes() << " min " << clock._second_hand.get_seconds()
                  << " sec";
}

/*
void Clock::add_event(const Event& event)
{
    _events.emplace_back(event);
}
*/

void Clock::add_event(const Event& event)
{
    _events.emplace(event.get_notif_time(), event);
}