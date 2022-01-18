#pragma once

#include <string>
#include <vector>

class Histogram
{
public:
    Histogram();
    Histogram(const Histogram& histogram);
    void analyze(const std::string&); // analyse la string passée en paramètre
    void print() const;               // affiche l'histogramme

private:
    std::vector<unsigned int> _count = std::vector<unsigned int>(
        26, 0); // tableau contenant le nombre d'occurrences de chaque lettre entre 'a' et 'z'
};