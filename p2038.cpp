/*************************************************************************
	> File Name: p2038.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年06月23日 星期二 10时09分11秒
 ************************************************************************/

#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;

int TotE,TotN;
int TotResList[100010];
int ResListCnt=0;
#define PushRes(a) TotResList[ResListCnt++]=a
//Node/Edge
struct _NODE {
        int LastE;
        int InDeg;
        int Deleted;
} nodes[100010];
struct _EDGE {
        int NextE;
        int From;
        int To;
        int Deleted;
} edges[100010];
int EdgeCount=1;

//For searching...
priority_queue<int,vector<int>,greater<int> > SearchQue;
//Functions
inline void AddEdge(int & from,int & to)
{
        edges[EdgeCount].From=from;
        edges[EdgeCount].To=to;
        edges[EdgeCount].NextE=nodes[from].LastE;
        nodes[from].LastE=EdgeCount;
        EdgeCount++;
        nodes[to].InDeg++;
}
//Processing......
inline void Read()
{
        register int tmp1,tmp2;
        scanf("%d%d",&TotN,&TotE);
        for(int i=0;i<TotE;i++)
        {
                scanf("%d%d",&tmp1,&tmp2);
                AddEdge(tmp1,tmp2);
        }
}
inline void Search()
{
        //获取所有入度为0的点并加入堆
        for(int i=1;i<=TotN;i++)
        {
                if(!nodes[i].InDeg)
                {
                       SearchQue.push(i); 
                }
        }
        //取点，遍历并删边
        register int NowNode,NowEdge;
        while(!SearchQue.empty())
        {
                NowNode=SearchQue.top();
                SearchQue.pop();
                if(nodes[NowNode].Deleted)continue;
                PushRes(NowNode);
                nodes[NowNode].Deleted=1;
                NowEdge=nodes[NowNode].LastE;
                while(NowEdge)
                {
                        if(edges[NowEdge].Deleted)continue;
                        edges[NowEdge].Deleted=1;
                        nodes[edges[NowEdge].To].InDeg--;
                        if(!nodes[edges[NowEdge].To].InDeg)
                                SearchQue.push(edges[NowEdge].To);
                        NowEdge=edges[NowEdge].NextE;
                }
        }
}
#define ExitProg() exit(!puts("OMG."))
inline void Judge()
{
        for(register int i=1;i<=TotN;i++)
        {
                if(!nodes[i].Deleted)ExitProg();
        }
        for(register int i=1;i<=TotE;i++)
        {
                if(!edges[i].Deleted)ExitProg();
        }
}
inline void Print()
{
        for(register int i=0;i<ResListCnt;i++)
        {
                printf("%d ",TotResList[i]);
        }
}

int main()
{
        Read();
        Search();
        Judge();
        Print();
        return 0;
}
