/*************************************************************************
	> File Name: p1878.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年01月09日 星期五 18时25分12秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;

struct EDGE{
    int node1;
    int node2;
    int edgew;
}edges[90020];
int EdgeCount=1;
int NodeFather[308];
inline int GetFather(int NodeNum)
{
    return NodeFather[NodeNum]?NodeFather[NodeNum]=GetFather(NodeFather[NodeNum]):NodeNum;
}
inline bool ChkOrConnectNode(int Node1,int Node2)
{
    int Father2=GetFather(Node2);
    int Father1=GetFather(Node1);
    if(Father2==Father1)return 0;
    else {
        NodeFather[Father2]=Father1;
        return 1;
    }
}
int n,m,s,maxnum,i;
bool CustSort(struct EDGE a,struct EDGE b)
{
    return a.edgew<b.edgew;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",
              &edges[EdgeCount].node1,
              &edges[EdgeCount].node2,
              &edges[EdgeCount].edgew);
        EdgeCount++;
    }
    sort(edges+1,edges+EdgeCount,CustSort);
    for(i=1;i<EdgeCount;i++)
    {
        if(ChkOrConnectNode(edges[i].node1,edges[i].node2))
        {
            s++;
            maxnum=maxnum<edges[i].edgew?edges[i].edgew:maxnum;
        }
    }
    printf("%d %d",s,maxnum);
    return 0;
}
