#include <iostream>
using namespace std;

 // сортировка вставками с использованием указательной арифметики
 
void swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
};

int main() {
    int n, s = 0;
    cin >> n;
    int * A = new int [n];
    int* p = A;
    int* q = A+n;
    for( ; p!=q; p++)
        cin >> *p;
    p = A;
    int i = 0;
    for( ; p!=q; p++) {
      i++;
      int j = i;
      for (; j != 0 && *(A + j-1) > *(A+j); j--)
        swap(*(A+j-1), *(A+j));
    };
    
    p = A;
    for ( ; p!=q; p++){
        cout << *p << " ";
    };
    
    return 0;
}
