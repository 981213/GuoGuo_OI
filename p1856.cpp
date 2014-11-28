/*************************************************************************
	> File Name: p1856.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年11月26日 星期三 18时56分29秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
int n,m;
int card1,card2,card3,card4;
int chesslist[352];
int stat[41][41][41][41];
using namespace std;
inline int countres(int i,int j,int k,int l)
{
    int res=0;
    if(i)res=stat[i-1][j][k][l];
    if(j&&res<stat[i][j-1][k][l])res=stat[i][j-1][k][l];
    if(k&&res<stat[i][j][k-1][l])res=stat[i][j][k-1][l];
    if(l&&res<stat[i][j][k][l-1])res=stat[i][j][k][l-1];
    res+=chesslist[i+(j<<1)+k*3+(l<<2)];
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&chesslist[i]);
    }
    for(int i=0;i<m;i++)
    {
        int temp;
        scanf("%d",&temp);
        switch(temp)
        {
            case 1:card1++;break;
            case 2:card2++;break;
            case 3:card3++;break;
            case 4:card4++;break;
        }
    }
    for(int i=0;i<=card1;i++)
    {
        for(int j=0;j<=card2;j++)
        {
            for(int k=0;k<=card3;k++)
            {
                for(int l=0;l<=card4;l++)
                {
                    stat[i][j][k][l]=countres(i,j,k,l);
                }
            }
        }
    }
    printf("%d",stat[card1][card2][card3][card4]);
    return 0;
}
