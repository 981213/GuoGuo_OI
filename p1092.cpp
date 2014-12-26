/*************************************************************************
	> File Name: p1092.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年12月26日 星期五 16时04分01秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct Edge{
    int NodeLeft;
    int NodeRight;
    float EdgeWeight;
}edges[4000010];
int EdgeCount=0;
struct Node{
    int NodeX;
    int NodeY;
    int NodeFather;
}nodes[2005];
int NodeCount=1;
inline void AddEdge(int NodeLeft,int & NodeRight,float EdgeWeight)
{
    #ifdef DEBUG
    printf("Edge Add %d,%d,%.7f \n",NodeLeft,NodeRight,EdgeWeight);
    #endif
    edges[EdgeCount].NodeLeft=NodeLeft;
    edges[EdgeCount].NodeRight=NodeRight;
    edges[EdgeCount].EdgeWeight=EdgeWeight;
    ++EdgeCount;
}

inline void AddNode(int NodeNum)
{
//    int Max=(NodeNum>5?4:NodeNum-1);
    for(int i=1;i<NodeNum;i++)
    {
        int xdist=nodes[i].NodeX-nodes[NodeNum].NodeX;
        int ydist=nodes[i].NodeY-nodes[NodeNum].NodeY;
        AddEdge(i,NodeNum,sqrt(float(xdist*xdist+ydist*ydist)));
    }
}
int n,r;
/*
bool custcompare(struct Node a,struct Node b)
{
    return (a.NodeX<b.NodeX)?1:(a.NodeX==b.NodeX?(a.NodeY<b.NodeY?1:0):0);
}*/
bool CustCompare(struct Edge edgea,struct Edge edgeb)
{
    return edgea.EdgeWeight<edgeb.EdgeWeight;
}
int GetFather(int & NodeNum)
{
    return (NodeNum==nodes[NodeNum].NodeFather?NodeNum:(nodes[NodeNum].NodeFather=GetFather(nodes[NodeNum].NodeFather)));
}
inline bool CheckOrAdd(int & NodeA,int & NodeB)
{
    int AFather=GetFather(NodeA);
    int BFather=GetFather(NodeB);
    if(AFather==BFather)
    {
        return 0;
    }
    else
    {
        nodes[AFather].NodeFather=BFather;
        return 1;
    }
}
double AnsA=0,AnsB=0;
int ToTNum=1;
int main()
{
    scanf("%d%d",&n,&r);
    while(NodeCount<=n)
    {
        scanf("%d%d",&nodes[NodeCount].NodeX,&nodes[NodeCount].NodeY);
        ++NodeCount;
    }
//    sort(nodes+1,nodes+NodeCount,custcompare);
    for(int i=1;i<=n;i++)
    {
        AddNode(i);
    }
    sort(edges,edges+EdgeCount,CustCompare);
    for(int i=1;i<=n;i++)
    {
        nodes[i].NodeFather=i;
    }
    for(int i=0;i<EdgeCount;i++)
    {
        if(CheckOrAdd(edges[i].NodeLeft,edges[i].NodeRight))
        {
            float NowWeight=edges[i].EdgeWeight;
            if(NowWeight>r)
            {
                ToTNum++;
                AnsB+=NowWeight;
            }
            else
            {
                AnsA+=NowWeight;
            }
            #ifdef DEBUG
            printf("Edge %d,%d,%.7f test Passed.NowWeight=%d \n",edges[i].NodeLeft,edges[i].NodeRight,edges[i].EdgeWeight,NowWeight);
            #endif
        }
        #ifdef DEBUG
        else 
        {
            printf("Edge %d,%d,%.7f test Failed \n",edges[i].NodeLeft,edges[i].NodeRight,edges[i].EdgeWeight);
        }
        #endif
    }
    printf("%lld %lld %lld",ToTNum,(long long)(AnsA+0.5),(long long)(AnsB+0.5));
    return 0;
}
