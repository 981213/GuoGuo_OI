/*************************************************************************
	> File Name: p1324.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年12月28日 星期日 19时45分58秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
struct Edge{
    int NodeLeft;
    int NodeRight;
    int EdgeWeight;
    int PrevEdge;
    int PrevEdgeR;
}edges[100010];
int NodeMinWeight[5010];
int NodeMinWeight2[5010];
int n,m,x;
int NodeLastEdge[5010];
int NodeLastEdgeR[5010];
queue<int> SpFaQueue;
long long AnsRes;
inline void AddEdge(int EdgeNum)
{
    edges[EdgeNum].PrevEdge=NodeLastEdge[edges[EdgeNum].NodeLeft];
    NodeLastEdge[edges[EdgeNum].NodeLeft]=EdgeNum;
    edges[EdgeNum].PrevEdgeR=NodeLastEdgeR[edges[EdgeNum].NodeRight];
    NodeLastEdgeR[edges[EdgeNum].NodeRight]=EdgeNum;
}
inline void SpFaL(int & Start)
{
    memset(NodeMinWeight,60,sizeof(int)*(n+1));
    NodeMinWeight[Start]=0;
    SpFaQueue.push(Start);
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
inline void SpFaR(int & Start)
{
    memset(NodeMinWeight2,60,sizeof(int)*(n+1));
    NodeMinWeight2[Start]=0;
    SpFaQueue.push(Start);
    int NextEdge;
    int NowNode;
    while(!SpFaQueue.empty())
    {
        NowNode=SpFaQueue.front();
        SpFaQueue.pop();
        NextEdge=NodeLastEdgeR[NowNode];
        while(NextEdge)
        {
            if(NodeMinWeight2[edges[NextEdge].NodeLeft]>NodeMinWeight2[NowNode]+edges[NextEdge].EdgeWeight)
            {
                NodeMinWeight2[edges[NextEdge].NodeLeft]=NodeMinWeight2[NowNode]+edges[NextEdge].EdgeWeight;
                SpFaQueue.push(edges[NextEdge].NodeLeft);
            }
            NextEdge=edges[NextEdge].PrevEdgeR;
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&x);

    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&edges[i].NodeLeft,&edges[i].NodeRight,&edges[i].EdgeWeight);
        AddEdge(i);
    }
    SpFaL(x);
    SpFaR(x);
    int ThisRes;
    for(int i=1;i<=n;i++)
    {
        ThisRes=NodeMinWeight[i]+NodeMinWeight2[i];
        #ifdef DEBUG
        printf("%d Ans is: %d\n",i,ThisRes);
        #endif
        AnsRes=ThisRes>AnsRes?ThisRes:AnsRes;
    }
    printf("%d",AnsRes);
    return 0;
}
