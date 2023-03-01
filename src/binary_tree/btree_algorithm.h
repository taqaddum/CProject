/**
 ******************************************************************************
 * @file           : btree_algorithm.h
 * @author         : jhZou
 * @brief          : 以前序序列，中序序列创建二叉树
 * @attention      : None
 * @date           : 2023/2/11
 ******************************************************************************
 */

#ifndef COFFER_BTREE_ALGORITHM_H
#define COFFER_BTREE_ALGORITHM_H

struct BTNode
{
    int val;
    BTNode *left, *right;
};

struct PBTNode
{
    int val;
    PBTNode *parent, *left, *right;
};

template <typename T>
BTNode *createBTree(T *preorder, T *preorder_end, T *inorder, T *inorder_end)
{
    auto *root = new BTNode{*preorder, nullptr, nullptr};
    if (preorder > preorder_end)
    {
        root = nullptr;
    }
    else
    {
        int left_length = 0;
        T *root_inorder = inorder;
        while (*preorder != *root_inorder)
            root_inorder++;

        left_length = root_inorder - inorder;
        root->left = createBTree(preorder + 1, preorder + left_length, inorder, root_inorder - 1);
        root->right = createBTree(preorder + left_length + 1, preorder_end, root_inorder + 1, inorder_end);
    }
    return root;
}

//中序遍历中的下一个节点
PBTNode *inorderNext(PBTNode *ptr)
{
    if (!ptr)
        exit(EXIT_FAILURE);
    PBTNode *next = nullptr;
    if (ptr->right)
    {
        next = ptr->right;
        while (next->left)
        {
            next = next->left;
        }
    }
    else if (ptr->parent)
    {
        next = ptr->parent;
        while (ptr->parent->right == ptr)
        {
            next = next->parent;
            ptr = ptr->parent;
        }
    }
    return next;
}

#endif // COFFER_BTREE_ALGORITHM_H
