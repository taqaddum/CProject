/**
 ******************************************************************************
 * @file           : main.cpp
 * @author         : jhZou
 * @brief          : 测试二叉树创建方法
 * @attention      : 二叉树节点值为整型
 * @date           : 2023/2/11
 ******************************************************************************
 */
#include <iostream>
#include <cstring>
#include <queue>
#include "btree_algorithm.h"

using std::cout;
using std::endl;
using std::max;
using std::queue;

// 先序遍历
inline int preOrderTravel(BTNode *ptr)
{
    if (ptr != nullptr)
    {
        cout << char(ptr->val);
        preOrderTravel(ptr->left);
        preOrderTravel(ptr->right);
    }
    return 0;
}

// 中序遍历
inline int inOrderTravel(BTNode *ptr)
{
    if (ptr != nullptr)
    {
        inOrderTravel(ptr->left);
        cout << char(ptr->val);
        inOrderTravel(ptr->right);
    }
    return 0;
}

// 后序遍历
inline int postOrderTravel(BTNode *ptr)
{
    if (ptr != nullptr)
    {
        postOrderTravel(ptr->left);
        postOrderTravel(ptr->right);
        cout << char(ptr->val);
    }
    return 0;
}

inline int removeBTree(BTNode *ptr)
{
    if (ptr != nullptr)
    {
        removeBTree(ptr->left);
        removeBTree(ptr->right);
        cout << "清理当前节点:" << char(ptr->val) << endl;
        delete ptr;
    }
    return 0;
}

inline int maxSumPath(BTNode *ptr)
{
    if (!ptr)
        return 0;
    int left = maxSumPath(ptr->left);
    int right = maxSumPath(ptr->right);
    return max(left, right) + ptr->val;
}

inline int maxDepth(BTNode *ptr)
{
    if (!ptr)
        return 0;
    int left = maxDepth(ptr->left) + 1;
    int right = maxDepth(ptr->right) + 1;
    return left > right ? left : right;
}

inline int countNode(BTNode *root)
{
    if (!root)
        return 0;
    int left = countNode(root->left);
    int right = countNode(root->right);
    return left + right + 1;
}

inline int diameterBTree(BTNode *root)
{
    static int max_diameter = 0;
    auto maxDepth = [](auto &&self, BTNode *ptr) {
        if (!ptr)
            return 0;
        int left = self(self, ptr->left);
        int right = self(self, ptr->right);
        max_diameter = max(max_diameter, left + right);
        return 1 + max(left, right);
    };
    return maxDepth(maxDepth, root);
}

inline void levelTraversal(BTNode *root)
{
    queue<BTNode *> q;
    q.push(root);
    while (!q.empty())
    {
        unsigned int length = q.size();
        for (int i = 0; i < length; i++)
        {
            auto x = q.front();
            q.pop();
            if (x->left)
                q.push(x->left);
            if (x->right)
                q.push(x->right);
            cout<<char (x->val)<<' ';
        }
        cout<<endl;
    }
}

BTNode *swapBTreeLR(BTNode *root)
{
    if (!root)
        return nullptr;
    auto left = swapBTreeLR(root->left);
    auto right = swapBTreeLR(root->right);
    root->left = right, root->right = left;
    return root;
}

void flattenBTree(BTNode *root){
    if(!root) return;
    flattenBTree(root->left);
    flattenBTree(root->right);
    BTNode *lt = root->left, *lr = root->right, *head = root;
    root->left = nullptr;
    root->right = lt;
    while(head->right) head = head->right;
    head->right = lr;
}

BTNode *maxvalBTree(int *arr, int low, int high)
{
    if (low > high)
        return nullptr;
    int maxval = INT16_MIN, idx = -1;
    for (int i = 0; i <= high - low; i++)
    {
        if (arr[i] > maxval)
        {
            maxval = arr[i];
            idx = i;
        }
    }
    auto node = new BTNode{maxval, nullptr, nullptr};
    node->left = maxvalBTree(arr, low, idx - 1);
    node->right = maxvalBTree(arr, idx + 1, high);
    return node;
}

int main(int argc, char **argv)
{
    using std::cin;
    using std::strlen;

    char preorder[8] = "abdegcf";
    char inorder[8] = "dbgeacf";
    unsigned int length = strlen(preorder) - 1;

    BTNode *node = createBTree(preorder, preorder + length, inorder, inorder + length);
    preOrderTravel(swapBTreeLR(node));
    cout<<endl;
    levelTraversal(node);
    cout << "二叉树直径为：" << diameterBTree(node) << endl;
    cout << "节点数为：" << countNode(node) << endl;

    cout << "先序遍历：";
    preOrderTravel(node);

    cout << endl << "中序遍历：";
    inOrderTravel(node);

    cout << endl << "后序遍历：";
    postOrderTravel(node);

    cout << endl << "最大路径和：" << maxSumPath(node);
    cout << endl << "最大深度：" << maxDepth(node);

    cin.get();
    removeBTree(node);
    return 0;
}
