/*************************************************************************
	> File Name: p1127.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年12月24日 星期三 19时32分58秒
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
}edges[40010];
int NodeMinWeight[20010];
int n,m,a,b;
int NodeLastEdge[20010];
queue<int> SpFaQueue;
long long AnsRes;
inline void AddEdge(int EdgeNum)
{
    edges[EdgeNum].PrevEdge=NodeLastEdge[edges[EdgeNum].NodeLeft];
    NodeLastEdge[edges[EdgeNum].NodeLeft]=EdgeNum;
}
inline void SpFaL()
{
    SpFaQueue.push(a);
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
int main()
{
    scanf("%d%d%d%d",&n,&m,&a,&b);
    memset(NodeMinWeight,60,sizeof(int)*(n+1));
    NodeMinWeight[a]=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&edges[i].NodeLeft,&edges[i].NodeRight,&edges[i].EdgeWeight);
        AddEdge(i);
    }
    SpFaL();
    printf("%d",NodeMinWeight[b]);
    return 0;
}
