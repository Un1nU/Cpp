#include <iostream>
#include <vector>

using namespace std;

class DpTreeNode
{
public:
    int val;
    DpTreeNode* left;
    DpTreeNode* right;
    DpTreeNode* parent;
    DpTreeNode(int x): val(x), left(nullptr), right(nullptr), parent(nullptr) {}
};

DpTreeNode* recurBuild(
    vector<int>::iterator inStart, vector<int>::iterator inEnd,
    vector<int>::iterator postStart, vector<int>::iterator postEnd)
{
    if (inStart == inEnd) return nullptr;

    DpTreeNode* root = new DpTreeNode(*(postEnd-1));

    auto inorderRoot = inStart;
    while(inorderRoot < inEnd && (*inorderRoot) != (root->val))
    {
        inorderRoot++;
    }

    cout << *inorderRoot;
    if (inorderRoot == inEnd || (*inorderRoot) != (root->val))  throw -1;

    root->left = recurBuild(inStart, inorderRoot, postStart, postStart+(inorderRoot-inStart)+1);
    root->right = recurBuild(inorderRoot+1, inEnd, postStart+(inorderRoot-inStart)+1, postEnd-1);

    return root;
}

DpTreeNode* buildDpTree(vector<int> inorder, vector<int> postorder)
{
    return recurBuild(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
}

void preorderTraverse(DpTreeNode* root)
{
    if (!root) return;

    cout << root->val << " ";
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}

/*
    画出所有可能的情况
         A
      /   \
     B     C
   / \      \
  D   E     H
    /      / \
   F      I  J
   \
    G

分类：
 1. A,B,C,F,H : 结点 '有右儿子'，下一结点就是其右儿子的 '最左' 儿子，如果右儿子没有左儿子，则为其本身
 2. D,I : 为父结点的 '左儿子' 且 '没有右儿子'，下一结点就是其父结点
 3. E,G : 为父结点的 '右儿子' 且 '没有右儿子'，下一结点为其祖先结点并且祖先结点为其父亲结点的左儿子，与2可以归为一类
 4. J:  最尾结点，没有下一结点
*/

DpTreeNode* theNextNode(DpTreeNode* pNode)   
{
    if (!pNode) return nullptr;
    
    if (pNode->right) // 第1类
    {
        pNode = pNode->right;
        while(pNode->left)
            pNode = pNode->left;
        
        return pNode;
    }

    while (pNode->parent) // 第2 3类
    {
        DpTreeNode* root = pNode->parent;

        if (root->left == pNode)
            return root;
        
        pNode = pNode->parent;
    }

    return nullptr; // 第 4 类
}

int main()
{
    int len;
    cin >> len;

    vector<int> inorder(len);
    vector<int> postorder(len);

    for (int i = 0; i < len ; i++)
        cin >> inorder[i];
    cout << endl;

    for (int i = 0; i < len ; i++)
        cin >> postorder[i];
    cout << endl;

    DpTreeNode* root = buildDpTree(inorder, postorder);

    

    return 0;
}