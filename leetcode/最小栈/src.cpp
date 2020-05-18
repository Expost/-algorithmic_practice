#include <stdio.h>
#include <list>
#include <stack>
using namespace std;

// 这道题之前做过，但又忘了，第一想法依旧是存到一个链表中
// 算法push、pop复杂度为O(N)，getMin复杂度为O(1)
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


// 更优的是采用辅助栈的方式，push/pop复杂度均为O(1)
// 虽然之前做过，但依旧忘了，那做题的意义在哪呢？
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
    //printf("%d\n", minStack.getMin());//   -- > 返回 - 3.
    //minStack.pop();
    //printf("%d\n", minStack.top());   //   -- > 返回 0.
    //printf("%d\n", minStack.getMin());//   -- > 返回 - 2.

    getchar();
    return 0;
}

