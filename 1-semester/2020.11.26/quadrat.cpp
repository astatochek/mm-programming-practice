#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;


// Вводится число натуральное

// Выводится его разложения на натуральные числа, являющиеся полными квадратами, с наименьшим числом слагаемых
struct quw{
    double len;
    vector <double> v;

    quw(){
        len = 4;
        v = {};
    }
};
int main() {
    double n;
    cin >> n;
    vector <quw> vec(n+1);
    for (double i = 0; i <= n; i++){
        vec[i] = quw();
        if (i == 1){
            vec[i].len = 1;
            vec[i].v.push_back(1);
        }
        else if (i == 2) {
            vec[i].len = 2;
            vec[i].v.push_back(1);
            vec[i].v.push_back(1);
        }
        else if (i == 0) {
            vec[i].len = 1000000000000000;
            vec[i].v.push_back(1);
        }
        else if (sqrt(i) == round(sqrt(i)))
        {
          vec[i].len = 1;
          vec[i].v.push_back(sqrt(i));
        }
        else for (int j = 1; j <= round(sqrt(i)) + 1; j++)
        {
          if (vec[i].len == 2){
            break;
          }
          if (i - j * j >= 0){
            if (vec[i].len > vec[i - j * j].len + 1)
            {
              vec[i].len = vec[i - j * j].len + 1;
              vec[i].v = {};
              vec[i].v = vec[i - j*j].v;
              vec[i].v.push_back(j);
            }
          }
        }
      }
    cout << n << " = ";
    for (int j = 0; j < vec[n].len; j++) {
        cout << vec[n].v[j] << "^2 ";
        if (j < vec[n].len - 1) cout << "+ ";
    }

    return 0;
}
