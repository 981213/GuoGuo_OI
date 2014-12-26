/*************************************************************************
	> File Name: p1604.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年12月12日 星期五 16时10分03秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
struct STULINK
{
    int left,right;
    bool mark_removed;
}students[100010];
int n,m;
inline void ins_left(int curstu,int targetstu)
{
    students[curstu].left=students[targetstu].left;
    students[targetstu].left=curstu;
    students[curstu].right=targetstu;
    students[students[curstu].left].right=curstu;
}
inline void ins_right(int curstu,int targetstu)
{
    students[curstu].right=students[targetstu].right;
    students[targetstu].right=curstu;
    students[curstu].left=targetstu;
    students[students[curstu].right].left=curstu;
}
inline void stu_insert(int curstu,int targetstu,bool operate)//0=left 1=right
{
    if(operate)
    {
        ins_right(curstu,targetstu);
    }
    else
    {
        ins_left(curstu,targetstu);
    }
}
inline void stu_rm(int targetstu)
{
    if(students[targetstu].mark_removed)return;
    students[students[targetstu].left].right=students[targetstu].right;
    students[students[targetstu].right].left=students[targetstu].left;
    students[targetstu].mark_removed=1;
}
int main()
{
    scanf("%d",&n);
    students[0].right=1;
    for(int i=2;i<=n;i++)
    {
        int _target,operate;
        scanf("%d%d",&_target,&operate);
        stu_insert(i,_target,operate);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int temp;
        scanf("%d",&temp);
        stu_rm(temp);
    }
    int currentstu=students[0].right;
    while(currentstu)
    {
        printf("%d ",currentstu);
        currentstu=students[currentstu].right;
    }
    return 0;
}
