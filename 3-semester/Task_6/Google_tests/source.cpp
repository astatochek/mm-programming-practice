#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <sstream>
#include <map>
#include "string.h"

bool cmp(std::pair <float, std::pair<int,int> > a, std::pair <float, std::pair<int,int> > b)
{
    return a.first < b.first || a.first == b.first && a.second.first > b.second.first;
}


std::pair <int, int> Sklad(std::vector< std::pair <float, std::pair<int,int> > > v, int k)
{
    sort(v.begin(), v.end(), cmp);
    int res1 = 0;
    int res2 = v[0].second.second;
    int ves = v[0].second.first;
    for (int i = 0; i < k; i++)
    {
        res1 += v[i].second.first;
        if (v[i].second.first > ves)
        {
            ves = v[i].second.first;
            res2 = v[i].second.second;
        }

    }

    return std::make_pair(res1, res2);
}



std::string Who(std::string path)
{
    std::ifstream in(path);
    std::stringstream myString;
    std::string line;
    if (in.is_open())
        while (getline(in, line))
        { myString << line << "\n"; }

    int n;
    std::string word1, word2;
    std::map <std::string, std::string> dict;
    myString >> n;
    while(n--)
    {
        myString >> word1 >> word2;
        dict[word1] = word2;
        dict[word2] = word1;
    }

    std::string word;
    myString >> word;

    return dict[word];
}