#include <iostream>
#include <vector>
#include <string>
using namespace std;


// Задача о выравнии одного слова относительно другого

// Вводятся 2 слова, цена добавления, удаления и замены буквы, выводится суммарная стоимость операций для преобразования одного слова в другое




int min(int x, int y, int z)
{
    if (x <= y && x <= z)
        return x;
    else if (y <= x && y <= z)
        return y;
    return z;
}


int main()
{

    int m, n, a, b, c;
  
    string s1, s2;
    cout << "Введите слово, которое надо преобразовать: ";
    cin >> s1;
    cout << "Введите слово, которое надо получить: ";
    cin >> s2;
    cout << "Введите цену добавления буквы: ";
    cin >> a;
    cout << "Введите цену удаления буквы: ";
    cin >> b;
    cout << "Введите цену замены буквы: ";
    cin >> c;
    m = s1.length();
    n = s2.length();

    vector <int> help = {};
    vector <vector<int>> D;
    for (int i = 0; i <= m; i++){
        help = {};
        for (int j=0; j <= n; j++){
            help.push_back(0);
        }
        D.push_back(help);
    }

    D[0][0] = 0;

    for (int i = 1; i <= m; i++)
    {
        D[i][0] = D[i - 1][0] + b;
    }
    for (int j = 1; j <= n; j++)
    {
        D[0][j] = D[0][j - 1] + a;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            D[i][j] = min( D[i-1][j] + b, D[i][j-1] + a, D[i-1][j-1] + ((s1[i-1] == s2[j-1]) ? 0 : c) );
        }
    }


    cout << "Цена преобразования: " << D[m][n] << "\n";


    return 0;
}
