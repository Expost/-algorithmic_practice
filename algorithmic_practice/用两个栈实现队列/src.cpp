#include <stdio.h>
#include <stack>

using namespace std;

stack<int> stack1;  // ����push
stack<int> stack2;  // ����pop

// ע������Ķ������Ƚ��ȳ�����


// �����Լ���ʵ�֣����Ӷ�̫�ߣ���ȫû��Ҫ��ô�鷳
//void push(int node) 
//{
//    if (stack1.empty() && !stack2.empty())
//    {
//        int count = stack2.size();
//        for (int i = 0; i < count; i++)
//        {
//            int value = stack2.top();
//            stack1.push(value);
//            stack2.pop();
//        }
//    }
//
//    stack1.push(node);
//}
//
//int pop() 
//{
//    if (stack2.empty() && !stack1.empty())
//    {
//        int count = stack1.size();
//        for (int i = 0; i < count; i++)
//        {
//            int value = stack1.top();
//            stack2.push(value);
//            stack1.pop();
//        }
//    }
//
//    int value = stack2.top();
//    stack2.pop();
//    return value;
//}


// ���˵�ʵ�֣����Ӷ�Ҫ�ͺܶ�
void push(int node) {
    stack1.push(node);
}

int pop() {
    int a = 0;
    if (stack2.empty()) {
        while (!stack1.empty()) {
            a = stack1.top();
            stack2.push(a);
            stack1.pop();
        }
    }

    a = stack2.top();
    stack2.pop();
    return a;
}


int main()
{
    //for (int i = 0; i < 7; i++)
    //{
    //    push(i);
    //}

    //for (int i = 0; i < 7; i++)
    //{
    //    int value = pop();
    //    printf("value is %d\n", value);
    //}

    int value = 0;
    push(1);
    push(2);
    push(3);
    value = pop();
    printf("value is %d\n", value);
    value = pop();
    printf("value is %d\n", value);
    push(4);
    push(5);
    value = pop();
    printf("value is %d\n", value);
    value = pop();
    printf("value is %d\n", value);
    value = pop();
    printf("value is %d\n", value);

    getchar();
    return 0;
}