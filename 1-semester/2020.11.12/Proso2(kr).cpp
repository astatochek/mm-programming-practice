#include <iostream>
using namespace std;
//Дана задача: “Выбрать все простые элементы из массива натуральных чисел не превосходящих k: A=[a1,... ,aN]”. 

//Вводится n - число элементов массива, k - мажоранта, затем вводятся элементы массива

//Выводятся все простые элементы массива

int main() {
    int n, k;
    cin >> n >> k;
    int* A = new int [n];
    bool* P = new bool [k];
    for (int i = 2; i < k; i++) P[i] = true;
    for (int i = 2; i < k; i++) if (P[i] == true) for (int j = i+i; j < k; j+=i) P[j] = false;

    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) if (P[A[i]] == true) cout << A[i] << " ";

    delete [] P;
    delete [] A;

    return 0;
}
