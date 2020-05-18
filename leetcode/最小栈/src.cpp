#include <stdio.h>
#include <list>
#include <stack>
using namespace std;

// �����֮ǰ�������������ˣ���һ�뷨�����Ǵ浽һ��������
// �㷨push��pop���Ӷ�ΪO(N)��getMin���Ӷ�ΪO(1)
//class MinStack {
//public:
//    /** initialize your data structure here. */
//    MinStack() {
//
//    }
//
//    void push(int x) {
//        s.push(x);
//        
//        bool inserted = false;
//        for (auto itr = l.begin(); itr != l.end(); itr++) {
//            if(x < *itr){
//                l.insert(itr, x);
//                inserted = true;
//                break;
//            }
//        }
//
//        if (!inserted) {
//            l.push_back(x);
//        }
//    }
//
//    void pop() {
//        int value = s.top();
//        for (auto itr = l.begin(); itr != l.end(); itr++) {
//            if (*itr == value) {
//                l.erase(itr);
//                break;
//            }
//        }
//
//        s.pop();
//    }
//
//    int top() {
//        return s.top();
//    }
//
//    int getMin() {
//        return *l.begin();
//    }
//
//private:
//    stack<int> s;
//    list<int> l;
//};


// ���ŵ��ǲ��ø���ջ�ķ�ʽ��push/pop���ӶȾ�ΪO(1)
// ��Ȼ֮ǰ���������������ˣ�����������������أ�
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        s.push(x);
        if (l.empty())
            l.push(x);
        else {
            if (x <= l.top())
                l.push(x);
        }
    }

    void pop() {
        if (s.top() == l.top())
            l.pop();

        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return l.top();
    }

private:
    stack<int> s;
    stack<int> l;
};



int main() {
    MinStack minStack;
    minStack.push(512);
    minStack.push(-1024);
    minStack.push(-1024);
    minStack.push(512);
    minStack.pop();
    printf("%d\n", minStack.getMin());
    minStack.pop();
    printf("%d\n", minStack.getMin());
    minStack.pop();
    printf("%d\n", minStack.getMin());


    //MinStack minStack;
    //minStack.push(-2);
    //minStack.push(0);
    //minStack.push(-3);
    //printf("%d\n", minStack.getMin());//   -- > ���� - 3.
    //minStack.pop();
    //printf("%d\n", minStack.top());   //   -- > ���� 0.
    //printf("%d\n", minStack.getMin());//   -- > ���� - 2.

    getchar();
    return 0;
}

