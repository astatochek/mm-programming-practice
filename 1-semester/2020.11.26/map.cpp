#include <iostream>
#include <vector>

using namespace std;


//Дана прямоугольная клетчатая карта, в ячейках которой указаны стоимости прохода по клетке. Из клетки ходить вниз, вправо и по диагонали вниз-вправо. Напишите программу, находящую самый дешевый путь из верхней левой в правую нижнюю клетку.

// Вводится n, m, массив n х m

//Выводится мимнмальная стоимость

int minimal(int a, int b, int c){
    if (a <= b and a <= c) return a;
    if (b <= a and b <= c) return b;
    return c;
}

int main() {
    int n, m, a;
    cin >> n >> m;
    vector <int> help = {};
    vector <vector<int>> v;
    for (int i = 0; i < n; i++){
        help = {};
        for (int j=0; j < m; j++){
            cin >> a;
            help.push_back(a);
        }
        v.push_back(help);
    }
    vector<vector<int>> MAP(n);
    vector<int> help_2(m);
    for (int i = 0; i < n; i++) MAP[i] = help_2;
    MAP[0][0] = 0;
    for (int j = 1; j < m; j++) MAP[0][j] = MAP[0][j-1] + v[0][j];
    for (int j = 1; j < n; j++) MAP[j][0] = MAP[j-1][0] + v[j][0];

    for (int i = 1; i < n; i++){
      for (int j = 1; j < m; j++){
        MAP[i][j] = minimal(MAP[i-1][j], MAP[i-1][j-1], MAP[i][j-1]) + v[i][j];
      }
    }


    cout << MAP[n-1][m-1];
    return 0;
}
