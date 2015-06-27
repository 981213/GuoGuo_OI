/*************************************************************************
	> File Name: p2064.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年01月02日 星期五 15时53分11秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;


struct EDGE{
    int NodeL;
    int NodeR;
    int EdgeWeight;
    int NextEdge;
}edges[200010];
int EdgeCount=1;
int NodeMinDist[15010];
int NodeLastEdge[15010];
queue<int> SPFAQueue;
int m,n,q;
int temp1,temp2,temp3;
int i;

inline void InitEdge(int & EdgeNum)
{
    edges[EdgeNum].NextEdge=NodeLastEdge[edges[EdgeNum].NodeL];
    NodeLastEdge[edges[EdgeNum].NodeL]=EdgeNum;
}
inline void AddEdge(int & NodeL,int & NodeR,int & EdgeWeight)
{
    edges[EdgeCount].NodeL=NodeL;
    edges[EdgeCount].NodeR=NodeR;
    edges[EdgeCount].EdgeWeight=EdgeWeight;
    InitEdge(EdgeCount);
    EdgeCount++;
}
inline void AddDualEdge(int & NodeA,int & NodeB,int & EdgeWeight)
{
    AddEdge(NodeA,NodeB,EdgeWeight);
    AddEdge(NodeB,NodeA,EdgeWeight);
}
inline void SPFA()
{
    memset(NodeMinDist,60,(n+2)*sizeof(int));
    SPFAQueue.push(1);
    NodeMinDist[1]=0;
    while(!SPFAQueue.empty())
    {
        int NowNode=SPFAQueue.front();
        #ifdef DEBUG
        printf("Now Node=%d\n",NowNode);
        #endif
        SPFAQueue.pop();
        int NowEdge=NodeLastEdge[NowNode];
        while(NowEdge)
        {
            if(NodeMinDist[edges[NowEdge].NodeR]>NodeMinDist[NowNode]+edges[NowEdge].EdgeWeight)
            {
                SPFAQueue.push(edges[NowEdge].NodeR);
                NodeMinDist[edges[NowEdge].NodeR]=NodeMinDist[NowNode]+edges[NowEdge].EdgeWeight;
            }
            NowEdge=edges[NowEdge].NextEdge;
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(i=0;i<m;++i)
    {
        scanf("%d%d%d",&temp1,&temp2,&temp3);
        AddDualEdge(temp1,temp2,temp3);
    }
    SPFA();
    for(i=0;i<q;++i)
    {
        scanf("%d%d",&temp1,&temp2);
        printf("%d\n",NodeMinDist[temp1]+NodeMinDist[temp2]);
    }
    return 0;
}


