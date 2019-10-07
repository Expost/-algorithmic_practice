#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

// 阴差阳错写出来了😂
bool IsPopOrder(vector<int> pushV, vector<int> popV) 
{
    stack<int> s;
    int i = 0;
    for (auto &itr : pushV)
    {
        s.push(itr);

        while (i < popV.size() && s.top() == popV[i])
        {
            s.pop();
            i++;
        }
    }

    return s.empty();
}

int main()
{
    vector<int> v1 = { 1,2,3,4,5 };
    vector<int> v2 = { 4,5,3,2,1 };
    vector<int> v3 = { 4,3,5,1,2 };
    vector<int> v4 = { 5,4,3,2,1 };
    printf("%d\n", IsPopOrder(v1, v4));

    getchar();
    return 0;
}