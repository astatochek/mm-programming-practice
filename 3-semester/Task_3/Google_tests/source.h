#include <vector>

std::vector <std::vector <int> > to2D(std::vector <int> array, int m, int n);

std::vector <int> to1D(std::vector <std::vector <int> > array);


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


double det(matrix &matrix);