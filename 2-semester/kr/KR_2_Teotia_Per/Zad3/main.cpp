#include <queue>
#include <vector>

class AVL
{
	...
	struct node
	{
		DataType data;
		node* left;
		node* right;
		int balance;
	};
public:
	...
	AVL() { ...; } // конструктор
	void add(DataType elem); // добавляет в дерево элемент по правилам АВЛ-дерева
	bool find(DataType elem); // возвращает true, если элемент есть в дереве

	std::vector <DataType> bfs() // кидает все элементы в вектор и возвращает его
	{
		std::vector <DataType> res;
		std::queue <node*> Q;
		Q.push(*root); // верхний элемент в дереве
		while (!Q.empty())
		{
			node cur = Q.front();
			Q.pop();
			res.push_back(cur.data);
			if (cur.left != nullptr)
			{
				Q.push(*cur.left);
			}
			if (cur.right != nullptr)
			{
				Q.push(*cur.right);
			}
		}
		return res;
	}

	AVL &operator = (const AVL& A) { ...; } // перегрузка оператора равно



	friend class set;
};

class set
{
	AVL data;
public:
	set()
	{
		data = AVL();
	}

	std::vector <DataType> elements{ return data.bfs(); }

	void add(DataType elem)
	{
		data.add(elem);
	}

	set& operator = (const set& A)
	{
		data = AVL();
		std::vector <DataType> elements = A.elements();
		for (auto elem : elements)
			data.add(elem);
		return * this;
	}

	bool find(DataType elem) { return data.find(elem); } // проверять вхождение элемента в множество
};

friend set merge(set A, set B)
{
	set res = A;
	std::vector <DataType> elements = B.elements();
	for (auto elem : elements) // добавляем в res элементы из B, которых нет в A
		if (!A.find(elem))
			res.add(elem);
	return res;
}

friend set intersect(set A, set B)
{
	std::vector <DataType> elements = A.elements();
	set res = set();
	for (auto elem : elements) // добавляем в res все элементы, которые есть и в A, и в B
		if (B.find(elem))
			res.add(elem);
	return res;
}
