#pragma once

#include <string>

class Histogram
{
public:
    Histogram();                 // constructeur
    Histogram(const Histogram&); // constructeur de copie

    ~Histogram(); // destructeur

    Histogram& operator=(const Histogram&); // opérateur d'assignation par copie

    void analyze(const std::string&); // analyse la string passée en paramètre
    void print() const;               // affiche l'histogramme
    void reset();                     // remet le tableau à 0

private:
    unsigned*    _count;     // tableau contenant le nombre d'occurrences de chaque lettre entre 'a' et 'z'
    const size_t _size = 26; // taille du tableau
};