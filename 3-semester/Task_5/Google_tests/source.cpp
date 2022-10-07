#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <list>

std::ostream& operator<<(std::ostream& out, const std::list<int>& list)
{
    for (auto &i : list) {
        out << " " << i;
    }
    return out;
}

void emplaceE(std::list<int>& list, int E, int E1)
{
    auto it = std::find(list.begin(), list.end(), E);
    while (it != list.end())
    {
        it++;
        list.insert(it, E1);
        it = std::find(it, list.end(), E);
    }
}


