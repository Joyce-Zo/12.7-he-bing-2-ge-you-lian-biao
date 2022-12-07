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
        return list2;   //������һ������ΪNULL����ֱ�ӷ�����һ��������
    }
    else if (list2 == NULL)
    {
        return list1;
    }
    else
    {
        (list2->val) > (list1->val) ? (head = list1, tail = list1, list1 = list1->next) : (head = list2, tail = list2, list2 = list2->next);
            // ��Ŀ�������������ȸ�head��tailһ��ֵ�������l1С�Ͱ�l1��head/tail
            // ����l2
        while (list1 && list2)
        {
            if ((list1->val) > (list2->val))
            {
                tail->next = list2;
                list2 = list2->next;    // �Ƚϴ�С��˭С��˭��tail��next��head���䣬��¼ͷ
            }
            else
            {
                tail->next = list1;
                list1 = list1->next;
            }
            tail = tail->next;
        }
        //  ��󣬵�һ��ΪNULLʱ���˳�����ѭ��������ʣ�µ�һ������ֱ�Ӽ���tail��next��
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
        //  ֱ��mallocһ���ڱ�λͷ�ڵ�
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
    //  ��Ϊ��malloc�����Լǵ��ͷţ�����Ӧ�ȱ��浽һ��ָ������ͷ�
    struct ListNode* list = head->next;
    free(head);
    return list;
}
int main()
{
    //  �Լ���������
    struct ListNode* newnode1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode11 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode22 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode33 = (struct ListNode*)malloc(sizeof(struct ListNode));

    //  ������ֵ
    newnode1->val = 1; newnode1->next = newnode2;
    newnode2->val = 2; newnode2->next = newnode3;
    newnode3->val = 4; newnode3->next = NULL;
    newnode11->val = 1; newnode11->next = newnode22;
    newnode22->val = 3; newnode22->next = newnode33;
    newnode33->val = 4; newnode33->next = NULL;

    //  ����������
    struct ListNode* head = mergeTwoLists(newnode1,newnode11);
    return 0;
}