/*************************************************************************
	> File Name: p1216.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年11月28日 星期五 16时10分01秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int vallist[17][17];//i->j 人的编号为0~15
int n;
int stats[16][1<<16];//当前在地I个人,stat
int getstat(int i,int j)
{
    int retval=2147483647;
    
    //i-1, j^(1<<i)
    //
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&vallist[i][j]);
        }
    }
    for(int i=0;i<16;i++)
    {
        stats[i][0]=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<~(1<<n);j++)
        {
            stats[i][j]=getstat(i,j);
        }
    }
    return 0;
}
