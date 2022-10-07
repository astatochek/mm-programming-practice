#include <vector>
#include <algorithm>
#include <iostream>
#include "source.h"


Polynom::Polynom()
{
    base = {0};
    deg = 0;
};


Polynom::Polynom(std::vector<int> vec)
{
    base = vec;
    deg = vec.size()-1;
}

std::vector <int> Polynom::getBase() const
{
    return base;
}

int Polynom::getDeg() const
{
    return deg;
}


Polynom::Polynom(const Polynom  &P)
{
    base = P.getBase();
    deg = base.size()-1;
}


Polynom& Polynom::operator += (Polynom x)
{
    int n = x.getDeg() - deg;
    if (n > 0) // приведение к одинаковому размеру
    {
        while (n--)
            base.push_back(0);
    }

    for (int i = 0; i < x.getBase().size(); i++) // сложение коэффициентов
        base[i] += x.getBase()[i];


    for (int i = base.size() - 1; i > 0; i--) // убираем лишние нули в конце
    {
        if (base[i] == 0)
        {
            base.erase(base.begin() + i);
            continue;
        }
        if (base[i] != 0)
            break;
    }


    deg = base.size()-1;

    return *this;
}

Polynom& Polynom::operator -= (Polynom x)
{
    int n = x.getDeg() - deg;
    if (n > 0) // приведение к одинаковому размеру
    {
        while (n--)
            base.push_back(0);
    }

    for (int i = 0; i < x.getBase().size(); i++) // вычитанеи коэффициентов
        base[i] -= x.getBase()[i];


    for (int i = base.size() - 1; i > 0; i--) // убираем лишние нули в конце
    {
        if (base[i] == 0)
        {
            base.erase(base.begin() + i);



            continue;
        }
        if (base[i] != 0)
            break;
    }


    deg = base.size()-1;

    return *this;
}

Polynom& Polynom::operator *= (Polynom x)
{
    int n = base.size() + x.getBase().size();
    std::vector <int> res (n, 0);


    for (int i = 0; i < base.size(); i++)
        for (int j = 0; j < x.getBase().size(); j++)
            res[i + j] += base[i] * x.getBase()[j];


    for (int i = res.size() - 1; i > 0; i--) // убираем лишние нули в конце
    {
        if (res[i] == 0)
        {
            res.erase(res.begin() + i);
            continue;
        }
        if (res[i] != 0)
            break;
    }

    base = res;

    deg = base.size()-1;

    return *this;
}

Polynom& Polynom::operator = (const Polynom &x)
{
    base = x.getBase();
    deg = base.size()-1;
    return *this;
}

std::ostream& operator<<(std::ostream& ostr, Polynom P)
{
    std::vector <int> vec = P.getBase();

    if (vec == std::vector <int> {0})
    {
        ostr << "0";
        return ostr;
    }

    bool flag = true;
    for (int i = 0; i < vec.size(); i++)
    {
        if (flag && vec[i] != 0)
        {
            ostr << vec[i];
            if (i != 0)
            {
                ostr << "x";
                if (i != 1)
                    ostr << "^" << i;
            }

            flag = false;
            continue;
        }

        if (!flag && vec[i] != 0)
        {
            if (vec[i] > 0)
                ostr << " + ";
            else
                ostr << " - ";

            if (abs(vec[i]) != 1)
                ostr << abs(vec[i]);
            ostr << "x";
            if (i != 1)
                ostr << "^" << i;
        }

    }

    return ostr;
}


Polynom operator + (Polynom x, Polynom y)
{
    return x += y;
};

Polynom operator + (Polynom x, int y)
{
    return x += Polynom({y});
};

Polynom operator - (Polynom x, Polynom y)
{
    return x -= y;
};

Polynom operator - (Polynom x, int y)
{
    return x -= Polynom(std::vector<int>{y});
};

Polynom operator * (Polynom x, Polynom y)
{
    return x *= y;
};

Polynom operator * (Polynom x, int y)
{
    return x *= Polynom(std::vector<int>{y});
};




std::vector <Polynom> Chebyshev2(int n)
{
    std::vector <Polynom> res;
    if (n > 0)
        res.push_back(Polynom({1}));
    if (n > 1)
        res.push_back(Polynom({0, 2}));
    for (int i = 2; i < n; i++)
        res.push_back(Polynom({0, 2}) * res[i-1] - res[i-2]);

    return res;

}
