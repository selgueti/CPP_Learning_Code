#include "circle.hpp"
#include "line.hpp"
#include "line_seg.hpp"
#include "rectangle.hpp"
#include "shape.hpp"

#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const PointContainer& points)
{
    os << '[';
    for (const auto& p : points)
        os << p << ' ';
    return os << ']';
}

void intersect_all(const std::vector<Shape*>& shapes)
{
    for (auto iter = shapes.begin(); iter != shapes.end(); ++iter)
    {
        for (auto iter2 = std::next(iter); iter2 != shapes.end(); ++iter2)
        {
            std::cout << **iter << " intersects " << **iter2 << " in:\t" << (*iter)->intersect(**iter2)
                      << std::endl;
        }
    }
}

int main(int, char**)
{
    std::vector<Shape*> some_shapes;
    // test 1
    some_shapes.emplace_back(new Line { { 0, 4 }, { 8, 0 } });
    some_shapes.emplace_back(new LineSegment { { 0, 0 }, { 10, 10 } });

    // test 2
    some_shapes.emplace_back(new LineSegment { { 0, 2 }, { 10, 2 } });

    // test 3
    // some_shapes.emplace_back(new Rectangle { { 10, -1 }, { -10, 1 } });

    some_shapes.emplace_back(new Rectangle { { -10, 1 }, { 10, -1 } });

    some_shapes.emplace_back(new Rectangle { { -9, 3 }, { 0, -3 } });

    // test 4
    some_shapes.emplace_back(new Circle { { 0, 0 }, 5 });

    some_shapes.emplace_back(new Circle { { 0, 10 }, 5 });

    intersect_all(some_shapes);
    for (auto& p : some_shapes)
        delete p;
}
