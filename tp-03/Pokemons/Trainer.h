#pragma once

#include "PC.h"

#include <string>
// A person that capture Pokemons and make them fight.
class Trainer
{
public:
    Trainer(const std::string& name, const PC& pc)
        : _name { name }
        , _pc { pc }
    {}

    const std::string name() const { return _name; }

private:
    const std::string _name;
    const PC&         _pc;
};
