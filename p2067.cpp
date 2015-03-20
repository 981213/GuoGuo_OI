/*************************************************************************
	> File Name: p2067.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年01月13日 星期二 09时45分49秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct EDGE{
    int NodeL;
    int NodeR;
    int EdgeWeight;
    int PrevEdge;
}edges[400020];
int NodeLastEdge[200010];
int NodeDist[200010];
int EdgeCount=1;
int NodeCount=1;
queue<int> SPFAQueue;
inline void AddEdge(int & NoL,int & NoR,int & EdW)
{
    edges[EdgeCount].NodeL=NoL;
    edges[EdgeCount].NodeR=NoR;
    edges[EdgeCount].EdgeWeight=EdW;
    edges[EdgeCount].PrevEdge=NodeLastEdge[NoL];
    NodeLastEdge[NoL]=EdgeCount;
    EdgeCount++;
}
inline void AddDualEdge(int No1,int No2,int & EdW)
{
    #ifdef DEBUG
    printf("Connect %d with %d.\n",No1,No2);
    #endif
    AddEdge(No1,No2,EdW);
    AddEdge(No2,No1,EdW);
}
int NowEdge;
int NowNode;
inline int SPFA(int Start,int End)
{
    memset(NodeDist,60,sizeof(NodeDist));
    SPFAQueue.push(Start);
    NodeDist[Start]=0;
    while(!SPFAQueue.empty())
    {
        NowNode=SPFAQueue.front();
        SPFAQueue.pop();
        NowEdge=NodeLastEdge[NowNode];
        while(NowEdge)
        {
            if(NodeDist[edges[NowEdge].NodeR]>NodeDist[NowNode]+edges[NowEdge].EdgeWeight)
            {
                NodeDist[edges[NowEdge].NodeR]=NodeDist[NowNode]+edges[NowEdge].EdgeWeight;
                SPFAQueue.push(edges[NowEdge].NodeR);
            }
            NowEdge=edges[NowEdge].PrevEdge;
        }
    }
    return NodeDist[End];
}
int n,i,j;
int temp1,temp2,temp3;
int ThisLineFirst,NextLineFirst;
long long TotSum=0;
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        ThisLineFirst=NodeCount;
        NextLineFirst=ThisLineFirst+i;
        for(j=0;j<i;j++)
        {
            #define NexL (NextLineFirst+(NodeCount-ThisLineFirst))
            #define NexR (NextLineFirst+(NodeCount-ThisLineFirst)+1)
            scanf("%d%d%d",&temp1,&temp2,&temp3);
            AddDualEdge(NodeCount,NexL,temp1);
            AddDualEdge(NodeCount,NexR,temp2);
            AddDualEdge(NexL,NexR,temp3);
            TotSum+=(temp1+temp2+temp3);
            NodeCount++;
        }
    }
    NodeCount--;
    int Res=SPFA(1,NexR);
    printf("%d",TotSum-Res);
    return 0;
}
