#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

TreeNode* recurBuild(
    vector<int>::iterator preStart, vector<int>::iterator preEnd, 
    vector<int>::iterator inStart, vector<int>::iterator inEnd)
{
    if (preStart == preEnd) return nullptr;

    TreeNode* subRoot = new TreeNode(*preStart);

    auto inorderRoot = find(inStart, inEnd, subRoot->val);
    // 等价替换，寻找中序遍历序列里面的根节点的位置
    // auto inorderRoot = inStart;
    // for (; *inorderRoot != subRoot->val && inorderRoot < inEnd; inorderRoot++);
    

    if (inorderRoot == inEnd && *inorderRoot != subRoot->val) throw -1; // 在中序序列中搜索不到根节点，说明输入序列异常

    subRoot->left = recurBuild(preStart+1, preStart+1+(inorderRoot-inStart), inStart, inorderRoot);
    subRoot->right = recurBuild(preStart+1+(inorderRoot-inStart), preEnd, inorderRoot+1, inEnd);

    return subRoot;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    return recurBuild(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
}

void preorderTraverse(TreeNode* root)
{
    if (!root) return;

    cout << root->val << " ";
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}

void inorderTraverse(TreeNode* root)
{
    if (!root) return;

    inorderTraverse(root->left);
    cout << root->val << " ";
    inorderTraverse(root->right);
}

void postorderTraverse(TreeNode* root)
{
    if (!root) return;

    postorderTraverse(root->left);
    postorderTraverse(root->right);
    cout << root->val << " ";
}

void ipreorderTraverse(TreeNode* root)
{
    if (!root) return;

    stack<TreeNode*> paths; // 存放访问的路径

    while(root)
    {
        cout << root->val << " "; // 前序时，到达结点直接访问
        paths.push(root); // 保存根节点
        root = root->left; // 向左搜索

        /*  这里的 while 判断存在两种情况：
         1. 当左边结点为空时，栈一定不空（因为上一步已经访问过根节点并且压入栈内），从历史路径中弹出一个元素，并向右搜索
         2. 当左右边结点均为空时，如果栈为空则表示访问结束；如果栈不空则继续往上弹出根节点，直到右边子树不为空，然后对该子树前序访问
        */
        while(!root && !paths.empty()) 
        {
            root = paths.top();
            paths.pop();
            root = root->right;
        }
    }
}

void iinorderTraverse(TreeNode* root)
{
    if (!root) return;

    stack<TreeNode*> paths;

    while(root)
    {
        paths.push(root);
        root = root->left;

        while(!root && !paths.empty())
        {
            root = paths.top();
            paths.pop();

            cout << root->val << " "; // 中序遍历是弹栈时才进行访问

            root = root->right;
        }
    }
}

void ipostorderTraverse(TreeNode* root) // 可以作为前中后序迭代访问的通用模板
{
    if (!root) return;

    stack<pair<TreeNode*, bool> > paths;
    paths.push(make_pair(root, false));
    bool visit;

    while (!paths.empty())
    {
        root = paths.top().first;
        visit = paths.top().second;
        paths.pop();

        if (!root) continue;

        if (visit) // 访问操作
        {
            cout << root->val << " ";
        }
        else 
        {
            paths.push(make_pair(root, true)); // 根据前中后序更改语句顺序即可
            paths.push(make_pair(root->right, false));
            paths.push(make_pair(root->left, false));
        }
        
    }

    /*while(root)
    {
        paths.push(root);
        visitTimes.push(1);
        root = root->left;

        while(!root && !paths.empty() && !visitTimes.empty())
        {
            root = paths.top();
            int times = visitTimes.top();
            visitTimes.pop();
            times++;

            if (times < 3)
            {
                visitTimes.push(times);
                root = root->right;
            }
            else
            {
                paths.pop();
                cout << root->val << " ";
            }
            
        }

    }*/
}

void layerorderTraverse(TreeNode* root)
{
    if (!root) return;
    queue<TreeNode*> paths;

    while(root)
    {
        cout << root->val << " "; // 访问操作

        if (root->left) paths.push(root->left);
        if (root->right) paths.push(root->right);
        if (paths.empty()) return;

        root = paths.front();
        paths.pop();
    }
}

int main()
{
    int len;
    cout << "Input numbers of tree nodes:" << endl;
    cin >> len;

    vector<int> preorder(len);
    vector<int> inorder(len);
    
    cout << "Input the preorder sequence of this tree:" << endl;
    for (int i = 0; i < len; i++)
        cin >> preorder[i];
    cout << endl;

    cout << "Input the inorder sequence of this tree:" << endl;
    for (int i = 0; i < len; i++)
        cin >> inorder[i];
    cout << endl;

    TreeNode* root;
    cout << "Constructing tree...." << endl;
    root = buildTree(preorder, inorder);
    cout << "Construct compeleted." << endl;
    cout << "-------------------------------" << endl;

    cout << "The recursive preorder traversal of this tree is:" << endl;
    preorderTraverse(root);
    cout << endl;

    cout << "The iterative preorder traversal of this tree is:" << endl;
    ipreorderTraverse(root);
    cout << endl;

    cout << "The recursive inorder traversal of this tree is:" << endl;
    inorderTraverse(root);
    cout << endl;

    cout << "The iterative inorder traversal of this tree is:" << endl;
    iinorderTraverse(root);
    cout << endl;

    cout << "The recursive postorder traversal of this tree is:" << endl;
    postorderTraverse(root);
    cout << endl;

    cout << "The iterative postorder traversal of this tree is:" << endl;
    ipostorderTraverse(root);
    cout << endl;

    cout << "The iterative layerorder traversal of this tree is:" << endl;
    layerorderTraverse(root);
    cout << endl;
}