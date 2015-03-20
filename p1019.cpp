/*************************************************************************
	> File Name: p1019.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年03月03日 星期二 19时33分47秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k;

static const short avalstat[] = {0,1,2,4,5,8,9,10,16,17,18,20,21,32,33,34,36,37,40,41,42,64,65,66,68,69,72,73,74,80,81,82,84,85,128,129,130,132,133,136,137,138,144,145,146,148,149,160,161,162,164,165,168,169,170,256,257,258,260,261,264,265,266,272,273,274,276,277,288,289,290,292,293,296,297,298,320,321,322,324,325,328,329,330,336,337,338,340,341};
#define MAXST 90
//所有单行可行状态
int BitCount(int Num)
{
    int Sum=0;
    while(Num>0)
    {
        Sum+=(Num&1);
        Num>>=1;
    }
    return Sum;
}
#define CheckAval(stat1,stat2) (((stat1&stat2)==0)&&((stat1&(stat2>>1))==0)&&((stat1&(stat2<<1))==0))
int DP[15][90][1<<10+1];
int temp;
int main()
{
    scanf("%d%d",&n,&k);
    int maxstatnum=(1<<n)-1;
    //Init
    #ifdef DEBUG
    puts("Init.");
    #endif
    for(int i=0;i<MAXST;i++)
    {
        if((avalstat[i]<maxstatnum)&&((temp=BitCount(avalstat[i]))<=k))
        {
            DP[0][temp][avalstat[i]]=1;
            #ifdef DEBUG
            printf(" Stat %d Avail.BitCount:%d.\n",avalstat[i],temp);
            #endif
        }
    }
    //DP
    for(int i=1;i<n;i++)//行
    {
        for(int j=0;j<=k;j++)//已用
        {
            for(int st=0;((st<MAXST)&&(avalstat[st]<maxstatnum));st++)//当前状态avalstat[st]
            {
                if(((temp=BitCount(avalstat[st])+j)<=k))
                {
                    for(int pst=0;((pst<MAXST)&&(avalstat[pst]<maxstatnum));pst++)//前一个状态avalstat[pst]
                    {
                        #ifdef DEBUG
                        printf("Line %d Used %d.Checking Stat %d with %d:",i,j,avalstat[st],avalstat[pst]);
                        #endif
                        if(CheckAval(avalstat[st],avalstat[pst]))
                        {
                            #ifdef DEBUG
                            puts("true.");
                            #endif
                            DP[i][temp][avalstat[st]]+=DP[i-1][j][avalstat[pst]];
                        }
                        #ifdef DEBUG
                        else puts("false.");
                        #endif
                    }
                }
            }
        }
    }
    #ifdef DEBUG
    for(int i=0;i<n;i++)
    {
        printf("Line %d:\n",i);
        for(int j=0;j<=k;j++)
        {
            printf("  Used Chess:%d\n",j);
            for(int a=0;(a<MAXST)&&(avalstat[a]<maxstatnum);a++)
            {
                printf("    Stat %d has %d ways.\n",avalstat[a],DP[i][j][avalstat[a]]);
            }
        }
    }
    #endif
    unsigned int Ans=0;
            for(int a=0;(a<MAXST)&&(avalstat[a]<maxstatnum);a++)
            {
                Ans+=DP[n-1][k][avalstat[a]];
            }
    cout<<Ans;
    return 0;
}
