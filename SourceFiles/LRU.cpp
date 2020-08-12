#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

struct LinkNode
{
    int val, key;
    LinkNode* prev;
    LinkNode* next;
    LinkNode(): key(0), val(0), prev(nullptr), next(nullptr) {}
    LinkNode(int k, int x): key(k), val(x), prev(nullptr), next(nullptr) {}
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
        head->next = tail;
        tail->prev = head;
        size = 0;
    }   
    ~DoubleLink() 
    {
        delete head;
        delete tail;
    }

    bool insertLast(LinkNode* node)
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
        node->next = nullptr;
        node->prev = nullptr;
        size--;
    
        return true;
    }

    LinkNode* removeFirst()
    {
        LinkNode* removeNode = head->next;
        removeNode->next->prev = head;
        head->next = removeNode->next;
        size--;

        return removeNode;
    }
    
    int getSize()
    {
        return size;
    }
};

class LRUCache 
{
private:
    unordered_map<int, LinkNode*> mp; // 哈希表，存储 (key, LinkNode*) 对
    DoubleLink* cache;
    int capacity;

public:
    LRUCache(int capacity) 
    {
        cache = new DoubleLink();
        this->capacity = capacity;
    }
    
    int get(int key) 
    {
        auto nodeIter = mp.find(key);
        if (nodeIter == mp.end()) return -1;

        LinkNode* node = nodeIter->second;
        cache->removeNode(node);
        cache->insertLast(node);

    }
    
    void put(int key, int value) 
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
            if (size + 1 > capacity) // 如果添加结点超过了 LRU 的容量，则删除最少使用结点
            {
                LinkNode* node = cache->removeFirst();
                mp.erase(node->key); // LinkNode 中需要包含 key 的原因
                delete node;
            }
            
            LinkNode* newNode = new LinkNode(key, value);
            cache->insertLast(newNode);
            mp[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */