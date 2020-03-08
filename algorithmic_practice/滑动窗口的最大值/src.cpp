#include <stdio.h>
#include <vector>
#include <list>
#include <deque>
using namespace std;

static const int kCount = 2;
void insert_list(list<int> &l, int v) {
    bool inserted = false;
    int i = 0;
    for (auto itr = l.begin(); itr != l.end() && i < kCount;itr++, i++) {
        if (v > *itr) {
            l.insert(itr, v);
            inserted = true;

            break;
        }
    }

    if (!inserted) {
        l.push_back(v);
    }
}

void remove_list(list<int> &l, int v) {
    int i = 0;
    for (auto itr = l.begin();itr != l.end() && i < kCount;itr++, i++) {
        if (v == *itr) {
            l.erase(itr);
            break;
        }
    }
}

vector<int> maxInWindows_1(const vector<int>& num, unsigned int size)
{
    vector<int> v;
    list<int> l;
    if (num.empty() || size == 0 || size > num.size()) {
        return v;
    }
    
    for (int i = 0; i < num.size(); i++) {
        if (i < size) {
            insert_list(l, num[i]);

            if (i == size - 1) {
                v.push_back(l.front());
            }
        }
        else {
            int left = num[i - size];
            int right = num[i];
            remove_list(l, left);
            insert_list(l, right);

            v.push_back(l.front());
        }
    }

    return v;
}

// �ο����ۣ�һ��ʹ�ö���ʵ�֣�Ҫ��ʹ������򵥶࣬�ο�ʵ������
// �� <=====> С
vector<int> maxInWindows_2(const vector<int>& num, unsigned int size) {
    vector<int> v;
    deque<int> d; // d�洢λ��
    for (int i = 0; i < num.size();i++) {
        while (d.size() && num[d.back()] <= num[i]) {
            d.pop_back();
        }
        while (d.size() && i - d.front() + 1 > size) {
            d.pop_front();
        }

        d.push_back(i);
        if (size && i + 1 >= size) {
            v.push_back(num[d.front()]);
        }
    }

    return v;
}

// d�洢ֵ�����ף����Ǵ�λ�ÿ���
vector<int> maxInWindows_3(const vector<int>& num, unsigned int size) {
    vector<int> v;
    deque<int> d;   // d�洢ֵ
    for (int i = 0; i < num.size();i++) {
        while (d.size() && d.back() < num[i]) {
            d.pop_back();
        }
        if (d.size() && i >= size && d.front() == num[i - size]) {
            d.pop_front();
        }

        d.push_back(num[i]);
        if (size && i + 1 >= size) {
            v.push_back(d.front());
        }
    }

    return v;
}

// vector<int> v = { 1,1,10,10,10,1,1,1,1,1 };
// ����������£�ֻ�г���2�Ľ���ǶԵģ�1�Ǵ�ģ�3����Ҳ�Ǵ�ģ����Ķ���
// �ܵ���˵��������2�ķ�ʽ���洢λ�ñȽϿ��ף���ֵ�����ף�����ţ�͵��������������
// �Ѿ����ҷ������δ�����
int main() {
    //vector<int> v = { 2,3,4,3,2,2,5,1 };
    //vector<int> v = { 1,3,-1,-3,5,3,6,7 };
    vector<int> v = { 1,1,10,10,10,1,1,1,1,1 };
    //vector<int> v = { 16,14,12,10,8,6,4 };
    auto ret = maxInWindows_2(v, 3);
    for (auto &itr : ret) {
        printf("%d ", itr);
    }

    getchar();
    return 0;
}