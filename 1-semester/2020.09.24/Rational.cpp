#include <iostream>
using namespace std;

// СТРУКТУРА - РАЦИОНАЛЬНЫЕ ЧИСЛА

// вычисление НОД
int gcd(int a, int b){
    if (b==0) return a;
    return abs(gcd(b, abs(a)%b));
};

// вычисление НОК
int lcd(int a, int b){
    return abs((a * b) / gcd(a, b));
};

struct Rational {

    int nom;
    unsigned int denom;

    Rational(int x, unsigned int y) {
        nom = x / gcd(x, y);
        denom = y / gcd(x, y);
    };


    Rational &operator *= (Rational &x){
        nom *= x.nom;
        denom *= x.denom;
        int current_gcd = gcd(nom, denom);
        nom /= current_gcd;
        denom /= current_gcd;
        return *this;
    };

    Rational &operator /= (Rational &x){

        if (x.nom < 0){
            denom += -x.nom;
            nom *= -x.denom;
        }
        else{
            nom *= x.denom;
            denom *= x.nom;
        }
        int current_gcd = gcd(nom, denom);
        nom /= current_gcd;
        denom /= current_gcd;
        return *this;
    };

    Rational &operator += (Rational &x){
        int current_lcd = lcd(denom, x.denom);
        nom *= current_lcd / denom;
        denom = current_lcd;
        if (x.nom < 0)
            nom += -1 * int(abs(x.nom) * current_lcd / x.denom);
        else
            nom += x.nom * current_lcd / x.denom;
        int current_gcd = gcd(nom, denom);
        nom /= current_gcd;
        denom /= current_gcd;
        return *this;
    };

    Rational &operator -= (Rational &x){
        int current_lcd = lcd(denom, x.denom);
        nom *= current_lcd / denom;
        denom = current_lcd;
        if (x.nom < 0)
            nom -= -1 * int(abs(x.nom) * current_lcd / x.denom);
        else
            nom -= x.nom * current_lcd / x.denom;
        int current_gcd = gcd(nom, denom);
        nom /= current_gcd;
        denom /= current_gcd;
        return *this;
    };

    Rational &operator *= (int &x){
        nom *= x;
        int current_gcd = gcd(nom, denom);
        nom /= current_gcd;
        denom /= current_gcd;
        return *this;
    };

    Rational &operator /= (int &x){
        if (x < 0){
            nom *= -1;
            denom *= abs(x);
        }
        else denom *= x;
        int current_gcd = gcd(nom, denom);
        nom /= current_gcd;
        denom /= current_gcd;
        return *this;
    };


};

Rational &operator * (Rational x, Rational &y){
    return x *= y;
};

Rational &operator * (Rational x, int &y){
    return x *= y;
};

Rational &operator / (Rational x, int &y){
    return x /= y;
};

Rational &operator / (Rational x, Rational &y){
    return x /= y;
};

Rational &operator + (Rational x, Rational &y){
    return x += y;
};

Rational &operator - (Rational x, Rational &y){
    return x -= y;
};
ostream &operator << (ostream &out, Rational &x){
    if (x.denom == 0) out << "Inf";
    else if (x.nom == 0) out << 0;
    else if (x.denom == 1) out << x.nom;
    else out << x.nom << "/" << x.denom;
    return out;
};

int main() {
    Rational a(17, 4), b(-34, 8);
    int g = 10, h = -10;
    Rational c = a*b, d = a/b, e = a+b, f = a-b, i = a*g, j = a/h;
    cout << a << " * " << b << " = " << c << endl;
    cout << a << " : " << b << " = " << d << endl;
    cout << a << " + " << b << " = " << e << endl;
    cout << a << " - " << b << " = " << f << endl;
    cout << a << " * " << g << " = " << i << endl;
    cout << a << " : " << h << " = " << j << endl;
}
