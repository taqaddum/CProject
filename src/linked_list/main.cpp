/**
 ******************************************************************************
 * @file           : main.cpp
 * @author         : jhZou
 * @brief          : None
 * @attention      : None
 * @date           : 2023/2/14
 ******************************************************************************
 */
#include <iostream>
#include "listnode.h"

using std::cout;
using std::endl;
using std::printf;

/*!
 * 移除链表中的重复节点
 * @param head 待处理链表头节点
 */
inline void removeLinkDuplicate(ListNode *head){
    ListNode *slow = head, *fast = head;
    while (fast){
        if(slow->data != fast->data){
            slow->next = fast;
            slow = slow->next;
        }
        fast = fast->next;
    }
    slow->next = nullptr;
}

inline bool isPalindrome2Pointer(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    auto reverse = [](auto &&self, ListNode *head) {
        if (!(head && head->next))
            return head;
        auto res = self(self, head->next);
        head->next->next = head;
        head->next = nullptr;
        return res;
    };
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    auto res = reverse(reverse, slow);
    auto p = res;
    bool flag = true;
    while (head != slow)
    {
        if (head->data != res->data)
            flag = false;
        head = head->next;
        res = res->next;
    }
    reverse(reverse, p);
    return flag;
}

inline bool isPalindromeLink(ListNode *head)
{
    static ListNode *temp = head;
    auto check = [](auto &&self, ListNode *head) {
        if (!head)
            return true;
        bool res = self(self, head->next) && temp->data == head->data;
        temp = temp->next;
        return res;
    };
    return check(check, head);
}

inline ListNode *traversalBackwardK(ListNode *head, int k)
{
    auto p = head;
    while (k-- > 0)
    {
        p = p->next;
    }
    while (p)
    {
        p = p->next;
        head = head->next;
    }
    return head;
}

inline ListNode *findMidNode(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cout << "cycle";
        }
    }
    return slow;
}

inline ListNode *reverseNode(ListNode *head)
{
    if (!(head && head->next))
    {
        return head;
    }
    auto last = reverseNode(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
}

inline ListNode *reverseNode(ListNode *head, int n)
{
    static ListNode *successor = nullptr;
    auto reverse = [](ListNode *head, int n) {
        if (n == 1)
        {
            successor = head->next;
            return head;
        }
        auto last = reverseNode(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return last;
    };
    return reverse(head, n);
}

inline ListNode *reverseInterval(ListNode *head, int m, int n)
{
    if (m == 1)
        return reverseNode(head, n);
    head->next = reverseInterval(head->next, m - 1, n - 1);
    return head;
}

inline ListNode *iterReverseNode(ListNode *head, ListNode *end = nullptr)
{
    ListNode *pre = nullptr, *cur = head, *post = head;
    while (cur != end)
    {
        post = cur->next;
        cur->next = pre;
        pre = cur;
        cur = post;
    }
    return pre;
}

inline ListNode *reverseGroup(ListNode *head, int k)
{
    ListNode *a, *b;
    a = b = head;
    if (!head)
        return nullptr;
    for (int i = 0; i < k; i++)
    {
        if (!b)
            return head;
        b = b->next;
    }
    auto node = iterReverseNode(a, b);
    a->next = reverseGroup(b, k);
    return node;
}

int main()
{
    int a[7] = {1, 4, 5, 7, 9, 12, 13};
    int b[5] = {2, 3, 4, 6, 8};
    int c[10] = {4, 2, 6, 1, 8, 3, 7, 9, 10, 21};
    int d[4][5] = {{1, 4, 5, 7, 9}, {2, 3, 4, 6, 9}, {3, 5, 6, 7, 8}, {7, 8, 9, 11, 13}};
    char e[4] = "aba";
    int f[10] = {1,1,1,2,3,3,5,7,7,8};

    ListNode *arr[4];
    for (auto x : d)
    {
        auto dist = (x - d[0]) / 5;
        arr[dist] = createList(x, x + 4);
    }

    auto la = createList(a, a + 6);
    auto lb = createList(b, b + 4);
    auto lc = createList(c, c + 9);
    auto ld = createList(a, a + 6);
    auto le = createList(e, e + 2);
    auto lf = createList(f, f+9);
    auto traversal = [](ListNode *head) {
        while (head)
        {
            cout << head->data << ' ';
            head = head->next;
        }
        cout << endl;
    };
    removeLinkDuplicate(lf);
    traversal(lf);
    //    cout<<"是否为回文:" << isPalindrome2Pointer(le) << endl;
    cout << "是否为回文：" << isPalindrome2Pointer(le) << endl;
    cout << findMidNode(la)->data << endl;
    //    traversal(reverseNode(ld, 3));
    //    traversal(reverseInterval(ld, 2, 6));
    traversal(iterReverseNode(ld));
    auto pa = traversalBackwardK(la, 3);
    cout << pa->data << endl;

    traversal(la);
    traversal(lb);
    //    traversal(mergeOrderNode(la, lb));
    traversal(recrusiveMerge(la, lb));
    traversal(decoupleLinkList(lc, 6));

    for (int step = 1; step < 4; step = 2 * step)
    {
        for (int i = 0; i + step < 4; i += 2 * step) // i 代表两个待合并链表中的第一个
            arr[i] = recrusiveMerge(arr[i], arr[i + step]);
    }
    traversal(arr[0]);

    return 0;
}
