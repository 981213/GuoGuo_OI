/*************************************************************************
	> File Name: p1235.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年12月05日 星期五 16时21分16秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define custmax(a,b) a>b?a:b
using namespace std;
int n;
int numlist1[301];
int numlist2[301];
int stats[301][301];
short statsfromx[301][301];
short statsfromy[301][301];
int resnums[301],resnumcount=0,stats2[301];
int maxnum,maxfromx,maxfromy;
inline int getstat(int i,int j)
{
    int retval[3]={
        stats[i-1][j-1]+(numlist1[i]==numlist2[j]),
        stats[i-1][j],
        stats[i][j-1]
    };
    int * retvala = max_element(retval,retval+3);
    if(maxnum<*retvala)
    {
        maxnum=*retvala;
        maxfromx=i;
        maxfromy=j;
    }
    switch(retvala-retval)
    {
        case 0:
            statsfromx[i][j]=i-1;
            statsfromy[i][j]=j-1;
            break;
        case 1:
            statsfromx[i][j]=statsfromx[i-1][j];
            statsfromy[i][j]=statsfromy[i-1][j];
            break;
        case 2:
            statsfromx[i][j]=statsfromx[i][j-1];
            statsfromy[i][j]=statsfromy[i][j-1];
            break;
    }
    return *retvala;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&numlist1[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&numlist2[i]);
    }
    stats[0][0]=(numlist1[0]==numlist2[0]);
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            stats[i][j]=getstat(i,j);
        }
    }
    int temp;
    for(;((statsfromx[maxfromx][maxfromy])&&(statsfromy[maxfromx][maxfromy]));temp=maxfromx,maxfromx=statsfromx[maxfromx][maxfromy],maxfromy=statsfromy[temp][maxfromy])
    {
        resnums[resnumcount++]=numlist1[maxfromx];
    }
    resnumcount--;
    printf("%d",maxnum);
    return 0;
}
