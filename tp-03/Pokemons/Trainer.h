#pragma once

#include "PC.h"
#include "Pokeball.h"
#include "Pokemon.h"

#include <string>
#include <vector>
// A person that capture Pokemons and make them fight.
class Trainer
{
public:
    Trainer(const std::string& name, PC& pc)
        : _name { name }
        , _pc { pc }
    {
        _pokeballs.resize(_nb_pokeballs);
    }

    const std::string name() const { return _name; }

    const std::vector<Pokeball>& pokeballs() const { return _pokeballs; }

    void capture(std::unique_ptr<Pokemon> pokemon)
    {
        (*pokemon).set_trainer(this);
        for (auto i = 0u; i < _nb_pokeballs; i++)
        {
            if (_pokeballs[i].empty())
            {
                _pokeballs[i].store(std::move(pokemon));
                return;
            }
        }
        _pc.receive(std::move(pokemon));
    }

    void store_in_pc(int index)
    {
        if ((index >= 0) && ((_nb_pokeballs - index) > 0) && (!_pokeballs[index].empty()))
        {
            _pc.receive(std::make_unique<Pokemon>(_pokeballs[index].pokemon()));
            _pokeballs[index].free();
        }
    }

private:
    const std::string     _name;
    PC&                   _pc;
    std::vector<Pokeball> _pokeballs;
    const unsigned int    _nb_pokeballs = 6;
};
