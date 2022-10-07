#include <iostream>
using namespace std;

// оригинальный класс
class A{
    int a;
    double b;
    char c;
    long long d;
public:
    A(int x, double y, char t, long long z): a(x), b(y), c(t), d(z) {}
};

// вспомогательный класс
class B{
public:
    int a1;
    double b1;
    char c1;
    long long d1;
    B(int x, double y, char t, long long z): a1(x), b1(y), c1(t), d1(z) {}
};

int &get_a( A &cls )
{
    void *p = &cls;
    B *pb = static_cast<B *>( p );
    return pb->a1;
}

double &get_b( A &cls )
{
    void *p = &cls;
    B *pb = static_cast<B *>( p );
    return pb->b1;
}

char &get_c( A &cls )
{
    void *p = &cls;
    B *pb = static_cast<B *>( p );
    return pb->c1;
}

long long &get_d( A &cls )
{
    void *p = &cls;
    B *pb = static_cast<B *>( p );
    return pb->d1;
}

void put_a( A &cls, int x )
{
    void *p = &cls;
    B *pb = static_cast<B *>( p );
    pb->a1=x;
}

void put_b( A &cls, double x )
{
    void *p = &cls;
    B *pb = static_cast<B *>( p );
    pb->b1=x;
}

void put_c( A &cls, char x )
{
    void *p = &cls;
    B *pb = static_cast<B *>( p );
    pb->c1=x;
}

void put_d( A &cls, long long x )
{
    void *p = &cls;
    B *pb = static_cast<B *>( p );
    pb->d1=x;
}

int main()
{
    A test(10, 2.1, 'a', 12222);

    int &a_1 = get_a(test);
    double &b_1 = get_b(test);
    char &c_1 = get_c(test);
    long long &d_1 = get_d(test);

    cout << a_1 << '\n';
    cout << b_1 << '\n';
    cout << c_1 << '\n';
    cout << d_1 << '\n';

    put_a(test, 11);
    put_b(test, 2.2);
    put_c(test, 'b');
    put_d(test, 122223);

    cout << a_1 << '\n';
    cout << b_1 << '\n';
    cout << c_1 << '\n';
    cout << d_1 << '\n';
    
    return 0;
}
