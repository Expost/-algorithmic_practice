#include <stdio.h>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {

    }

    void pop() {

    }

    int top() {

    }

    int getMin() {

    }
};



int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    printf("%d\n", minStack.getMin());//   -- > ���� - 3.
    minStack.pop();
    minStack.top();   //   -- > ���� 0.
    printf("%d\n", minStack.getMin());//   -- > ���� - 2.

    getchar();
    return 0;
}

