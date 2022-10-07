#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <utility>
#include <algorithm>
#include <vector>
#include <string>

#include "Node.h"
#include "Edge.h"
#include "Graph.h"


std::vector <std::vector<int>> makeM(std::vector <int> verts, std::vector <std::vector<int>> M) // �������� ������� �� ������ ������������, �� � �������� ���������� ������ �� ����
{
    std::vector <std::vector<int>> res;
    std::vector <int> tmp;
    for (auto i : verts)
    {
        tmp = {};
        for (auto j : verts)
        {
            tmp.push_back(M[i][j]);
        }
        res.push_back(tmp);
    }
    return res;
}




struct triplet
{
    size_t i;
    size_t j;
    int dist;
    triplet(size_t i_, size_t j_, int dist_)
    {
        i = i_;
        j = j_;
        dist = dist_;
    }
};

bool cmp(triplet a, triplet b)
{
    return a.dist < b.dist;
}

int Kruskal_unbranching_cycled(std::vector <std::vector<int>> M) // ������ ��������� �������� ��� ���������� ������ ������� �������
{
    std::vector <triplet> V; // �������� ������ �����
    for (int i = 0; i < M.size(); i++)
    {
        for (int j = 0; j < M.size(); j++)
        {
            if (i != j)
            {
                triplet tmp(i, j, M[i][j]);
                V.push_back(tmp);
            }
        }
    }
    std::vector <int> check, temp;
    for (int i = 0; i < M.size(); i++) check.push_back(0);
    sort(V.begin(), V.end(), cmp);
    std::vector <std::vector<int>> sets;
    int bound = M.size(), res = 0, cur = 0;
    for (auto &elem : V) // ������ �� ���� ������
    {
        if (sets.empty()) {
            temp = {};
            temp.push_back(elem.i);
            temp.push_back(elem.j);
            sets.push_back(temp);
            res += elem.dist;
            cur += 2;
        }
        else
        {
            bool flag = true;
            int i_loc = -1, j_loc = -1;
            for (int i = 0; i < sets.size() && flag; i++)
            {
                bool i_in = false, j_in = false;
                for (int j = 0; j < sets[i].size(); j++) {
                    if (sets[i][j] == elem.i) {
                        i_in = true;
                        i_loc = i;
                    }
                    if (sets[i][j] == elem.j) {
                        j_in = true;
                        j_loc = i;
                    }
                }
                if (i_in && j_in) flag = false;
            }
            if (flag && i_loc != -1 && sets[i_loc][sets[i_loc].size() - 1] == elem.i && j_loc == -1)
            {
                sets[i_loc].push_back(elem.j);
                cur++;
                res += elem.dist;
            }
            else if (flag && j_loc != -1 && sets[j_loc][0] == elem.j && i_loc == -1)
            {
                sets[j_loc].insert(sets[j_loc].begin(), elem.i);
                cur++;
                res += elem.dist;
            }
            if (flag && i_loc != j_loc && i_loc != -1 && j_loc != -1)
            {
                if (sets[i_loc][sets[i_loc].size() - 1] == elem.i && sets[j_loc][0] == elem.j)
                {
                    for (auto val : sets[j_loc])
                    {
                        sets[i_loc].push_back(val);
                    }
                    sets.erase(sets.begin() + j_loc);
                    res += elem.dist;
                }
            }
            if (flag && i_loc == j_loc) // == -1
            {
                temp = {};
                temp.push_back(elem.i);
                temp.push_back(elem.j);
                sets.push_back(temp);
                res += elem.dist;
                cur += 2;
            }
        }
        if (sets.size() == 1 && cur == bound && sets[0].size() == M.size()) break; // �����, ����� �������� ����������� ��� ������������ ����� ���������� �����
    }
    //printf(sets[0]);
    res += M[sets[0][sets[0].size() - 1]][sets[0][0]]; //�������� ������
    //std::cout << "\nKraskal ready: " << bound << " " << cur << " " << res << "\n";
    return res;

}


