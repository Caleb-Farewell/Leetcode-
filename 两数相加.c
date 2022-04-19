#include <stdio.h>
#include <string.h>
// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *add(struct ListNode *p1, struct ListNode *p2, int *b)
{
    struct ListNode *pp = NULL;
    int a;
    a = p1->val + p2->val + *b;
    if (a >= 10)
    {
        a = a % 10;
        *b = 1;
    }
    else
    {
        *b = 0;
    }
    pp = (struct ListNode *)malloc(sizeof(struct ListNode));
    pp->val = a;
    pp->next = NULL;
    return pp;
}

void add_a(struct ListNode **p, struct ListNode **q, int *b)
{
    int a = 0;
    a = (*p)->val + *b;
    if (a >= 10)
    {
        a = a % 10;
        *b = 1;
    }
    else
        *b = 0;
    (*p)->val = a;
    (*q)->next = (*p);
    (*q) = (*p);
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{

    struct ListNode *p, *q = NULL;
    int b = 0;
    p = add(l1, l2, &b);
    q = p;
    struct ListNode *pl1 = l1->next;
    struct ListNode *pl2 = l2->next;
    while (pl1 && pl2)
    {
        struct ListNode *h = add(pl1, pl2, &b);
        q->next = h;
        q = h;
        pl1 = pl1->next;
        pl2 = pl2->next;
    }
    while (pl1)
    {
        add_a(&pl1, &q, &b);
        pl1 = pl1->next;
    }
    while (pl2)
    {
        add_a(&pl2, &q, &b);
        pl2 = pl2->next;
    }
    if (b)
    {
        struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val = b;
        p->next = NULL;
        q->next = p;
        q = p;
    }
    return p;
}