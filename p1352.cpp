/*************************************************************************
	> File Name: p1352.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月18日 星期五 17时32分07秒
 ************************************************************************/
//分析题意可知为求MST
#include<cstdio>
#include<cstring>
#include<cassert>
using namespace std;
int DistMap[1810][1810];
int n;
//Prim
#define MAXINT 2147483647
int lowcost[1810];
int mst[1810];
inline int Prim_MST()//选取1号点作为起点
{
        int sum=0;
        int min,minid;
        memset(lowcost,125,sizeof(int)*(n+5));
        lowcost[1]=-1;
        for(register int i=2;i<=n;i++)
        {
                lowcost[i]=DistMap[1][i];
                mst[i]=1;
        }
        mst[1]=0;//起点加入MST
        for(register int i=2;i<=n;i++)
        {
                min=MAXINT;
                minid=0;
                for(register int j=2;j<=n;j++)
                {
                        if((lowcost[j]<min)&&(lowcost[j]!=-1))
                        {
                                min=lowcost[j];
                                minid=j;
                        }
                }
                sum+=min;
                assert(sum>=0);
                lowcost[minid]=-1;
                //重新初始化lowcost
                for(register int j=2;j<=n;j++)
                {
                        if(DistMap[minid][j]<lowcost[j])
                        {
                                lowcost[j]=DistMap[minid][j];
                                mst[j]=minid;
                        }
                }
                
        }
        return sum;
}
int main()
{
        scanf("%d",&n);
        for(register int i=1;i<=n;i++)
        {
                for(register int j=1;j<=n;j++)
                {
                        scanf("%d",&DistMap[i][j]);
                }
        }
        printf("%d",Prim_MST());
        return 0;
}