int Kruskal_Comm(std::vector <std::vector <int> > M) // ������� (������������)
{

    std::vector <triplet> V;
    for (int i = 0; i < M.size(); i++)
    {
        for (int j = 0; j < M.size(); j++)
        {
            if (i != j)
            {
                triplet tmp(i, j, M[i][j]);
                V.push_back(tmp);
            }
        }
    }
    std::vector <triplet> res;
    std::vector <int> locations;
    for (int i = 0; i < M.size(); i++)
        locations.push_back(i);

    sort(V.begin(), V.end(), cmp);



    for (auto& elem : V)
    {
        if (locations[elem.i] != locations[elem.j])
        {
            int j = locations[elem.j];
            for (int i = 0; i < locations.size(); i++)
                if (locations[i] == j)
                    locations[i] = locations[elem.i];
            res.push_back(elem);
        }
    }

    int output = 0;
    for (auto& elem : res)
        output += elem.dist;

	
    return output;

    }

void Rec(std::vector <int> path, std::vector <int> rest,
    int current_dist, std::pair <std::vector <int>, int>& res,
    std::vector <std::vector<int>> M)
{
    std::vector <int> next_path, next_rest;
    int next_current_dist;

    if (rest.size() == 1) {
        if ((current_dist + M[path[path.size() - 1]][rest[0]] + M[rest[0]][0]) <= res.second)
        {
            //std::cout << "bound changed from " << res.second << " to " << current_dist + M[path[path.size()-1]][rest[0]] + M[rest[0]][0] << "\n";
            res.second = current_dist + M[path[path.size() - 1]][rest[0]] + M[rest[0]][0];
            path.push_back(rest[0]);
            path.push_back(0);
            res.first = path;

        }
    }
    else
    {
        for (int i = 0; i < rest.size(); i++)
        {
            next_path = path;
            next_rest = rest;
            next_current_dist = current_dist;
            if ((current_dist + M[path[path.size() - 1]][rest[i]]) <= res.second)
            {
                next_current_dist += M[path[path.size() - 1]][rest[i]];
                next_path.push_back(rest[i]);
                next_rest.erase(next_rest.begin() + i);

                /*std::cout << "path: ";
                printf(next_path);
                std::cout << "; rest: ";
                printf(next_rest);
                std::cout << "; dist: " << next_current_dist << "; bound: " << res.second << "\n";*/
                if (res.second >= next_current_dist + Kruskal_Comm(makeM(next_rest, M)))
                    Rec(next_path, next_rest, next_current_dist, res, M);
            }
        }
    }
}

void BranchAndBound(Graph* graph, sf::RenderTarget* rt)
{

    bool flag = true;
    std::vector <std::vector <int> > M = graph->getMatrix();

    for (int i = 0; i < M.size(); i++)
        for (int j = 0; j < i; j++)
            if (M[i][j] != M[j][i] || M[i][j] == 0)
                flag = false;
	if (!flag)
	{
        sf::Vector2f center = graph->getCenter();
		
        sf::Text text;
        sf::Font font;
        font.loadFromFile("IBMPlexSans-Medium.ttf");
        text.setFont(font);
        text.setCharacterSize(40);
        text.setString("Error");
        text.setFillColor(sf::Color(255, 47, 47));
        sf::FloatRect rect = text.getLocalBounds();
        double width = rect.width;
        double height = rect.height;
        text.setOrigin(width / 2.0, height / 2.0);
        text.setPosition(center.x, center.y);
        rt->draw(text);
	}
	
	if (flag)
	{
        
        int bound = Kruskal_unbranching_cycled(M);
        std::pair <std::vector <int>, int> res({}, bound);
        std::vector <int> rest;
        for (int i = 1; i < M.size(); i++) rest.push_back(i);
        Rec({ 0 }, rest, 0, res, M);


        for (int i = 0; i < res.first.size() - 1; i++)
        {
            int first = res.first[i];
            int second = res.first[i + 1];




            for (auto& edge : graph->getEdges())
            {
                if (edge->getFirst()->getName() == std::to_string(first + 1) && edge->getSecond()->getName() == std::to_string(second + 1))
                {
                    edge->draw(rt, false, sf::Color(27, 134, 217));
                    edge->draw(rt, true, sf::Color(27, 134, 217));
                }
            }


        }



        for (auto& node : graph->getNodes())
        {
            node->draw(rt, sf::Color(27, 134, 217));
        }
	}
    
}