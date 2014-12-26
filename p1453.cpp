/*************************************************************************
	> File Name: p1453.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年12月24日 星期三 13时27分34秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct Edge{
    int NodeLeft;
    int NodeRight;
    int EdgeWeight;
    int PrevEdge;
    int PrevEdgeR;
}edges[100010];
int NodeMinWeight[1010];
int n,m;
int NodeLastEdge[1010];
int NodeLastEdgeR[1010];
queue<int> SpFaQueue;
long long AnsRes;
inline void AddEdge(int EdgeNum)
{
    edges[EdgeNum].PrevEdge=NodeLastEdge[edges[EdgeNum].NodeLeft];
    NodeLastEdge[edges[EdgeNum].NodeLeft]=EdgeNum;
    edges[EdgeNum].PrevEdgeR=NodeLastEdgeR[edges[EdgeNum].NodeRight];
    NodeLastEdgeR[edges[EdgeNum].NodeRight]=EdgeNum;
}
inline void SpFaL()
{
    SpFaQueue.push(1);
    int NextEdge;
    int NowNode;
    while(!SpFaQueue.empty())
    {
        NowNode=SpFaQueue.front();
        SpFaQueue.pop();
        NextEdge=NodeLastEdge[NowNode];
        while(NextEdge)
        {
            if(NodeMinWeight[edges[NextEdge].NodeRight]>NodeMinWeight[NowNode]+edges[NextEdge].EdgeWeight)
            {
                NodeMinWeight[edges[NextEdge].NodeRight]=NodeMinWeight[NowNode]+edges[NextEdge].EdgeWeight;
                SpFaQueue.push(edges[NextEdge].NodeRight);
            }
            NextEdge=edges[NextEdge].PrevEdge;
        }
    }
}
inline void SpFaR()
{
    SpFaQueue.push(1);
    int NextEdge;
    int NowNode;
    while(!SpFaQueue.empty())
    {
        NowNode=SpFaQueue.front();
        SpFaQueue.pop();
        NextEdge=NodeLastEdgeR[NowNode];
        while(NextEdge)
        {
            if(NodeMinWeight[edges[NextEdge].NodeLeft]>NodeMinWeight[NowNode]+edges[NextEdge].EdgeWeight)
            {
                NodeMinWeight[edges[NextEdge].NodeLeft]=NodeMinWeight[NowNode]+edges[NextEdge].EdgeWeight;
                SpFaQueue.push(edges[NextEdge].NodeLeft);
            }
            NextEdge=edges[NextEdge].PrevEdgeR;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(NodeMinWeight,60,sizeof(int)*(n+1));
    NodeMinWeight[1]=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&edges[i].NodeLeft,&edges[i].NodeRight,&edges[i].EdgeWeight);
        AddEdge(i);
    }
    SpFaL();
    for(int i=2;i<=n;i++)
    {
        AnsRes+=NodeMinWeight[i];
    }
    memset(NodeMinWeight,60,sizeof(int)*(n+1));
    NodeMinWeight[1]=0;
    SpFaR();
    for(int i=2;i<=n;i++)
    {
        AnsRes+=NodeMinWeight[i];
    }
    printf("%d",AnsRes);
    return 0;
}
