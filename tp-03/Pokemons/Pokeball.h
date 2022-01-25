#pragma once

#include "Pokemon.h"

#include <memory>
#include <utility>
// A ball where Pokemon sleep.
class Pokeball
{
public:
    bool     empty() { return _pokemons.empty(); }
    void     store(std::unique_ptr<Pokemon> pokemon) { _pokemons.emplace_back(std::move(pokemon)); }
    Pokemon& pokemon() { return *(_pokemons[0]); }

private:
    std::vector<std::unique_ptr<Pokemon>> _pokemons {};
};