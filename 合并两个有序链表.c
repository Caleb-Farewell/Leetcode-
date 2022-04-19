#include <stdio.h>
#include <string.h>
// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *NList, *p1, *p2, *pc = NULL;
    p1 = list1;
    p2 = list2;
    NList = (struct ListNode *)malloc(sizeof(struct ListNode));
    pc = NList;
    while (p1 && p2)
    {
        if ((p1->val) <= (p2->val))
        {
            pc->next = p1;
            pc = p1;
            p1 = p1->next;
        }
        else
        {
            pc->next = p2;
            pc = p2;
            p2 = p2->next;
        }
    }
    pc->next  = p1?p1:p2;
    return NList;
}