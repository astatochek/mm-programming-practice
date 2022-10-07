#include <iostream>
#include <vector>

using namespace std;

//Вывод k-й порядковой статистики

int main() {
  int k, n;
  cout << "Введите количество элементов в массиве: ";
  cin >> n;
  vector <int> v(n);
  cout << "Вводите элементы массива: ";
  for (int i = 0; i < n; i++) cin >> v[i];
  cout << "Введите номер порядковой статистики: ";
  cin >> k;
  if (k < n/2){
    for (int j = 1; j < k+1; j++){
      int index_max = 0;
      for (int i = 0; i < v.size(); i++)
        if (v[i] > v[index_max]) index_max = i;
      if (j == k) cout << k << "-я порядковая статистика: " << v[index_max];
      else v.erase(v.begin() + index_max);
    }
  }
  else{
    k = n-k;
    for (int j = 0; j < k+1; j++){
      int index_min = 0;
      for (int i = 0; i < v.size(); i++)
        if (v[i] < v[index_min]) index_min = i;
      if (j == k) cout << n-k << "-я порядковая статистика: " << v[index_min];
      else v.erase(v.begin() + index_min);
    }
  }
}
