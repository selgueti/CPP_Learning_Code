#pragma once

#include <memory>
#include <string>

class Trainer;

// A creature that is cute and can fight other ones.
class Pokemon
{
public:
    Pokemon(const std::string& name)
        : _name { name }
    {}
    const std::string& name() const { return _name; }
    const Trainer*     trainer() const { return _trainer; }
    void               set_trainer(Trainer* trainer) { _trainer = trainer; }

private:
    const std::string _name;
    Trainer*          _trainer = nullptr;
};
