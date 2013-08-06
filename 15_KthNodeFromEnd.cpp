/*
��Ŀ������һ����������������е�����k����㡣
      Ϊ�˷��ϴ������ϰ�ߣ������1��ʼ������
      �������β����ǵ�����1����㡣
      ��һ��������6����㣬��ͷ��㿪ʼ���ǵ�ֵ������1��2��3��4��5��6.
      �������ĵ�����3�������ֵΪ4�Ľ�㡣
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

/*Ѱ�������е�����K����*/
ListNode* FindKthToTail(ListNode *pListHead,int k)
{
    if(pListHead == NULL || k == 0)
    {
        return NULL;
    }

    ListNode *pAhead = pListHead;
    ListNode *pBehind = pListHead;
    /*pAhead��ǰ��k-1������pAhead�ߵ�β���ʱ��pAhead��pBehindʼ�����k-1,��pBehindָ������ǵ�(n-(k-1))=��n-k+1������*/
    for(int i=0;i<k-1;i++)
    {
        /*���k>n�����*/
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

// ====================���Դ���====================
// ����Ҫ�ҵĽ���������м�
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

// ����Ҫ�ҵĽ���������β���
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

// ����Ҫ�ҵĽ���������ͷ���
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

// ���Կ�����
void Test4()
{
    cout<<"=====Test4 starts:====="<<endl;
    cout<<"expected result: NULL."<<endl;
    ListNode* pNode = FindKthToTail(NULL, 100);
    PrintListNode(pNode);
}

// ��������ĵڶ���������������Ľ������
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

// ��������ĵڶ�������Ϊ0
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
