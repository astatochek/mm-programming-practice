#include <iostream>
#include "sos.h"



int main() {
    pair<int, char> p(2, 'a');
    pair <int, char> q(5, 'h');
    std::cout << "Two pairs of <int, char> were created:\np = " << p << "\nq = " << q << "\n";
    if (p == q) std::cout << p << " = " << q << " <=> q = p\n";
    else std::cout << p << " != " << q << " <=> q != p\n";
    q = p;
    std::cout << "Lets make q = p\nq = " << q << "\n";
    if (p == q) std::cout << p << " = " << q << " <=> q = p\n";
    else std::cout << p << " != " << q << " <=> q != p\n";
    std::cout << "You can change elements of a pair separately:\nq.first = 10\n";
    q.first = 10;
    std::cout << "q = " << q << "\nq.second = 'r'\n";
    q.second = 'r';
    std::cout << "q = " << q << "\n";
    if (p == q) std::cout << p << " = " << q << " <=> q = p\n";
    else std::cout << p << " != " << q << " <=> q != p\n";

    return 0;
}