/*************************************************************************
	> File Name: p1126.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年12月24日 星期三 12时34分05秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int NodeFather[200010];
struct Edge{
    int NodeLeft;
    int NodeRight;
    int EdgeWeight;
}edges[100010];
int n,m;
bool CustCompare(struct Edge edgea,struct Edge edgeb)
{
    return edgea.EdgeWeight<edgeb.EdgeWeight;
}
int GetFather(int & NodeNum)
{
    return (NodeNum==NodeFather[NodeNum]?NodeNum:(NodeFather[NodeNum]=GetFather(NodeFather[NodeNum])));
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
        NodeFather[AFather]=BFather;
        return 1;
    }
}
long long AnsNum=0;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        NodeFather[i]=i;
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",
              &edges[i].NodeLeft,
              &edges[i].NodeRight,
              &edges[i].EdgeWeight);
    }
    sort(edges,edges+m,CustCompare);
    for(int i=0;i<m;i++)
    {
        if(CheckOrAdd(edges[i].NodeLeft,edges[i].NodeRight))
        {
            AnsNum+=edges[i].EdgeWeight;
        }
    }
    printf("%d",AnsNum);
    return 0;
}
