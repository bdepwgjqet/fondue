#include <cstdio>
#include <list>
#include <unordered_map>

using namespace std;

struct node {
    int key;
    int value;
    node(){}
    node(int key, int value):key(key),value(value){}
};

class LRUCache{
public:
    list<node> dlist;
    unordered_map<int, list<node>::iterator> hmap;
    int size;

    LRUCache(int capacity) {
        size = capacity;
        hmap.clear();
        dlist.clear();
    }
    
    int get(int key) {
        if (hmap.count(key) <= 0) {
            return -1;
        }
        dlist.splice(dlist.begin(),dlist,hmap[key]);
        hmap[key] = dlist.begin();
        return hmap[key]->value;
    }
    
    void set(int key, int value) {
        if (hmap.count(key) <= 0) {
            if (dlist.size() == size) {
                hmap.erase(dlist.back().key);
                dlist.pop_back();
            }
            dlist.push_front(node(key,value));
            hmap[key] = dlist.begin();
            return;
        }
        hmap[key]->value = value;
        dlist.splice(dlist.begin(),dlist,hmap[key]);
        hmap[key] = dlist.begin();
    }
};

int main() {
    return 0;
}
