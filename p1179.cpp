/*************************************************************************
	> File Name: p1179.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年05月17日 星期日 09时49分29秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXS 1000
int match[]={6,2,5,5,4,5,6,3,7,6};
inline int cmth(int a )
{
    if(a==0)return 6;
    int count=0;
    while(a>0)
    {
        count+=match[a%10];
        a/=10;
    }
    return count;
}
int n,cnt;
int vis[MAXS+4][MAXS+4];
int main()
{
    scanf("%d",&n);
    n-=4;
    for(int i=0;i<MAXS;i++)
    {
        for(int j=0;j<MAXS;j++)
        {
            if((cmth(i)+cmth(j)+cmth(i+j)==n))
            {
                #ifdef DEBUG
                printf("%d+%d=%d Used:%d+%d+%d+4=%d\n",i,j,i+j,cmth(i),cmth(j),cmth(i+j),cmth(i)+cmth(j)+cmth(i+j)+4);
                #endif
                cnt++;
            }
            #ifdef DEBUG
            else
            {
                //printf("UNAVAL:%d+%d=%d Used:%d+%d+%d+4=%d\n",i,j,i+j,cmth(i),cmth(j),cmth(i+j),cmth(i)+cmth(j)+cmth(i+j)+4);
            }
            #endif
        }
    }
    printf("%d",cnt);
    return 0;
}
