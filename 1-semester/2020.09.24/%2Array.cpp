#include <iostream>
using namespace std;

// Вводится длина массива, затем его элементы
// Создается новый массив, состоящий только из четных элементов первого, затем он заменяет первый
// Элементы нового массива выводятся


int main() {
    int n, s = 0;
    cin >> n;
    int * A = new int [n];

    int* p = A;
    int* q = A+n;
    for( ; p!=q; p++){
        cin >> *p;
        if (*p % 2 != 0) s+=1;
    };
    p = A;
    int * temp = new int [s];
    int* i = temp;
    for ( ; p!=q; p++){
        if (*p % 2 != 0){
            *i = *p;
            i++;
        };
    };
    delete []A;
    A = temp;
    p = A;
    q = A+s;
    for ( ; p!=q; p++){
        cout << *p << " ";
    };

    delete []temp;


    return 0;
}
