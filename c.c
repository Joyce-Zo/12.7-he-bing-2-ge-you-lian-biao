#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists1(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head, * tail;
    head = tail = NULL;

    if (list1 == NULL)
    {
        return list2;   //当其中一个链表为NULL，则直接返回另一个链表即可
    }
    else if (list2 == NULL)
    {
        return list1;
    }
    else
    {
        (list2->val) > (list1->val) ? (head = list1, tail = list1, list1 = list1->next) : (head = list2, tail = list2, list2 = list2->next);
            // 三目操作符，上来先给head和tail一个值，如果是l1小就把l1给head/tail
            // 否则l2
        while (list1 && list2)
        {
            if ((list1->val) > (list2->val))
            {
                tail->next = list2;
                list2 = list2->next;    // 比较大小，谁小，谁放tail的next，head不变，记录头
            }
            else
            {
                tail->next = list1;
                list1 = list1->next;
            }
            tail = tail->next;
        }
        //  最后，当一个为NULL时，退出上面循环，并将剩下的一个链表直接加入tail的next后
        if (list1 == NULL)
        {
            tail->next = list2;
        }
        else
        {
            tail->next = list1;
        }
        return head;
    }
}
struct ListNode* mergeTwoLists2(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head, * tail;
    head = tail = NULL;
    if (list1 == NULL)
    {
        return list2;
    }
    else if (list2 == NULL)
    {
        return list1;
    }
    else
    {
        
        head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
        //  直接malloc一个哨兵位头节点
        while (list1 && list2)
        {
            if ((list1->val) > (list2->val))
            {
                tail->next = list2;
                list2 = list2->next;
            }
            else
            {
                tail->next = list1;
                list1 = list1->next;
            }
            tail = tail->next;
        }
        if (list1 == NULL)
        {
            tail->next = list2;
        }
        else
        {
            tail->next = list1;
        }
        return head->next;
    }
    //  因为是malloc，所以记得释放，不过应先保存到一个指针里，再释放
    struct ListNode* list = head->next;
    free(head);
    return list;
}
int main()
{
    //  自己创建链表
    struct ListNode* newnode1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode11 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode22 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode33 = (struct ListNode*)malloc(sizeof(struct ListNode));

    //  给链表赋值
    newnode1->val = 1; newnode1->next = newnode2;
    newnode2->val = 2; newnode2->next = newnode3;
    newnode3->val = 4; newnode3->next = NULL;
    newnode11->val = 1; newnode11->next = newnode22;
    newnode22->val = 3; newnode22->next = newnode33;
    newnode33->val = 4; newnode33->next = NULL;

    //  调用链表函数
    struct ListNode* head = mergeTwoLists(newnode1,newnode11);
    return 0;
}