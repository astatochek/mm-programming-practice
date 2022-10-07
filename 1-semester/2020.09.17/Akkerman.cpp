#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
// реализация функции Аккермана
// был еще вариант с unsigned long long int вместо ljng double, но мне кажется, второй берет побольше в рамках этой задачи, хотя и выводит большие числа в неприличной форме
long double Akkerman(long double a, int b, long double result){
    if(b==0) return result;
    else{
        result = pow(a, result);
        return Akkerman(a, b-1, result);
    }
}
int main() {
    int a, b;
    cin >> a >> b;
    cout << Akkerman(a, b, a);
}
