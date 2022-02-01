#pragma once
#include "Person.h"
#include "Phone.h"

class MobilePhone : public Phone
{
public:
    MobilePhone(const Person& owner)
        : Phone { owner }
    {}

    void ring() const override { _owner.answer_phone(); };
};