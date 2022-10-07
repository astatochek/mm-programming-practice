#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;


//Реализовать решение задачи о рюкзаке в непрерывной формулировке

//Вводится количество товаров, вместимость рюкзака, затем для каждого товара вводится его имя, стоимасть всей его массы и масса
//Будем считать, что все товары можно разделить на порции по 1 кг, рюкзак вмещает целое число кг
//Выводится наилучший набор товаров для вора

struct triad{
    string name;
    int cost;
    int weight;
    float udel;
    triad(string s, int x, int y){
        name = s;
        cost = x;
        weight = y;
        udel = x/y;
    }
};

bool cmp(triad i, triad j) {
    return i.udel >= j.udel;
}

int main()
{
    int n, capacity, capacity_copy;
    cin >> n >> capacity;
    capacity_copy = capacity;

    vector<triad> vec;
    for (int i = 0; i < n; i++) {
        int a, b;
        string word;
        cin >> word >> a >> b;
        triad tri = triad(word, a, b);
        vec.push_back(tri);

    }
    sort(vec.begin(), vec.end(), cmp);

    int i = 0, value = 0;
    cout << "В рюкзаке унесем:" << endl;
    while (capacity > 0){
        if (vec[i].weight >= capacity){
            vec[i].weight = capacity;
            value += vec[i].udel * capacity;
            capacity = 0;
        }
        else{
          capacity -= vec[i].weight;
          value += vec[i].cost;
        }
        cout << " " << vec[i].weight << "/" << capacity_copy << " кг: " << vec[i].name << endl;
        i++;
    }
    cout << "Общая стоимость украденных товаров: " << value << endl;


    return 0;
}
