#include <vector>
#include <unordered_map>

using namespace std;

class Node 
{
public:
    int val;
    vector<Node*> neighbors;
    
    Node() 
    {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) 
    {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) 
    {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution 
{
private:
    unordered_map<Node*, Node*> isVisited;

public:
    Node* cloneGraph(Node* node) 
    {
        if (!node) return nullptr;

        if (isVisited.find(node) != isVisited.end())
            return isVisited[node];

        Node* cloneNode = new Node(node->val);
        isVisited[node] = cloneNode;

        for (auto& neighbor : node->neighbors)
        {
            cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
        }

        return cloneNode;
    }
};