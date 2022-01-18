#pragma once

#include <iostream>
#include <string>
#include <utility>

// Contains the number of minutes first, and then the number of seconds.
using Time = std::pair<unsigned int, unsigned int>;

class Event
{
public:
    Event(const Time& notif_time, const std::string& message)
        : _notif_time { notif_time }
        , _message { message }
    {}

    Event() {}

    bool notify_time(int current_min, int current_sec)
    {
        if ((current_min - _notif_time.first) == 0 && (current_sec - _notif_time.second) == 0)
        {
            std::cout << _message << std::endl;
            return true;
        }
        return false;
    }

    Time get_notif_time() const { return _notif_time; }

private:
    Time        _notif_time;
    std::string _message;
};
