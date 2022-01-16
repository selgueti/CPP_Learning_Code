#pragma once

#include <ostream>
#include <utility>
#include <vector>

using Vertex = std::pair<int, int>;

class Polygon
{
    friend std::ostream& operator<<(std::ostream& stream, const Polygon& polygon);

public:
    void          add_vertex(const int x, const int y);
    const Vertex& get_vertex(unsigned int n) const;

private:
    std::vector<Vertex> _vertices;
};
