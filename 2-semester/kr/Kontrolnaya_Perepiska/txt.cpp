#include <iostream>
#include <fstream>
#include <istream>
#include "string.h"

struct txt
{
    char* str;
    size_t size;
    txt(const char* file_name);
    ~txt();
    char get(size_t index);
    void set(size_t index, char val);
    int cnt(char* T);
};


txt::txt(const char* file_name)
{
    size = 1;
    size_t arr_size = 1;
    str = new char[arr_size];
    std::ifstream file(file_name);

    if (file.is_open())
    {
        while(!file.eof())
        {
            if (arr_size <= size)
            {
                arr_size *= 2;
                char* prev = str;
                str = new char[arr_size];
                memcpy(str, prev, size+1);
                delete prev;
            }
            char c;
            file.read(&c, 1);
            str[size-1] = c;
            size++;
        }
    }
    else throw "no such file";
}


int txt::cnt(char* T)
{
    size_t cnt = 0;
    for (size_t i = 0; i < size; i++) if (str[i] == *T) cnt++;
    return cnt;
}


int main()
{
    txt t("exmpl.txt");
    return 0;
}