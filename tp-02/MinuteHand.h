#pragma once

class MinuteHand
{

public:
    int  get_minutes() const;
    void advance();

private:
    int _minutes;
};