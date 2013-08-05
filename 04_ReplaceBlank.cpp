/*
题目：请实现一个函数，把字符串中的每个空格替换成“%20”。
      例如输入“We are happy.”,则输出“We%20are%20happy.”
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*length为字符数组的总容量*/
void ReplaceBlank(char str[],int length)
{
    if(str==NULL&&length<=0)
    {
        return;
    }
    int originalLength=0;
    int numberOfBlank=0;
    int i = 0;
    while(str[i]!='\0')
    {
        ++originalLength;
        if(str[i]==' ')
        {
            ++numberOfBlank;
        }
        ++i;
    }
    /*newLength 为把空格替换成'%20'之后的长度*/
    int newLength = originalLength + numberOfBlank * 2;
    if(newLength > length)
        return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if(str[indexOfOriginal] == ' ')
        {
            str[indexOfNew --] = '0';
            str[indexOfNew --] = '2';
            str[indexOfNew --] = '%';
        }
        else
        {
            str[indexOfNew --] = str[indexOfOriginal];
        }

        -- indexOfOriginal;
    }

}

void Test(char* testName, char string[], int length, char expected[])
{
    if(testName != NULL)
        cout<<testName<<" begins: ";

    ReplaceBlank(string, length);

    if(expected == NULL && string == NULL)
        cout<<"Passed."<<endl;
    else if(expected == NULL && string != NULL)
        cout<<"Failed."<<endl;
    else if(strcmp(string, expected) == 0)
        cout<<"Passed."<<endl;
    else
        cout<<"Failed."<<endl;
}

// 空格在句子中间
void Test1()
{
    const int length = 100;

    char string[length] = "hello world";
    Test("Test1", string, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
    const int length = 100;

    char string[length] = " helloworld";
    Test("Test2", string, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
    const int length = 100;

    char string[length] = "helloworld ";
    Test("Test3", string, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
    const int length = 100;

    char string[length] = "hello  world";
    Test("Test4", string, length, "hello%20%20world");
}

// 传入NULL
void Test5()
{
    Test("Test5", NULL, 0, NULL);
}

// 传入内容为空的字符串
void Test6()
{
    const int length = 100;

    char string[length] = "";
    Test("Test6", string, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;

    char string[length] = " ";
    Test("Test7", string, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
    const int length = 100;

    char string[length] = "helloworld";
    Test("Test8", string, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;

    char string[length] = "   ";
    Test("Test9", string, length, "%20%20%20");
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}
