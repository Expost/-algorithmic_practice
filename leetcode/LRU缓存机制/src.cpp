#include <stdio.h>
#include <list>
#include <unordered_map>

using namespace std;


// ��ʵ�֣�����O(1)���Ӷ�
class LRUCache {
public:
    LRUCache(int capacity):max_count(capacity){

    }

    int get(int key) {
        int value = -1;
        for (auto itr = l.begin(); itr != l.end(); itr++) {
            if (itr->first == key) {
                value = itr->second;
                l.erase(itr);
                break;
            }
        }

        if (value != -1)
            l.push_front({ key, value });

        return value;
    }

    void put(int key, int value) {
        if (l.size() == max_count) {
            int count = 0;
            for (auto itr = l.begin(); itr != l.end(); itr++, count++) {
                if (itr->first == key) {
                    l.erase(itr);
                    break;
                }

                if (count == l.size() - 1) {
                    l.erase(itr);
                    break;
                }
            }
        }
        
        l.push_front({ key, value });
    }

private:
    int max_count;
    std::list<pair<int, int>> l;
};


int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    printf("%d\n", cache.get(1));       // ����  1
    cache.put(3, 3);                    // �ò�����ʹ����Կ 2 ����
    printf("%d\n", cache.get(2));       // ����  1
    cache.put(4, 4);                    // �ò�����ʹ����Կ 1 ����
    printf("%d\n", cache.get(1));       // ����  1
    printf("%d\n", cache.get(3));       // ����  1
    printf("%d\n", cache.get(4));       // ����  1


    getchar();
    return 0;
}