
class priority_queue
{
    struct node
    {
        int val;
        int prior;
        node(int v, int p)
        {
            val = v;
            prior = p;
        }
    };
    int capacity = 100;
    node data[100];
    int last_index = -1;
public:
    int prev(int i){return (i-1)/2;}
    int left(int i){return (2*i + 1);}
    int right(int i){return (2*i + 2);}
    void sift_up(int i); // аналогично первой задаче, в качестве еличины для сравнения берется priority
    void sift_down(int i); // тоже
    void insert(int val, int prior)
    {
        last_index++;
        if (last_index == capacity)
        {
            // удваиваем capacity и перезаписываем массив, на котором сидит куча
        }
        data[last_index] = node(val, prior);
        sift_up(last_index);
    }

    int get_index(int priority);// находит за логарифм элемент в куче и возвращает его индекс

    node extractMax()
    {
        node result = data[0];
        data[0] = data[last_index];
        last_index--;
        sift_down(0);
        return result;
    }

    void remove(int priority)
    {
        int index = get_index(priority);
        node tmp = data[0];
        data[0] = data[index];
        data[index] = tmp;

        extractMax();
        sift_up(index);

    }

    int size()
    {
        return last_index + 1;
    }

    node get(int i)
    {
        return data[i];
    }


};
