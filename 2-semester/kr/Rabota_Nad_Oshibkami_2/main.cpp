#include <iostream>

struct Node
{
    int data;
    Node* next = NULL;
    Node* prev = NULL;
};

class Circle_List
{
    Node* head;
public:
    Circle_List();
    ~Circle_List();
    Circle_List(const Circle_List& A);
    const Circle_List& operator=(const Circle_List& A);
    void push_back(int x);
    int pop_back();
    int get_max();
};

Circle_List::Circle_List()
{
    head = NULL;
};


Circle_List::~Circle_List()
{
    if(!head) return;
    Node* p = head->next;
    while (p != head)
    {
        Node* temp = p;
        p = p->next;
        delete temp;
    }
    delete head;
}

int Circle_List::get_max()
{
    int max = head->data;
    Node* p = head->next;
    while (p != head)
    {
        if (p->data > max) max = p->data;
        p = p->next;
    }
    return max;
}

void Circle_List::push_back(int x)
{
    if (head == NULL)
    {
        head = new Node;
        head->data = x;
    }
    else if (head->next == NULL)
    {
        Node* p = new Node;
        p->data = x;
        head->next = p;
        head->prev = p;
        p->next = head;
        p->prev = head;
    }
    else
    {
        Node* p = new Node;
        p->next = head;
        p->prev = head->prev;
        p->prev->next = p;
        head->prev = p;
        p->data = x;
    }
}


int Circle_List::pop_back()
{
    Node* current = head->prev;
    head->prev = current->prev;
    current->prev->next = head;
    int res = current->data;
    delete current;
    return res;
}


int main() {
    Circle_List list;
    for (int i = 0; i < 9; i++) list.push_back(((i+2)*23+11)%13);
    list.push_back(13);
    std::cout << "elements: ";
    for (int i = 0; i < 9; i++) std::cout << ((i+2)*23+11)%13 << " ";
    std::cout << 13 << "\n";
    std::cout << "current max: " << list.get_max() << "\n";
    int deleted_val = list.pop_back();
    std::cout << "elements: ";
    for (int i = 0; i < 9; i++) std::cout << ((i+2)*23+11)%13 << " ";
    std::cout << "\n";
    std::cout << "current max: " << list.get_max() << "\n";

    return 0;
}
