#include <iostream>
using namespace std;

// Бинарное возведение в степень через рекурсивную функцию

int bin_pow(int x, int n){
    if (n==0) return 1;
    if (n%2 == 1) return x*bin_pow(x, n-1);
    if (n%2 == 0) return bin_pow(x*x, n/2);
};
int main() {
    int x, power;
    cin >> x >> power;
    cout << bin_pow(x, power);
    return 0;
}
