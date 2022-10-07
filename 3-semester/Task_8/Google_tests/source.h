#include <vector>


class Polynom
{
private:
    std::vector <int> base;
    int deg;
public:

    Polynom();

    Polynom(std::vector <int> vec);

    Polynom(const Polynom  &P);

    std::vector <int> getBase() const;

    int getDeg() const;

    Polynom &operator += (Polynom x);

    Polynom &operator -= (Polynom x);

    Polynom &operator *= (Polynom x);

    Polynom &operator = (const Polynom &x);
};

std::ostream& operator<<(std::ostream& ostr, Polynom P);

Polynom operator + (Polynom x, Polynom y);


Polynom operator + (Polynom x, int y);
Polynom operator - (Polynom x, Polynom y);
Polynom operator - (Polynom x, int y);
Polynom operator * (Polynom x, Polynom y);
Polynom operator * (Polynom x, int y);

std::vector <Polynom> Chebyshev2(int n);

