#include <iostream>
#include <vector>

struct triplet
{
    size_t i;
    size_t j;
    int data;
    triplet * prev = NULL;
    triplet(size_t i_, size_t j_, int data_)
    {
        i = i_;
        j = j_;
        data = data_;
    };
};

class Matrix
{
    triplet * last = NULL;
public:
    Matrix(std::vector <std::vector <int>> M);
    ~Matrix();
    void set(size_t i, size_t j, int data);
    int get(size_t i, size_t j);

};

Matrix::Matrix(std::vector <std::vector <int>> M)
{
    for (int i = 0; i < M.size(); i++)
    {
        for (int j = 0; j < M[i].size(); j++)
        {
            if (M[i][j] != 0)
            {
                if (!last)
                {
                    last = new triplet(i, j, M[i][j]);
                    last->prev = NULL;
                }
                else
                {
                    triplet* p = new triplet(i, j, M[i][j]);
                    p->prev = last;
                    last = p;
                }
            }
        }
    }
}

Matrix::~Matrix()
{
    if (!last) return;
    triplet * p = last;
    while (p != NULL)
    {
        triplet * temp = p;
        p = p->prev;
        delete temp;
    }
    delete p;
}

void Matrix::set(size_t i, size_t j, int data)
{
    if (data != 0)
    {
        if (!last){
            last = new triplet(i, j, data);
            last->prev = NULL;
        }
        else
        {
            triplet * p = last;
            if (p->i == i && p->j == j){
                p->data = data;
            }
            else
            {
                p = p->prev;
                bool flag = false;
                while (p != NULL)
                {
                    if (p->i == i && p->j == j && !flag)
                    {
                        p->data = data;
                        flag = true;
                    }
                    p = p->prev;
                }
                if (!flag)
                {
                    triplet* temp = new triplet(i, j, data);
                    temp->prev = last;
                    last = temp;
                }
            }
        }
    }
}


int Matrix::get(size_t i, size_t j)
{
    triplet * p = last;
    if (p->i == i && p->j == j) return p->data;
    p = p->prev;
    while (p != NULL)
    {
        if (p->i == i && p->j == j) return p->data;
        p = p->prev;
    }
    return 0;
}

int main()
{
    std::vector <std::vector<int>> V = {{1, 0, 0, 0, 0},
                                        {0, 1, 0, 0, 0},
                                        {0, 0, 1, 0, 0},
                                        {0, 0, 0, 1, 0},
                                        {0, 0, 0, 0, 1}};
    Matrix M(V);
    std::cout << "--> M[0][4] = " << M.get(0, 4) << "\n";
    std::cout << "M.set(0, 4, 4);\n";
    M.set(0, 4, 4);
    std::cout << "--> M[0][4] = " << M.get(0, 4);

    return 0;
}
