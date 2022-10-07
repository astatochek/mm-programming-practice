#include <iostream>
using namespace std;
// Вывод всех составных чисел от 1 до n
int main() {
    int n;
    cin >> n;
    bool* A = new bool [n];
    for (int i = 0; i < n; i++) A[i] = false;
    for (int i = 2; i < n; i++){
        if (A[i] == false) for (int j = i; j < n; j+=i) A[j] = true;
        else cout << i << " ";
    };
    delete [] A;
    return 0;
}
