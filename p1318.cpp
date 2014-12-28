/*************************************************************************
	> File Name: p1318.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年12月28日 星期日 18时20分06秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int Dists[101][101];

int n,m;
int temp1,temp2;
int main()
{
    scanf("%d%d",&n,&m);
    memset(Dists,60,sizeof(Dists));
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&temp1,&temp2);
        scanf("%d",&Dists[temp1][temp2]);
        Dists[temp2][temp1]=Dists[temp1][temp2];
    }
    for(int i=1;i<=n;i++)
    {
        Dists[i][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                Dists[j][k]=
                Dists[j][k]<Dists[j][i]+Dists[i][k]?
                Dists[j][k]:
                Dists[j][i]+Dists[i][k];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",Dists[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
