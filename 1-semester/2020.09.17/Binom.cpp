
#include <iostream>
using namespace std;
//Программа рассчета биномиальго коэффициента C из n по k
//вводить нужно такие положительные целые k и n, что 0 <= k <= n
int main() {
    int n, k;
    long double result = 1.0;
    cin >> n >> k;
    result *= n;
    for (int i = 1; i < k; i++){
        result *=  n-i;
        result /= i;
    }
    result /= k;
    cout << result << endl;
