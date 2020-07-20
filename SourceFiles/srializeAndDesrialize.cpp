#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        if (!root) return "[]";
        string seq("[");
        queue<TreeNode*> nodes;
        nodes.push(root);

        /* 小bug，序列尾部会多出null，如下面的树
                  1
                / \
               2   3
                  / \
                 4   5 
            会序列化为 [1, 2, 3, null, null, 4, 5, null, null, null, null]
            应该序列化为 [1, 2, 3, null, null, 4, 5]
        */
        while (!nodes.empty())
        {
            root = nodes.front();
            nodes.pop();

            if (root)
            {
                seq += root->val + '0' + ',';
                nodes.push(root->left);
                nodes.push(root->right);
            } 
            else 
            {
                seq += "null,";
            }
        }

        seq[seq.length()-1] = ']'; 

        return seq;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if (data.empty()) return nullptr;
        // for (auto item : data) 不能改变item的内容？
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == ',' || data[i] == '[' || data[i] == ']')
                data[i] = ' ';
        }

        istringstream iss(data);
        string val;
        vector<TreeNode*> nodes;

        while (iss >> val)
        {
            if (val == "null")
                nodes.push_back(nullptr);
            else
                nodes.push_back(new TreeNode(stoi(val)));
        }

        for (int i = 0, j = 1; j < nodes.size(); i++)
        {
            if (nodes[i] == nullptr) continue;

            if (j < nodes.size()) nodes[i]->left = nodes[j++];
            if (j < nodes.size()) nodes[i]->right = nodes[j++];
        }

    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));