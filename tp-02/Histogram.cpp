#include "Histogram.h"

#include <iostream>
#include <stdlib.h>

Histogram::Histogram()
{}

Histogram::Histogram(const Histogram& histogram)
    : _count { histogram._count }
{
    std::cout << "Constructeur par copy" << std::endl;
}

// analyse la string passée en paramètre
void Histogram::analyze(const std::string& s)
{
    for (auto c : s)
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
    for (auto i = 0u; i < _count.size(); i++)
    {
        if (_count[i] > 0)
        {
            std::cout << c << ' ' << _count[i] << std::endl;
        }
        c++;
    }
    std::cout << "------" << std::endl;
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
        std::cin >> s;
    }

    Histogram h4, h2;
    Histogram h3 { Histogram { h4 } };

    return 0;
}