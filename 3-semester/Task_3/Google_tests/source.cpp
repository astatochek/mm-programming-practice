#include <vector>
#include <algorithm>
#include <iostream>

std::vector <std::vector <int> > to2D(std::vector <int> array, int m, int n)
{
    std::vector <std::vector <int> > res (n, std::vector <int> (m, 0));
    std::vector <int> :: iterator it, kt;
    std::vector <std::vector <int>> :: iterator jt;

    for (it = array.begin(); it != array.end(); it++)
    {
        jt = res.begin() + (it - array.begin()) / m;
        kt = (*jt).begin() + (it - array.begin()) % m;

        *kt = *it;
    }

    return res;
}

std::vector <int> to1D(std::vector <std::vector <int> > array)
{
    std::vector <int> res (array.size() * (*array.begin()).size());
    std::vector <std::vector <int>> :: iterator it;
    std::vector <int> :: iterator jt, kt;


    for (it = array.begin(); it != array.end(); it++)
        for (jt = (*it).begin(); jt != (*it).end(); jt++)
        {
            kt = res.begin() + (*it).size() * (it - array.begin()) + (jt - (*it).begin());
            *kt = *jt;
        }


    return res;
}


class matrix
{
private:
    int size;
    int znak;
public:
    std::vector <std::vector <double> > M;

    matrix(std::vector <std::vector <double> > a);

    void swapLine(int i, int j);
    void swapColumn(int i, int j);

    void changeLine(int i, int j, double coeff);
    void changeColumn(int i, int j, double coeff);

    int getZnak();
};



matrix::matrix(std::vector <std::vector <double> > a)
{
    M = a;
    size = a.size();
    znak = 1;
}

int matrix::getZnak()
{ return znak; }

void matrix::swapLine(int i, int j)
{
    std::vector <double> tmp = M[i];
    M[i] = M[j];
    M[j] = tmp;

    znak *= pow(-1, abs(i - j));
}

void matrix::swapColumn(int i, int j)
{
    std::vector <double> tmp(size);
    for (int g = 0; g < size; g++)
        tmp[g] = M[g][j];

    for (int g = 0; g < size; g++)
    {
        M[g][j] = M[g][i];
        M[g][i] = tmp[g];
    }

    znak *= pow(-1, abs(i - j));
}

void matrix::changeColumn(int i, int j, double coeff)
{
    for (int g = 0; g < size; g++)
        M[g][i] += coeff * M[g][j];

}

void matrix::changeLine(int i, int j, double coeff)
{
    for (int g = 0; g < size; g++)
        M[i][g] += coeff * M[j][g];
}


double det(matrix &matrix)
{
    int size = matrix.M.size();
    for (int pos = 0; pos < size - 1; pos++)
    {
        bool flag = false;
        for (int i = pos; i < size; i++)
        {
            if (matrix.M[i][pos] != 0)
            {
                matrix.swapLine(pos, i);
                flag = true;
                break;
            }
        }
        if (!flag)
            return 0;

        for (int i = pos + 1; i < size; i++)
        {
            matrix.changeLine(i, pos, (-1) * matrix.M[i][pos] / matrix.M[pos][pos] );
        }

    }

    for (int pos = 0; pos < size - 1; pos++)
    {

        for (int i = pos + 1; i < size; i++)
        {
            matrix.changeColumn(i, pos, (-1) * matrix.M[pos][i] / matrix.M[pos][pos] );
        }

    }



    double det = 1;
    for (int i = 0; i < size; i++)
    {
        if (matrix.M[i][i] == 0)
            return 0;
        det *= matrix.M[i][i];
    }


    det *= matrix.getZnak();


    return det;



}

