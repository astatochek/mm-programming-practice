#include <iostream>

class AoA
{
    size_t m;
    int** A;
    int* data;
public:
    AoA(int* Array_k, size_t m);
    ~AoA();
    AoA(const AoA& A);
    const AoA& operator=(const AoA& A);
    int get(size_t i, size_t j);
    void put(size_t i, size_t j, int val);
};

AoA::AoA(int* Array_k, size_t m): m(m), A(new int*[m])
{
    size_t size = 0;
    for (int i = 0; i < m; i++) size += Array_k[i];
    data = new int[size];
    int temp = 0;
    for (int i = 0; i < m; i++)
    {
        A[i] = data + temp;
        temp += Array_k[i];
    }
}

int AoA::get(size_t i, size_t j)
{
    if (i >= m) throw "Out of m";
    if (j >= (size_t)(A[i] - A[i+1])) throw "Out of k[i]";
    return A[i][j];
}

void AoA::put(size_t i, size_t j, int val)
{
    A[i][j] = val;
}

AoA::~AoA()
{
    delete[] A;
    delete[] data;
}

int main() {
    int *A = new int[10];
    for (int i = 0; i < 10; i++) A[i] = ((i+6)*20+3)%13+3;
    size_t size = 10;
    AoA B(A, size);
    for (int i = 0; i < size; i++) for (int j = 0; j < A[i]; j++) B.put(i, j, (((i+1)*j+7)*20+3)%13+3);
    for (int i = 0; i < size; i++)
    {
        std::cout << A[i] << ": ";
        for (int j = 0; j < A[i]; j++) std::cout << B.get(i, j) << " ";
        std::cout << "\n";
    }

    return 0;
}
