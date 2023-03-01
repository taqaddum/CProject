/**
 ******************************************************************************
 * @file           : linode.h
 * @author         : jhZou
 * @brief          : None
 * @attention      : None
 * @date           : 2023/2/14
 ******************************************************************************
 */

#ifndef COFFER_LISTNODE_H
#define COFFER_LISTNODE_H
struct ListNode
{
    int data;
    ListNode *next;
};

template <typename T>
ListNode *createList(T *start, T *end)
{
    if (start > end)
        return nullptr;

    auto node = new ListNode{*start, nullptr};
    node->next = createList(start + 1, end); // start++会原地循环
    return node;
}

// FIXME:链表合并函数不能工作
//  DONE:2023-2-14 18:10
ListNode *mergeOrderNode(ListNode *la, ListNode *lb)
{
    auto node = new ListNode;
    auto head = node;

    if (!la && !lb)
        return nullptr;
    while (la && lb)
    {
        if (la->data < lb->data)
        {
            head->next = la;
            la = la->next;
        }
        else
        {
            head->next = lb;
            lb = lb->next;
        }
        head = head->next;
    }

    if (la)
        head->next = la;
    if (lb)
        head->next = lb;
    head = node->next;
    delete node;
    return head;
}

template<typename T>
ListNode *decoupleLinkList(ListNode *head, T value)
{
    auto nodea = new ListNode;
    auto nodeb = new ListNode;
    ListNode *ptra = nodea, *ptrb = nodeb;

    while (head)
    {
        if (head->data < value)
        {
            ptra->next = head;
            ptra = ptra->next;
        }
        else
        {
            ptrb->next = head;
            ptrb = ptrb->next;
        }
        auto temp = head->next;
        head->next = nullptr;
        head = temp;
    }
    ptra->next = nodeb->next;
    head = nodea->next;
    delete nodea;
    delete nodeb;
    return head;
}

ListNode *recrusiveMerge(ListNode *a, ListNode *b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    if (a->data < b->data)
    {
        a->next = recrusiveMerge(a->next, b);
        return a;
    }
    else
    {
        b->next = recrusiveMerge(a, b->next);
        return b;
    }
}

#endif // COFFER_LISTNODE_H
