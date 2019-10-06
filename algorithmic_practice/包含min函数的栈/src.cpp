#include <stdio.h>
#include <stack>
#include <list>
using namespace std;

// 搞了一个链表用来插入排序😒
class Stack {
public:
    void push(int value) {
        bool inserted = false;
        for (auto iter = l.begin(); iter != l.end(); iter++)
        {
            if (value < *iter)
            {
                l.insert(iter, value);
                inserted = true;
                break;
            }
        }

        if (!inserted)
        {
            l.push_back(value);
        }
            
        s.push(value);
    }
    void pop() {
        for (auto iter = l.begin(); iter != l.end(); iter++)
        {
            if (*iter == s.top())
            {
                l.erase(iter);
                break;
            }
        }

        s.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        int v = l.front();
        return v;
    }

    stack<int> s;
    list<int> l;
};

// 参考讨论，使用辅助栈
class Stack1 {
public:
    void push(int value) {
        if (l.empty())
        {
            l.push(value);
        }
        else
        {
            if (value <= l.top())
            {
                l.push(value);
            }
        }
       
        s.push(value);
    }
    void pop() {
        if (s.top() == l.top())
        {
            l.pop();
        }

        s.pop();
    }

    int top() {
        return s.top();
    }
    int min() {
        return l.top();
    }

    stack<int> s;
    stack<int> l;
};

int main()
{
    Stack s;
    s.push(3);
    printf("%d\n", s.min());
    s.push(4);
    printf("%d\n", s.min());
    s.push(2);
    printf("%d\n", s.min());
    s.push(3);
    printf("%d\n", s.min());
    s.pop();
    printf("%d\n", s.min());
    s.pop();
    printf("%d\n", s.min());
    s.pop();
    printf("%d\n", s.min());
    s.push(0);
    printf("%d\n", s.min());
    getchar();
    return 0;
}