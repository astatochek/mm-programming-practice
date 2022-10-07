#include <vector>
#include <map>
#include <algorithm>






bool cmp(std::pair <int, int> a, std::pair<int, int> b) { return a.second < b.second; }

std::vector <int> delRepeating(std::vector <int> array) {
    std::map<int, int> dict;

    for (int i = 0; i < array.size(); i++)
    {
        if (dict.find(array[i]) == dict.end())
            dict[array[i]] = i;
    }

    std::vector <std::pair<int, int>> vec;
    for (auto &elem : dict)
    {
        vec.push_back(elem);
    }

    sort(vec.begin(), vec.end(), cmp);

    std::vector <int> res(vec.size());
    for (int i = 0; i < vec.size(); i++)
        res[i] = vec[i].first;


    return res;
}








int binarySearch(std::vector<int> array, int x, int left, int right)
{
    if (right == -1)
        right = array.size();

    int mid = (left + right) / 2;

    if (right <= left)
        return -1;

    if (array[mid] == x)
        return mid;

    if (array[mid] < x)
        return binarySearch(array, x, mid + 1, right);

    if (array[mid] > x)
        return binarySearch(array, x, left, mid - 1);

}








std::vector <int> Merge(std::vector <int> a, std::vector <int> b)
{
    int i = 0, j = 0;
    std::vector <int> res;
    while (i != a.size() && j != b.size())
    {
        if (a[i] < b[j]) { res.push_back(a[i]); i++; }

        else { res.push_back(b[j]); j++; }
    }


    if (i == a.size() && j < b.size())
    {
        for (int g = j; g < b.size(); g++)
            res.push_back(b[g]);
    }


    if (j == b.size() && i < a.size())
    {
        for (int g = i; g < a.size(); g++)
            res.push_back(a[g]);
    }

    return res;
}