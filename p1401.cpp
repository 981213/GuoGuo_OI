/*************************************************************************
	> File Name: p1401.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年06月12日 星期五 16时46分00秒
 ************************************************************************/

#include<cstdio>
#include<cstring>

using namespace std;
//Graph
struct NODE{
        unsigned int edways,lastedge;
} nodes[1010];
int TotNode;
struct EDGE{
        int left,right,edweight,nextedge;
} edges[2300010];
int EdC=1;
inline void AddEdge(int left,int right,int edweight)
{
        edges[EdC].left=left;
        edges[EdC].right=right;
        edges[EdC].edweight=edweight;
        edges[EdC].nextedge=nodes[left].lastedge;
        nodes[left].lastedge=EdC;
        EdC++;
}
inline void AddDEdge(int no1,int no2,int edw)
{
        AddEdge(no1,no2,edw);
        AddEdge(no2,no1,edw);
}
//Queue
#define QueSize 10101010
int que[QueSize];
int QuH=0,QuE=0;
#define AdQ(a) que[(QuE++)%QueSize]=a
#define DeQ()  que[(QuH++)%QueSize]
#define QEmp() (QuH==QuE)
//SPFAFunc
int shortpath[1010];

#define NoSP(a) shortpath[a]
#define EdWe(a) edges[a].edweight

void spfa(int start)
{
        memset(shortpath,60,sizeof(int)*(TotNode+3));
        AdQ(start);
        NoSP(start)=0;
        while(!QEmp())
        {
                int NowNode=DeQ();
                int NowEdge=nodes[NowNode].lastedge;
                while(NowEdge)
                {
                        if((NoSP(NowNode)+EdWe(NowEdge)<NoSP(edges[NowEdge].right)))
                        {
                                NoSP(edges[NowEdge].right)=NoSP(NowNode)+EdWe(NowEdge);
                                AdQ(edges[NowEdge].right);
                        }
                        NowEdge=edges[NowEdge].nextedge;
                }
        }
}

//main
int main()
{
        int TotEdge,tmp1,tmp2,tmp3;
        scanf("%d%d",&TotNode,&TotEdge);
        for(int i=0;i<TotEdge;i++)
        {
                scanf("%d%d%d",&tmp1,&tmp2,&tmp3);
                AddDEdge(tmp1,tmp2,tmp3);
        }
        spfa(1);
        for(int i=1;i<EdC;i++)
        {
                if((edges[i].right!=1)&&(shortpath[edges[i].left]+edges[i].edweight==shortpath[edges[i].right]))nodes[edges[i].right].edways++;
        }
        long long TotRes=1;
        for(int i=2;i<=TotNode;i++)TotRes=TotRes*nodes[i].edways%2147483647;
        printf("%u",TotRes);
        return 0;
}


