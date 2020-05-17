#include <stdio.h>
#include <list>
#include <unordered_map>

using namespace std;


// 先实现，不管O(1)复杂度，超出时间限制
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
        // 没找到直接返回-1
        if (map.find(key) == map.end()) {
            return -1;
        }

        // 找到值并删除该节点
        int value = map[key]->second;
        l.erase(map[key]);

        // 在头部重新插入该节点，并更新map中该key对应的节点
        l.push_front({ key, value });
        map[key] = l.begin();

        return value;
    }

    void put(int key, int value) {
        // 如果找到key，那么删除节点，并放到链表头
        if (map.find(key) != map.end()) {
            l.erase(map[key]);
            l.push_front({ key, value });
        }
        // 没有找到key
        else {
            // 且链表已经是最大长度，那么删除链表尾部的节点
            // 同时记得删除map中该key对应的节点
            if (l.size() == max_count) {
                auto itr = l.back();
                map.erase(itr.first);
                l.pop_back();
            }

            // 在链表头添加节点
            l.push_front({ key, value });
        }

        // 更新map中该key对应的节点
        map[key] = l.begin();
    }

private:
    int max_count;
    // pair<int,int> -> (key, value)
    list<pair<int, int>> l;
    // map<int, node> -> (key, node)，迭代器即为节点
    unordered_map<int, list<pair<int, int>>::iterator> map;
};

int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    printf("%d\n", cache.get(1));       // 返回  1
    cache.put(3, 3);                    // 该操作会使得密钥 2 作废
    printf("%d\n", cache.get(2));       // 返回  1
    cache.put(4, 4);                    // 该操作会使得密钥 1 作废
    printf("%d\n", cache.get(1));       // 返回  1
    printf("%d\n", cache.get(3));       // 返回  1
    printf("%d\n", cache.get(4));       // 返回  1


    getchar();
    return 0;
}