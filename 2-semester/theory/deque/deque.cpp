struct deque
{
	private:
		struct node
		{
		int data;
		node *next;

		node(int i, node *n = NULL) : data(i), next(n) {}
		};

		int size;
		node *first;
		node *last;

	public:
		deque();
		~deque();

		int head() const;
		int tail() const;

		void push_front(int k);
		void push_back(int k);

		int pop_front();
		int pop_back();

		int getSize();
		void print();

}; 