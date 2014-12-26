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
int stats[1<<16][16];//当前在地I个人,stat
inline int getstat(int stat,int cur)
{
    int retval=stats[stat][cur];
    if(stat & (1<<cur))
    {
        for(int prevperson=0;prevperson<n;prevperson++)
        {
            if((prevperson==cur)||!(stat&(1<<prevperson))) continue;
            else
            {
                if(retval>stats[stat^(1<<cur)][prevperson]+vallist[prevperson][cur])
                   retval=stats[stat^(1<<cur)][prevperson]+vallist[prevperson][cur];
            }
        }
    }
    return retval;
}
int main()
{
    memset(stats,60,sizeof(stats));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        stats[1<<i][i]=0;
        for(int j=0;j<n;j++)
        {
            scanf("%d",&vallist[i][j]);
        }
    }
    for(int i=1;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            stats[i][j]=getstat(i,j);
        }
    }
    int minval=2147483647;
    for(int i=0;i<n;i++)
    {
        if(minval>stats[(1<<n)-1][i])minval=stats[(1<<n)-1][i];
    }
    printf("%d",minval);
    return 0;
}
