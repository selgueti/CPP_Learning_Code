#include "PC.h"

#include "Trainer.h"

#include <utility>

void PC::give_back(Trainer& trainer, const std::string& pokemon_name)
{
    for (auto i = 0u; i < _pokemons.size(); i++)
    {
        if (_pokemons[i]->name() == pokemon_name && _pokemons[i]->trainer() == &trainer &&
            trainer.has_place_in_pokeballs())
        {
            trainer.capture(std::move(_pokemons[i]));
            _pokemons[i] = std::move(_pokemons[_pokemons.size() - 1]);
            _pokemons.pop_back();
            return;
        }
    }
}