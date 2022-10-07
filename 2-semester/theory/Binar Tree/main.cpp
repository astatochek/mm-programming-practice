#include <iostream>
#include <vector>
#include <algorithm>

class tree
{
private:
    struct node
    {
        int key;
        node* parent = NULL;
        node* heir1 = NULL;
        node* heir2 = NULL;

        node(int k, node* par = NULL, node* h1 = NULL, node* h2 = NULL);
    };
    node * p;
    void destroy_tree(node *leaf);
    std::vector <int> sort(node *leaf, std::vector<int> &vec);
    void bfs(std::vector< std::vector<int> > &V, int depth=0, node*pv = NULL);

public:
    void destroy_tree();
    tree(int k);
    ~tree();
    void insert(int k);
    bool find(int k);
    std::vector <int> sort();
    void bfs();
};

tree::node::node(int k, node* par, node* h1, node* h2)
{
    this->key = k;
    this->parent = par;
    this->heir1 = h1;
    this->heir2 = h2;
}

tree::tree(int k)
{
    p = new node(k, NULL, NULL, NULL);
}

tree::~tree(){
    destroy_tree();
}

void tree::destroy_tree(node *leaf)
{
    if(leaf != NULL)
    {
        destroy_tree(leaf->heir1);
        destroy_tree(leaf->heir2);
        delete leaf;
    }
}

void tree::destroy_tree()
{
    destroy_tree(p);
}


void tree::insert(int k)
{
    node * tmp = p;
    while ((tmp->heir1 != NULL) || (tmp->heir2 != NULL))
    {
        if (k < tmp->key)
        {
            if (tmp->heir1 != NULL)
                tmp = tmp->heir1;
            else
                break;
        }
        else
        {
            if (tmp->heir2 != NULL)
                tmp = tmp->heir2;
            else
                break;
        }
    }

    node *new_node = new node(k, tmp, NULL, NULL);
    new_node->key = k;

    if (k < tmp->key)
        tmp->heir1 = new_node;
    else
        tmp->heir2 = new_node;
}


bool tree::find(int k)
{
    node * tmp = p;
    while ((tmp->heir1 != NULL) || (tmp->heir2 != NULL))
    {
        if (tmp->key == k)
            break;
        if (k < tmp->key)
        {
            if (tmp->heir1 != NULL)
                tmp = tmp->heir1;
            else
                break;
        }
        else
        {
            if (tmp->heir2 != NULL)
                tmp = tmp->heir2;
            else
                break;
        }
    }
    if (tmp->key == k)
        return true;
    return false;
};

std::vector <int> tree::sort(node *leaf, std::vector<int> & vec)
{
    if (leaf != NULL)
    {
        if (leaf->heir1 != NULL)
            vec = sort(leaf->heir1, vec);
        vec.push_back(leaf->key);
        if (leaf->heir2 != NULL)
            vec = sort(leaf->heir2, vec);
    }
    return vec;

}

std::vector <int> tree::sort()
{
    std::vector<int> vec;
    std::vector<int> res = sort(p, vec);
    return res;
}


void tree::bfs(std::vector<std::vector<int>> &V, int depth, node* pv)
{
    if (pv == NULL)
        pv = p;
    if (depth == V.size()) V.push_back({});
    V[depth].push_back(pv->key);
    if (pv->heir1 != NULL)
        bfs(V, depth+1, pv->heir1);
    if (pv->heir2 != NULL)
        bfs(V, depth+1, pv->heir2);
}

void tree::bfs()
{
    std::vector<std::vector<int>> res;
    bfs(res);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            std::cout << res[i][j] << " ";
        }
        std::cout << "\n";
    }
}


int main()
{

    std::cout << "Example 1:\n";
    tree example_tree(35);
    for (int i = 50; i != 14; i = (5*i - 1)%90) example_tree.insert(i);
    std::cout << "Tree:\n";
    example_tree.bfs();
    std::cout << "Sorted list: ";
    std::vector <int> ex = example_tree.sort();
    for (int i = 0; i < ex.size(); i++) std::cout << ex[i] << " ";
    std::cout << "\n\n\n";



    int k, val;
    std::cout << "Insert the number of nodes:";
    std::cin >> k;
    std::cout << "Insert values for nodes: ";
    std::cin >> val;
    tree new_tree(val);
    for (int i = 1; i < k; i++)
    {
        std::cin >> val;
        new_tree.insert(val);
    }
    std::cout << "Tree:\n";
    new_tree.bfs();
    std::cout << "Sorted list: ";
    std::vector <int> ne = new_tree.sort();
    for (int i = 0; i < ne.size(); i++) std::cout << ne[i] << " ";
    std::cout << "\n";
    std::cout << "Type the number to check if it is in the tree\nTo end the process type '-42'\n";
    std::cin >> val;
    while (val != -42)
    {
        if (new_tree.find(val)) std::cout << val << " is in the tree\n";
        else std::cout << val << " is not in the tree";
        std::cin >> val;
    }
    std::cout << "Process finished.\n";



    return 0;
}
