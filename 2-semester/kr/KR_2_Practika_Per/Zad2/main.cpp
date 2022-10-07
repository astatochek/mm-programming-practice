#include <queue>
#include <functional>


struct node
{
	DataType data;
	node* next = 0;
	node* prev = 0;
};


class cycle_list
{
	node* first;
	size_t size;
	...
	friend class list_iterator;
};

friend class list_iterator
{
	std::queue <node*> Q;
	bool begin = 0;
	node* first;
public:
	list_iterator(cycle_list& A)
	{
		Q.push(A->first);
		begin = 1;
		first = A.first;
	}

	bool begin() { return begin; }

	bool end() { return Q.empty(); }

	DataType& operator*() { return Q.front()->data; }

	list_iterator& opeartor++()
	{
		if (begin)
			begin = 0;
		node* temp = Q.front();
		Q.pop();
		if (temp->next != first) // определяем, что нам надо заканчивать, если следующий элемент это уже самый первый
			Q.push(temp->next);
		return this;
	}
};

void for_each(cycle_list A, Function func)
{
	for (list_iterator it(A); !it.end(); it++)
		func(*it);
}
