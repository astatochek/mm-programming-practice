#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <float.h>
#include <cmath>

// Полный перебор за n^2 с маленькой эвристикой для отсеивания явно неподходщих сумм длин.
// n на всякий вводить больше 2


class dot
{
    double x;
    double y;
public:
    dot(double x_, double y_);
    double gtx(){return x;}
    double gty(){return y;}

};

dot::dot(double x_, double y_)
{
    x = x_;
    y = y_;
}

double CalcDist(dot A, dot B)
{
    return sqrt((A.gtx() - B.gtx())*(A.gtx() - B.gtx()) + (A.gty() - B.gty())*(A.gty() - B.gty()));
}



float rnd(int min, int max)
{return min + rand() % (1000*(max-min)) / 1000.0f;}

int main() {
    int n, check;
    double a, b;
    std::cout << "Type the number of dots:";
    std::cin >> n;
    std::cout << "If you want to type your dots, type 1\nIf you want to look at random ones, type 2\n";
    std::cin >> check;
    double left_border = -10.0, right_border = 10.0;
    srand(time(NULL));
    std::vector <dot> v;
    for (int i = 0; i < n; i++)
    {
        if (check == 2) v.push_back(dot(rnd(left_border, right_border), rnd(left_border, right_border)));
        if (check == 1)
        {
            std::cin >> a >> b;
            v.push_back(dot(a, b));
        }
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << i+1 << ": " << v[i].gtx() << " " << v[i].gty() << "\n";
    }

    int index;
    double min = DBL_MAX, cur;
    for (int i = 0; i < n; i++)
    {
        //std::cout << "iter: " << i << "\n";
        cur = 0.0;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                cur += CalcDist(v[i], v[j]);
                if (cur > min) break;
            }
        }
        if (cur <= min)
        {
            min = cur;
            index = i;
        }
    }
    std::cout << "Your dot is " << index+1 << ": " << v[index].gtx() << " " << v[index].gty() << "\n";



    return 0;
}
