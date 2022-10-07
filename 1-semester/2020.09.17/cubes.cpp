#include <iostream>
using namespace std;
// вводится количество чисел, затем эти числа
// выводится среднее арифметическое кубов введенных чисел
int main() {
    int n, sum = 0, count = 0, value;
    cin >> n;
    while(n--){
        cin >> value;
        sum += value*value*value;
        count++;
    }
    cout << float(sum)/float(count) << endl;
}
