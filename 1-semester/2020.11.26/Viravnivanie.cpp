#include <iostream>
#include <vector>
#include <string>
using namespace std;


// Задача о выравнии одного слова относительно другого

// Вводятся 2 слова, выводится суммарное количество операций замены, добавления и удаления для преобразования одного слова в другое

// Работает по приципу задачи о Расстоянии Левенштейна с учетом того, что любая операция стоит 1.




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

    int m, n;
  
    string s1, s2;
    cout << "Введите слово, которое надо преобразовать: ";
    cin >> s1;
    cout << "Введите слово, в которое надо преобразовать: ";
    cin >> s2;
    m = s1.length();
    n = s2.length();

    vector<vector<int> > D(m+1, vector<int>(n+1));

    D[0][0] = 0;

    for (int i = 1; i <= m; i++)
    {
        D[i][0] = D[i - 1][0] + 1;
    }
    for (int j = 1; j <= n; j++)
    {
        D[0][j] = D[0][j - 1] + 1;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            D[i][j] = min( D[i-1][j] + 1, D[i][j-1] + 1, D[i-1][j-1] + ((s1[i-1] == s2[j-1]) ? 0 : 1) );
        }
    }


    cout << "Количество операций: " << D[m][n];

    return 0;
}
