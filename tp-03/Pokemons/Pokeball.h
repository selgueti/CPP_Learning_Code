#pragma once

#include "Pokemon.h"

#include <memory>
#include <utility>
// A ball where Pokemon sleep.
class Pokeball
{
public:
    bool     empty() const { return _pokemon == nullptr; }
    void     store(std::unique_ptr<Pokemon> pokemon) { _pokemon = std::move(pokemon); }
    Pokemon& pokemon() const { return *_pokemon; }
    void     free() { _pokemon.reset(); }

private:
    std::unique_ptr<Pokemon> _pokemon {};
};