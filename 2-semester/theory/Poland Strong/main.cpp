#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <ctype.h>

/*
Программа будет работать только для операций сложения и умножетия, также можно использовать скобки.
Числа должны быть интовыми.
Все операции линейные, так что асимптотическая сложность равна O(n), где n - длина введенной строки уравнения.
Уравнение вводится в одну строку, между числами и любыми(!) знаками ставятся пробелы. Числа долны быть неотрицательными(!).
Пример ввода:
    ( 5 + 4 ) * 9 + ( 33 + 55 ) + 3
Вывод:
    5 4 + 9 * 33 55 + + 3 + = 172

*/


using namespace std;

// функция для проверки, является ли строка числом
bool IsNumber(string s){
    for (int i = 0; i < s.length(); i++){
        if (!isdigit(s[i])) return false;
    }
    return true;
}

//структура и соответствующие ей функции
class stack
{
public:
    string val;
    stack* prev;
    stack();
};
stack::stack() {
    val = "end";
}


void push(string value, stack* &p)
{

    stack* temp = new stack;
    temp->val = value;
    temp->prev = p;
    p = temp;
}


void pop(stack* &p)
{
    stack *temp = p->prev;
    delete p;
    p = temp;
}

ostream &operator << (ostream &out, stack* p){
    out << p->val;
    return out;
}

int prior(string a)
{
    if (a == "(") return 1;
    else if (a == "+" || a == "-") return 2;
    else if (a == "*" || a == "/") return 3;
    return 0;
}


//преобразование вектора обычной записивыражения в обратную польскую
vector <string> to_poland(vector <string> virazhenie){
    vector <string> res;
    stack pol = stack();
    stack* polska = &pol;
    for (int i = 0; i < virazhenie.size(); i++){

        if (IsNumber(virazhenie[i])){
            res.push_back(virazhenie[i]);
        }

        else if (virazhenie[i] == "(") push(virazhenie[i], polska);

        else if (virazhenie[i] == ")"){
            while (polska->val != "("){
                res.push_back(polska->val);
                pop(polska);
            }
            pop(polska);
        }

        else if (virazhenie[i] == "+" || virazhenie[i] == "-" || virazhenie[i] == "*" || virazhenie[i] == "/"){
            while (prior(virazhenie[i]) <= prior(polska->val)){
                res.push_back(polska->val);
                pop(polska);
            }
            push(virazhenie[i], polska);
        }



    }

    while (polska->val != "end"){
        res.push_back(polska->val);
        pop(polska);
    }

    return res;
}

vector <string> to_vector(string s){
    s += " ";
    vector <string> vec;
    string temp = "";
    string tmp;

    for (int i = 0; i < s.length(); i++){
        if (s[i] == ' '){
            if (temp != ""){
                vec.push_back(temp);
                temp.clear();
            }
        }
        else if (i == s.length()-1){
            vec.push_back(tmp);
            tmp.clear();
        }
        else if (s[i] == ')' || s[i] == '(' || s[i] == '*' || s[i] == '+'){
            tmp += s[i];
            vec.push_back(tmp);
            tmp.clear();
        }
        else{
            tmp += s[i];
            temp += tmp;
            tmp.clear();
        }
    }
    return vec;
}

int calculate(vector <string> vec){
    stack tmp = stack();
    stack* pol = &tmp;
    int n1, n2, res;
    for (int i = 0; i < vec.size(); i++){
        if (IsNumber(vec[i])) push(vec[i], pol);
        else{
            n2 = stoi(pol->val);
            pop(pol);
            n1 = stoi(pol->val);
            pop(pol);

            if (vec[i] == "+") res = n1 + n2;
            else if (vec[i] == "*") res = n1 * n2;

            push(std::to_string(res), pol);
        }
    }
    res = stoi(pol->val);
    return res;
}
int main()
{
    //ввоб выражения как строки с разделителем пробелом
    string s, st;
    st = "( 3 * ( 4 + 2 ) + 6 + 5 ) * 9";
    cout << "Example 1:\n" << st << " <=> ";
    vector <string> vec = to_vector(st);
    vector <string> pol = to_poland(vec);
    for (int i = 0; i < pol.size(); i++) cout << pol[i] << " ";
    int res = calculate(pol);
    cout << "= " << res << "\n";

    st = "7 + 5 * 6 + ( 3 + ( 3 + 2 ) ) * 10";
    cout << "Example 2:\n" << st << " <=> ";
    vec = to_vector(st);
    pol = to_poland(vec);
    for (int i = 0; i < pol.size(); i++) cout << pol[i] << " ";
    res = calculate(pol);
    cout << "= " << res << "\n";

    cout << "Type your expression:\n";
    getline(cin, s, '\n');
    vec = to_vector(s);
    pol = to_poland(vec);
    for (int i = 0; i < pol.size(); i++) cout << pol[i] << " ";
    res = calculate(pol);
    cout << "= " << res;
    return 0;
}
