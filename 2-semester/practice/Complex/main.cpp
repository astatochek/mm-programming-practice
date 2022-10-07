#include <iostream>
#include <math.h>
using namespace std;

struct Complex
{
    float a, b;

    Complex (float x, float y)
    {
        a = x;
        b = y;
    }

    Complex (Complex &x)
    {
        a = x.a;
        b = x.b;
    }

    Complex& operator += (Complex &x)
    {
        a += x.a;
        b += x.b;
        return *this;
    }

    Complex& operator -= (Complex &x)
    {
        a -= x.a;
        b -= x.b;
        return *this;
    }

    Complex& operator *= (Complex &x)
    {
        float new_a = a*x.a - b*x.b;
        float new_b = a*x.b + x.a*b;
        a = new_a;
        b = new_b;
        return *this;
    }

    Complex& operator /= (Complex &x)
    {
        float new_a = a*x.a + b*x.b;
        float new_b = b*x.a - x.b*a;
        try
        {
            if (x.a*x.a + x.b*x.b != 0) 
            {
                a = new_a / (x.a*x.a + x.b*x.b);
                b = new_b / (x.a*x.a + x.b*x.b);
            }
            else 
                throw "can't divide by zero!\n";
        }
        catch(const char* errMsg)
        {
            std::cout << errMsg;
        }

        return *this;
    }

	Complex& operator = (Complex &x)
	{
	    a = x.a;
	    b = x.b;
	    return *this;
	}


	Complex& conjugate()
	{
		b = -b;	
		return *this;
	}
};

Complex &operator - (Complex x, Complex &y)
{
    return x -= y;
}

Complex &operator + (Complex x, Complex &y)
{
    return x += y;
}

Complex &operator * (Complex x, Complex &y)
{
    return x *= y;
}

Complex &operator / (Complex x, Complex &y)
{
    return x /= y;
}

ostream &operator << (ostream &out, Complex &x)
{
    if (x.b < 0) out << "(" << x.a << " - " << -x.b << "i" << ")";  
    else out << "(" << x.a << " + " << x.b << "i" << ")";
    return out;
}


float abs(Complex &x)
{
	return sqrt(x.a*x.a + x.b*x.b);
}
 

int main() {

    Complex a(13.3, 4.0), b(16.1, -3.2);
    Complex difference = a-b, sum = a+b, product = a*b, quotient = a/b;
    Complex a_c = a.conjugated();

    cout << a << " - " << b << " = " << difference << "\n";
    cout << a << " + " << b << " = " << sum << "\n";
    cout << a << " * " << b << " = " << product << "\n";
    cout << a << " / " << b << " = " << quotient << "\n";
    cout << "module of a: " << a.module() << "\n";
    cout << "module of b: " << b.module() << "\n";
    cout << "a >= b: " << Compare(a, b) << "\n";
    cout <<"a: " << a << ", conjugated to a: " << a_c << "\n";
}
