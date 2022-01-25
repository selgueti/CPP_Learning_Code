#pragma once

#include "PC.h"
#include "Pokeball.h"
#include "Pokemon.h"

#include <iostream>
#include <string>
// A person that capture Pokemons and make them fight.
class Trainer
{
public:
    Trainer(const std::string& name, PC& pc)
        : _name { name }
        , _pc { pc }
    {
        _pokeballs.resize(_nb_pokebbals);
    }

    const std::string name() const { return _name; }

    const std::vector<Pokeball>& pokeballs() const { return _pokeballs; }

    void capture(std::unique_ptr<Pokemon> pokemon)
    {
        for (auto i = 0u; i < _nb_pokebbals; i++)
        {
            if (_pokeballs[i].empty())
            {
                _pokeballs[i].store(std::move(pokemon));
                return;
            }
        }
        _pc.receive(std::move(pokemon));
    }

private:
    const std::string     _name;
    PC&                   _pc;
    std::vector<Pokeball> _pokeballs;
    const unsigned int    _nb_pokebbals = 6;
};
