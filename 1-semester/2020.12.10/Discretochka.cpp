#include <iostream>
#include <vector>

using namespace std;


// Вводятся сначала: кол-во товаров, вместимость рюкзака, потом для каждого товара сначала вес, потом стоимость
// Выводится наилучшая суммарная стоимость товаров, которые можно унести в рюкзаке

int max(int a, int b){
  if (a >= b) return a;
  return b;
}


int main() {
  int W, k;
  cin >> W >> k;
  vector <int> w(k), c(k);
  for (int i = 0; i < k; i++){
    cin >> w[i] >> c[i];
  }

  vector <vector<int>> D;
  vector <int> help(W+1);
  for (int i = 0; i <= k; i++) D.push_back(help);
  for (int i = 0; i <= k; i++) for (int j = 0; j <= W; j++){
    if (j == 0 | i == 0) D[i][j] = 0;
    else D[i][j] = -1; 
  } 



  for (int i = 1; i <= k; i++) for (int j = 0; j <= W; j++){
    if (j >= w[i-1]) D[i][j] = max(D[i-1][j], (D[i-1][j - w[i-1]] + c[i-1]));
    else D[i][j] = D[i-1][j];
  }

  cout << D[k][W];

  return 0;
}


// 10 5
// 2 5
// 1 2
// 4 7
// 3 6
// 2 6
// res: 21
