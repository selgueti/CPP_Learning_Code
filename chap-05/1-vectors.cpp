#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main()
{
    int array[] = { 0, 1, 2, 3, 4, 5 };

    std::vector<int> v(array, array + 6);
    v.clear();
    for (const auto e : v)
    {
        std::cout << e << std::endl;
    }
    return 0;
}