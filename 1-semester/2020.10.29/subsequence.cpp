#include <iostream>
#include <vector>

using namespace std;


// Вводится количесвто элементов в массиве
// Вводятся элементы массива

// Выводится длина наибольшей неубывающей подпоследовательности подряд идущих элементов



int main() {

  int n;
  cin >> n;

  vector <int> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];

  int elon_max = 1, elon_cur = 1;

  for (int i = 1; i < n; i++){
    if (vec[i] >= vec[i-1]) elon_cur++;
    else{
      if (elon_cur > elon_max) elon_max = elon_cur;
      elon_cur = 1;
    }
  }
  if (elon_cur > elon_max) elon_max = elon_cur;
  cout << elon_max;
}
