#pragma once

#include "PC.h"
#include "Pokeball.h"

#include <string>
// A person that capture Pokemons and make them fight.
class Trainer
{
public:
    Trainer(const std::string& name, const PC& pc)
        : _name { name }
        , _pc { pc }
    {
        _pokeballs.resize(6);
    }

    const std::string name() const { return _name; }

    const std::vector<Pokeball>& pokeballs() const { return _pokeballs; }

private:
    const std::string     _name;
    const PC&             _pc;
    std::vector<Pokeball> _pokeballs;
};
