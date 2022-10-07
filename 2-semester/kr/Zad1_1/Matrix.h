#include <iostream>
#include <vector>

template <typename T, size_t rows, size_t cols> class Matrix;

template<typename T, size_t rows, size_t cols>

class Matrix
{
private:
    T** M;
public:

    template<typename T, size_t rows, size_t cols>
    Matrix<T, rows, cols>()
    {
        M = new T* [rows];
        for (int i = 0; i < rows; i++)
        {
            M[i] = new T[cols];
        }
    }

    template<typename T, size_t N>
    Matrix<T, 1, N>()
    {
        M = new T* [1];
        M[0] = new T [N];
    }

    template<typename T, size_t N>
    Matrix<T, N, N>()
    {
        M = new T* [N];
        for (int i = 0; i < N; i++)
        {
            M[i] = new T[N];
        }
    }

    ~Matrix()// одинаковый, так как устроены они все одинаково
    {
        M = new T* [rows];
        for (int i = 0; i < rows; i++)
        {
            delete[] M[i];
        }
        delete[] M;
    }

    Matrix(const Matrix  &_M);
    Matrix<T, rows, cols> &operator=(const Matrix<T, rows, cols> &_M);
    Matrix<T, rows, cols> operator*(const double d);

    template<typename T, size_t N>
    Matrix<T, N, N> transpose();

    template<typename T, size_t rows, size_t cols>
    Matrix<T, rows, cols> operator*(const Matrix<T, rows, cols> &_M);// с проверкой на возможность

    template<typename T, size_t N>
    Matrix<T, N, N> operator*(const Matrix<T, N, N> &_M);// без проверки

    template<typename T, size_t rows, size_t cols>
    T& operator()(unsigned row, unsigned col);
    T operator()(unsigned row, unsigned col ) const ;

    template<typename T, size_t N> // для вектора только одна координата требуется
    T& operator()(unsigned col);
    T operator()(unsigned col) const ;
};




