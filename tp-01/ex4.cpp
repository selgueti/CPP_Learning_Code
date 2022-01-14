#include <iostream>
#include <string>
#include <vector>

std::vector<unsigned int> count_lower(const std::string& s)
{
    std::vector<unsigned int> res;
    res.resize(26);
    for (auto c : s)
    {
        if (std::islower(c))
        {
            res[c - 'a'] += 1;
        }
    }
    return res;
}

void display_lower_occ(const std::vector<unsigned int>& occurences)
{
    char c = 'a';
    for (auto i = 0u; i < occurences.size(); i++)
    {
        if (occurences[i] > 0)
        {
            std::cout << c << ' ' << occurences[i] << std::endl;
        }
        c++;
    }
    std::cout << "------" << std::endl;
}

int main(void)
{
    std::string s;
    std::cin >> s;
    while (s != "QUIT")
    {
        display_lower_occ(count_lower(s));
        std::cin >> s;
    }
    return 0;
}