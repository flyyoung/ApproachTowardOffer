/*
题目：输入一个链表，输出该链表中倒数第k个结点。
      为了符合大多数的习惯，本题从1开始计数，
      即链表的尾结点是倒数第1个结点。
      如一个链表有6个结点，从头结点开始它们的值依次是1、2、3、4、5、6.
      这个链表的倒数第3个结点是值为4的结点。
*/
#include <iostream>
#include <cstdlib>
using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
};

ListNode *CreateListNode(int value)
{
    ListNode *pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = NULL;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
    if(pCurrent == NULL)
    {
        cout<<"Error to connect two nodes."<<endl;;
        exit(1);
    }
    pCurrent->m_pNext = pNext;
}

void PrintListNode(ListNode* pNode)
{
    if(pNode == NULL)
    {
        cout<<"The node is NULL"<<endl;
    }
    else
    {
        cout<<"The key in node is "<<pNode->m_nValue<<endl;
    }
}

void PrintList(ListNode *pHead)
{
    cout<<"PrintList starts."<<endl;

    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        cout<<"\t"<<pNode->m_nValue;
        pNode = pNode->m_pNext;
    }

    cout<<"\nPrintList ends.\n";
}

void DestroyList(ListNode *pHead)
{
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        pHead = pHead->m_pNext;
        delete pNode;
        pNode = pHead;
    }
}

/*寻找链表中倒数第K个数*/
ListNode* FindKthToTail(ListNode *pListHead,int k)
{
    if(pListHead == NULL || k == 0)
    {
        return NULL;
    }

    ListNode *pAhead = pListHead;
    ListNode *pBehind = pListHead;
    /*pAhead向前走k-1步。当pAhead走到尾结点时，pAhead和pBehind始终相差k-1,则pBehind指向的正是第(n-(k-1))=（n-k+1）个数*/
    for(int i=0;i<k-1;i++)
    {
        /*检查k>n的情况*/
        if(pAhead->m_pNext!=NULL)
        {
            pAhead = pAhead->m_pNext;
        }
        else
        {
            return NULL;
        }
    }

    while(pAhead->m_pNext!=NULL)
    {
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
    }
    return pBehind;
}

// ====================测试代码====================
// 测试要找的结点在链表中间
void Test1()
{
    cout<<"=====Test1 starts:====="<<endl;
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    cout<<"expected result: 4."<<endl;
    ListNode* pNode = FindKthToTail(pNode1, 2);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// 测试要找的结点是链表的尾结点
void Test2()
{
    cout<<"=====Test2 starts:====="<<endl;
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    cout<<"expected result: 5."<<endl;
    ListNode* pNode = FindKthToTail(pNode1, 1);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// 测试要找的结点是链表的头结点
void Test3()
{
    cout<<"=====Test3 starts:====="<<endl;
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    cout<<"expected result: 1."<<endl;
    ListNode* pNode = FindKthToTail(pNode1, 5);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// 测试空链表
void Test4()
{
    cout<<"=====Test4 starts:====="<<endl;
    cout<<"expected result: NULL."<<endl;
    ListNode* pNode = FindKthToTail(NULL, 100);
    PrintListNode(pNode);
}

// 测试输入的第二个参数大于链表的结点总数
void Test5()
{
    cout<<"=====Test5 starts:====="<<endl;
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    cout<<"expected result: NULL."<<endl;
    ListNode* pNode = FindKthToTail(pNode1, 6);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// 测试输入的第二个参数为0
void Test6()
{
    cout<<"=====Test6 starts:====="<<endl;
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    cout<<"expected result: NULL."<<endl;
    ListNode* pNode = FindKthToTail(pNode1, 0);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}
