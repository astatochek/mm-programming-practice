#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>

#include "string.h"


std::string getNormalLineA(std::string path) // используя функции библиотеки string.h
{
    std::string line, tmp, res;

    std::ifstream in(path);
    if (in.is_open())
    {
        while (getline(in, line))
        {
            char str[255];
            strcpy(str, line.c_str()); // превращаем string в char *
            char * word = strtok (str," "); // достаем первую лексему по разделителю

            while (word != NULL)
            {
                tmp = (const char*)word; // делаем string из char *
                if (!res.empty() && tmp != ".")
                    res += " ";
                res += tmp;

                word = strtok (NULL, " "); // продолжаем доставать лексемы (?)
            }

            in.close();

            return res;
        }
    }

    return "";

}

std::string getNormalLineB(std::string path) // за один проход без создания дополнительной строки
{
    std::string line, tmp, res;

    std::ifstream in(path);
    if (in.is_open())
        while (getline(in, line))
        {
            std::string::iterator it; // заводим итератор
            it = line.begin();
            while(it != line.end() - 1)
            {
                bool flag = false;

                if (*it == ' ' && *(it + 1) == ' ') // если смотрим на пробел, после которого тоже пробел
                {
                    if (it == line.begin()) // чтобы итератор не вылетел влево из начала строки
                        flag = true;
                    line.erase(it); // удаляем лишний пробел

                    if (!flag)
                        it--;
                }

                if (!flag)
                    it++;
            }

            it = line.begin();
            if (*it == ' ') // while выше может оставить один пробел в начале, так что его тоже удаляем
                line.erase(it);

            it = line.end() - 1;
            if (*it == '.' && *(it-1) == ' ') // если перед точкой был пробел, то его надо убрать
                line.erase(it-1);


            in.close();
            return line;
        }


    return "";
}



std::string getAbnormalLine(std::string path) // напечатать слова строки, не совпадающие с последним словом
{
    std::string line, tmp, res;

    std::vector <std::string> vec;

    std::ifstream in(path);
    if (in.is_open())
    {
        while (getline(in, line))
        {
            char str[255];
            strcpy(str, line.c_str()); // превращаем string в char *
            char * word = strtok (str," ."); // достаем первую лексему по разделителю

            while (word != NULL)
            {
                tmp = (const char*)word; // делаем string из char *

                vec.push_back(tmp);

                word = strtok (NULL, " ."); // продолжаем доставать лексемы (?)
            }

            in.close();



            for (auto &elem : vec)
            {
                if (elem != *(vec.end()-1))
                    res += elem + " ";
            }

            if (!res.empty())
                res.erase(res.end()-1);
            return res;


        }
    }

    return "";

}



std::string delLastLetter(std::string path) // удалив последнюю букву слова
{
    std::string line, tmp, res;

    std::ifstream in(path);
    if (in.is_open())
    {
        while (getline(in, line))
        {
            char str[255];
            strcpy(str, line.c_str()); // превращаем string в char *
            char * word = strtok (str," "); // достаем первую лексему по разделителю

            while (word != NULL)
            {
                tmp = (const char*)word; // делаем string из char *
                tmp.erase(tmp.end()-1);
                if (!tmp.empty())
                    res += tmp + " ";

                word = strtok (NULL, " "); // продолжаем доставать лексемы (?)
            }
            if (!res.empty())
                res.erase(res.end() - 1);

            in.close();

            return res;
        }
    }

    return "";

}


