/*************************************************************************
	> File Name: p1280.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年12月26日 星期五 19时39分30秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
short SqStack[100000];
int StackPoint=1;
int n;
int AnsNum;
inline void Cal_Ans(int & CurNum)
{
    while(SqStack[StackPoint-1]>CurNum)
    {
        --StackPoint;
    }
    if(SqStack[StackPoint-1]!=CurNum)
    {
        ++AnsNum;
    }
    SqStack[StackPoint++]=CurNum;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int CurNum;
        scanf("%d",&CurNum);
        Cal_Ans(CurNum);
    }
    printf("%d",AnsNum);
    return 0;
}
