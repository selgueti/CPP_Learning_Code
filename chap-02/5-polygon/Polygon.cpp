#include "Polygon.h"

void Polygon::add_vertex(const int x, const int y)
{
    _vertices.emplace_back(x, y);
}

std::ostream& operator<<(std::ostream& stream, const Polygon& polygon)
{
    for (const auto& vertice : polygon._vertices)
    {
        stream << "(" << vertice.first << "," << vertice.second << ") ";
    }
    return stream;
}

const Vertex& Polygon::get_vertex(unsigned int n) const
{
    return _vertices[n];
}