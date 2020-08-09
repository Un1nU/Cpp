#include <map>
#include <list>
using namespace std;

struct LinkNode // 
{
    int val, key;
    LinkNode* prev;
    LinkNode* next;
    LinkNode(): key(0), val(0), prev(nullptr), next(nullptr) {}
    LinkNode(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
};

class DoubleLink
{
private:
    LinkNode* head;
    LinkNode* tail;
    int size;

public:
    DoubleLink()
    {
        head = new LinkNode();
        tail = new LinkNode();
        size = 0;
        head->next = tail;
        tail->prev = head;
    }

    ~DoubleLink()
    {
        delete head;
        delete tail;
    }

    bool insertLast(LinkNode* node) // 
    {
        if (!node) return false;

        node->next = tail;
        node->prev = tail->prev;

        tail->prev->next = node;
        tail->prev = node;
        size++;

        return true;
    }

    bool removeNode(LinkNode* node)
    {
        if (!node) return false;

        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->prev = node->next = nullptr;
        size--;

        return true;
    }

    LinkNode* removeFirst()
    {
        LinkNode* removeNode = head->next;
        if (removeNode == tail) return nullptr;
        
        removeNode->next->prev = head;
        head->next = removeNode->next;
        size--;

        return removeNode;
    }

    int getSize() {  return size; }
};

class lru
{
private:
    int capacity;
    DoubleLink* cache; // 存储 value
    map<int, LinkNode*> mp; // 根据 key 查找 value

public:
    lru(int cap)
    {
        cache = new DoubleLink();
        capacity = cap;
    }

    int get(int key)
    {
        auto nodeIter = mp.find(key); 
        if (nodeIter == mp.end()) return -1;

        LinkNode* node = nodeIter->second;
        cache->removeNode(node);
        cache->insertLast(node);

        return node->val; 
    }

    int put(int key, int value)
    {
        auto nodeIter = mp.find(key); 
        if (nodeIter != mp.end())
        {
            nodeIter->second->val = value;  
            cache->removeNode(nodeIter->second);
            cache->insertLast(nodeIter->second);
        }
        else
        {
            int size = cache->getSize();
            if (size >= capacity)
            {
                LinkNode* firstNode = cache->removeFirst();
                mp.erase(firstNode->key);
                delete firstNode;
            }

            LinkNode* node = new LinkNode(key, value);
            cache->insertLast(node);
            mp.insert(make_pair(key, node));
            
        }
    }
};
