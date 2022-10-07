#include <vector>
#include <map>
#include <algorithm>
#include <iostream>


std::ostream& operator<<(std::ostream& ostr, const std::vector<double>& list)
{
    for (auto &i : list) {
        ostr << " " << i;
    }
    return ostr;
}






std::vector <std::pair <int, int> > sortDivideWin(std::vector <double> base)
{
    std::map <int, int> index;
    std::vector <std::pair <int, int> > res;
    for (int i = 0; i < base.size(); i++)
        index[base[i]] = i;

    //std::cout << base << "\n";

    sort(base.begin(), base.end());

    //std::cout << base << "\n";

    int n = base.size()-1;

    while (base.size() != 1)
    {
        auto it = base.begin();
        while (it != base.end() - 1 && it != base.end())
        {
            res.push_back(std::make_pair(std::min(index[*(it+1)] + 1, index[*it] + 1), std::max(index[*(it+1)] + 1, index[*it] + 1)));
            *it = (*it + *(it+1)) / 2;
            n++;
            index[*it] = n;
            base.erase(it+1);
            //std::cout << base << "\n";
        }
    }

    return res;

}

