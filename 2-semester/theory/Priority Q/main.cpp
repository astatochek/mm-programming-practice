#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

struct task
{
    std::string name;
    int priority;
    int t_in;
    int t_work;
    task(std::string name_ = "", int priority_ = 0, int t_in_ = 0, int t_work_ = 0)
    {
        name = name_;
        priority = priority_;
        t_in = t_in_;
        t_work = t_work_;
    }
};


struct b_heap
{
    std::vector<task> priority_q;

    b_heap (std::vector<task> priority_q_={})
    {
        for (int i = 0; i < priority_q_.size(); i++) priority_q.push_back(priority_q_[i]);
    }

    b_heap siftDown(int i)
    {
        while (2 * i + 1 < priority_q.size())
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int j = left;
            if ((right < priority_q.size()) &&
                (priority_q[right].priority < priority_q[left].priority))
                j = right;
            if (priority_q[i].priority <= priority_q[j].priority)
                break;
            std::swap(priority_q[i], priority_q[j]);
            i = j;
        }
        return *this;
    }

    b_heap siftUp(int i)
    {
        while (priority_q[i].priority < priority_q[(i - 1) / 2].priority)
        {
            std::swap(priority_q[i], priority_q[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
        return *this;
    }


    task extractMin()
    {
        task min = priority_q[0];
        priority_q[0] = priority_q[priority_q.size() - 1];
        priority_q.erase(priority_q.begin());
        siftDown(0);
        return min;
    }

    b_heap insert(task t)
    {

        priority_q.push_back(t);
        siftUp(priority_q.size() - 1);
        return *this;
    }
};

bool cmp(task a, task b)
{
    return a.t_in < b.t_in;
}

int main()
{
    int n;
    std::cin >> n;

    std::string s;
    int p;
    int ins;
    int work;
    task tmp;
    std::vector<task> container;

    for (int i{0}; i < n; i++)
    {
        std::cin >> s >> p >> ins >> work;
        tmp.name = s;
        tmp.priority = p;
        tmp.t_in = ins;
        tmp.t_work = work;
        container.push_back(tmp);
    }

    std::sort(container.begin(), container.end(), cmp);


    std::vector<std::pair<task, int> > result(0);
    b_heap heap;
    int current_time = 0;


    while ((container.size() > 0) || (heap.priority_q.size() > 0))
    {
        current_time++;
        if (current_time == container[0].t_in)
        {
            heap.insert(container[0]);
            container.erase(container.begin());
        }
        if (heap.priority_q.size() > 0)
        {
            heap.priority_q[0].t_work--;
            if (heap.priority_q[0].t_work == 0)
            {
                result.push_back(std::make_pair(heap.priority_q[0], current_time));
                heap.priority_q.erase(heap.priority_q.begin());
            }
        }
        for (int i = 0; i < heap.priority_q.size(); i++)
            heap.priority_q[i].priority--;
    }
    for (auto & i : result)
        std::cout << i.first.name << " " << i.second << "\n";


    return 0;
}
