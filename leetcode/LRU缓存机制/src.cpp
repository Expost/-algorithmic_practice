#include <stdio.h>
#include <list>
#include <unordered_map>

using namespace std;


// ��ʵ�֣�����O(1)���Ӷȣ�����ʱ������
//class LRUCache {
//public:
//    LRUCache(int capacity):max_count(capacity){
//
//    }
//
//    int get(int key) {
//        int value = -1;
//        for (auto itr = l.begin(); itr != l.end(); itr++) {
//            if (itr->first == key) {
//                value = itr->second;
//                l.erase(itr);
//                break;
//            }
//        }
//
//        if (value != -1)
//            l.push_front({ key, value });
//
//        return value;
//    }
//
//    void put(int key, int value) {
//        int count = 0;
//        for (auto itr = l.begin(); itr != l.end(); itr++, count++) {
//            if (itr->first == key) {
//                l.erase(itr);
//                break;
//            }
//            if (l.size() == max_count && count == l.size() - 1) {
//                l.erase(itr);
//                break;
//            }
//        }
//        
//        l.push_front({ key, value });
//    }
//
//private:
//    int max_count;
//    std::list<pair<int, int>> l;
//};


class LRUCache {
public:
    LRUCache(int capacity) :max_count(capacity) {}

    int get(int key) {
        // û�ҵ�ֱ�ӷ���-1
        if (map.find(key) == map.end()) {
            return -1;
        }

        // �ҵ�ֵ��ɾ���ýڵ�
        int value = map[key]->second;
        l.erase(map[key]);

        // ��ͷ�����²���ýڵ㣬������map�и�key��Ӧ�Ľڵ�
        l.push_front({ key, value });
        map[key] = l.begin();

        return value;
    }

    void put(int key, int value) {
        // ����ҵ�key����ôɾ���ڵ㣬���ŵ�����ͷ
        if (map.find(key) != map.end()) {
            l.erase(map[key]);
            l.push_front({ key, value });
        }
        // û���ҵ�key
        else {
            // �������Ѿ�����󳤶ȣ���ôɾ������β���Ľڵ�
            // ͬʱ�ǵ�ɾ��map�и�key��Ӧ�Ľڵ�
            if (l.size() == max_count) {
                auto itr = l.back();
                map.erase(itr.first);
                l.pop_back();
            }

            // ������ͷ��ӽڵ�
            l.push_front({ key, value });
        }

        // ����map�и�key��Ӧ�Ľڵ�
        map[key] = l.begin();
    }

private:
    int max_count;
    // pair<int,int> -> (key, value)
    list<pair<int, int>> l;
    // map<int, node> -> (key, node)����������Ϊ�ڵ�
    unordered_map<int, list<pair<int, int>>::iterator> map;
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