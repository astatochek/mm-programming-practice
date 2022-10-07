#include <iostream>
using namespace std;
// Вывод первых k простых чисел
// Работает за O( k ln ln (2k + ln k) )
int main() {
    int n, k, s = 0, total = 0;
    cin >> k;
    n = k * (2 + log(k));
    bool* A = new bool [n];
    for (int i = 0; i < n; i++) A[i] = false;
    for (int i = 2; i < n; i++){
        if (A[i] == false) for (int j = i+i; j < n; j+=i) A[j] = true;
    };
    for (int i = 2; i < n; i++){
        if (A[i] == false && s < k){
            cout << i << " ";
            s++;
        };
        if (A[i] == false) total++;
    };
    cout << endl << "A total of " << s << " numbers";
    delete [] A;
    return 0;
}
