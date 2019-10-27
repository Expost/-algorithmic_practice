#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// �����ɵ���ˣ����˺þò�֪������ô�������뱩��ƴ����
// �������ο�������
// �Զ���һ���Ƚϴ�С�ĺ������Ƚ������ַ���s1, s2��С��ʱ���Ƚ�����ƴ���������Ƚ�s1+s2,��s2+s1�ĸ���
// ���s1+s2����˵��s2Ӧ�÷�ǰ�棬���԰��������s2��Ӧ������s1ǰ�档
bool cmp(int v1, int v2)
{
    string s1 = to_string(v1) + to_string(v2);
    string s2 = to_string(v2) + to_string(v1);
    return s1 < s2;
}

string PrintMinNumber(vector<int> numbers) 
{
    string str;
    sort(numbers.begin(), numbers.end(), cmp);
    for (auto &n : numbers)
    {
        str += to_string(n);
    }

    return str;
}

int main()
{
    vector<int> v = { 3, 32, 321 };
    string str = PrintMinNumber(v);
    printf("%s\n", str.c_str());
    
    getchar();
    return 0;
}