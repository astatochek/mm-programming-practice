#include <iostream>
#include <cmath>

using namespace std;


// Реализация умножения Карацубы

//Работает при результате не больше инта

// Иногда она дает неправильные ответы. Почему - не ясно



int Karatsubo(int a, int b){

  //Выходим из рекурсии
  if (a<100 && b<100) return a*b;

  //Само умножение

  //Запоминаем длинны
  int len_a = 0, a_copy = a, a1 = 0, a0 = 0;
  while (a!=0){
    len_a ++;
    a/=10;
  }
  a = a_copy;
  int len_b = 0, b_copy = b, b1 = 0, b0 = 0;
  while (b!=0){
    len_b ++;
    b/=10;
  }
  b = b_copy;

  // Делаем а наибольшим из двух
  if (len_a < len_b){
    int help = a, help_len = len_a;
    a = b;
    b = help;
    len_a = len_b;
    len_b = help_len;
  }

  a_copy = a;
  b_copy = b;

  //Вводим число n
  int n = len_a/2;

//Определяем a0, a1, b0, b1
  for (int i = 0; i < n; i++) {
      a1 += a % 10 * pow(10, i);

      b1 += b % 10 * pow(10, i);

      a /= 10;
      b /= 10;
  }
  for (int i = 0; i < len_a - n; i++) {
      a0 += a % 10 * pow(10, i);

      b0 += b % 10 * pow(10, i);

      a /= 10;
      b /= 10;
  }
  cout << "a=" << a_copy << ", b=" << b_copy << endl;
  cout << "a0=" << a0 << ", a1=" << a1 << ", b0=" << b0 << ",b1=" << b1 << endl;
  cout << "n=" << n << endl;

  int a0b0 = Karatsubo(a0, b0);
  int a1b1 = Karatsubo(a1, b1);

  return a0b0 * pow(10, ((len_a % 2 == 1) ? 2*n + 1 : 2*n))
 + (Karatsubo(a0+a1, b0+b1) - a0b0 - a1b1) * pow(10, n) + a1b1;


}


int main() {
  int x, y;
  cin >> x >> y;
  cout << Karatsubo(x, y);

  


}
