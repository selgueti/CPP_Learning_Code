#include "Histogram.h"

#include <iostream>
#include <stdlib.h>

// constructeur
Histogram::Histogram()
{
    std::cout << "Constructeur par défaut" << std::endl;
    _count = (unsigned int*)malloc(_size * sizeof(unsigned int));
    reset();
}

// constructeur de copie
Histogram::Histogram(const Histogram& other)
    : Histogram()
{
    std::cout << "Constructeur par copie" << std::endl;
    for (size_t i = 0; i < _size; i++)
    {
        _count[i] = other._count[i];
    }
}

// destructeur
Histogram::~Histogram()
{
    std::cout << "Déstructeur" << std::endl;
    free(_count);
}

// opérateur d'assignation par copie
Histogram& Histogram::operator=(const Histogram& other)
{
    std::cout << "opérateur d'assignation par copie" << std::endl;
    if (this != &other)
    {
        _count = other._count;
    }
    return *this;
}

// analyse la string passée en paramètre
void Histogram::analyze(const std::string& s)
{
    for (const auto c : s)
    {
        if (std::islower(c))
        {
            _count[c - 'a'] += 1;
        }
    }
}

// affiche l'histogramme
void Histogram::print() const
{
    char c = 'a';
    for (auto i = 0u; i < _size; i++)
    {
        if (_count[i] > 0)
        {
            std::cout << c << ' ' << _count[i] << std::endl;
        }
        c++;
    }
    std::cout << "------" << std::endl;
}

// remet le tableau à 0
void Histogram::reset()
{
    for (size_t i = 0; i < _size; i++)
    {
        _count[i] = 0;
    }
}

int main(void)
{
    std::string s;
    std::cin >> s;
    Histogram h1;

    while (s != "QUIT")
    {
        h1.analyze(s);
        h1.print();
        h1.reset();
        std::cin >> s;
    }

    Histogram h4, h2;
    Histogram h3 { Histogram { h4 } };

    return 0;
}