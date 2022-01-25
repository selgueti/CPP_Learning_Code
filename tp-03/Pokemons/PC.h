#pragma once

#include "Pokemon.h"

#include <memory>
#include <vector>
// A PC is the place where Pokemons get automagically sent when the trainer's pockets are full.
// When a Pokemon is transferred to the PC, this one takes ownership.
class PC
{
public:
    std::vector<std::unique_ptr<Pokemon>>& pokemons() { return _pokemons; }

    void receive(std::unique_ptr<Pokemon> ptr) { _pokemons.emplace_back(std::move(ptr)); }

private:
    std::vector<std::unique_ptr<Pokemon>> _pokemons;
};
