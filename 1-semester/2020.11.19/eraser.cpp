#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


using namespace std;


//Дана аудитория и k человек желающих читать в ней в лекции. Каждый человек указывает время лекции со времени a_i до b_i. Организовать расписание, при котором наибольшее количество занятий будет проведено.

//Вводится количество человек, потом время в формате int начала и конца лекции
//Выводится наилучшее расписасание

int Eraser(vector<pair<int, int>> v, int cnt)
{
    if (v.size() == 1) {
        cout << v[0].first << " " << v[0].second << endl;
        return cnt+1;
    }
    if (v[1].first <= v[0].second){
        if (v[1].second <= v[0].second){
            v.erase(v.begin());
            return Eraser(v, cnt);
        }
        else{
            v.erase(v.begin() + 1);
            return Eraser(v, cnt);
        }
    }
    else{
        cout << v[0].first << " " << v[0].second << endl;
        v.erase(v.begin());
        return Eraser(v, cnt + 1);
    }
}

bool cmp(pair<int, int> i, pair<int, int> j)
{
    if (i.first == j.first)
        return i.second > j.second;
    return i.first < j.first;
}


int main()
{
    int k;
    cin >> k;

    vector<pair<int, int>> vec(k);
    for (int i = 0; i < k; i++)
        cin >> vec[i].first >> vec[i].second;
    sort(vec.begin(), vec.end(), cmp);


    int res = Eraser(vec, 0);


    return 0;
}
