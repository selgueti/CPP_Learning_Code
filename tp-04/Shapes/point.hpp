#pragma once
#include <algorithm>
#include <cmath>
#include <ostream>

class Point
{
public:
    float x, y;

    bool  operator<(const Point& p) const { return (x == p.x) ? (y < p.y) : (x < p.x); }
    bool  operator==(const Point& p) const { return (x == p.x) && (y == p.y); }
    bool  operator!=(const Point& p) const { return !operator==(p); }
    Point operator-() const { return { -x, -y }; }
    Point operator+(const Point& p) const { return { x + p.x, y + p.y }; }
    Point operator-(const Point& p) const { return { x - p.x, y - p.y }; }
    Point operator*(const float scale) const { return { x * scale, y * scale }; }
    float dist_to_0() const { return std::sqrt(x * x + y * y); }
    float dist(const Point& p) const { return (*this - p).dist_to_0(); }
    Point normalized(const float target_length = 1.0f) const { return *this * (target_length / dist_to_0()); }
    Point rotate_90deg() const { return { -y, x }; }

    Point& operator+=(const Point& p) { return *this = *this + p; }
    Point& operator-=(const Point& p) { return *this += -p; }
    Point& operator*=(const float scale) { return *this = *this * scale; }
    void   normalize(const float target_length = 1.0f) { *this = normalized(target_length); }

    bool is_between(const Point& first, const Point& last) const
    {

        return (x >= std::min(first.x, last.x)) && (y >= std::min(first.y, last.y)) &&
               (x <= std::max(first.x, last.x)) && (y <= std::max(first.y, last.y));
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& p)
    {
        return os << '(' << p.x << ',' << p.y << ')';
    }
};