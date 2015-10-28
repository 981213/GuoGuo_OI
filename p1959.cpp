/*************************************************************************
	> File Name: milk.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年10月16日 星期五 18时05分07秒
 ************************************************************************/

#include<cstdio>
using namespace std;
int n,k;
#define MAX(a,b) (a>b?a:b)
struct _N_T {
        int LastE,ansa,ansb,ansc;//ansa=取,ansb=不取
} nodes[100010];
struct _E_T {
        int from,to,next;
} edges[200010];
int edc=1;
inline void AddEdge(int from,int to)
{
        edges[edc].from=from;
        edges[edc].to=to;
        edges[edc].next=nodes[from].LastE;
        nodes[from].LastE=edc;
        edc++;
}
inline void AddDEdge(int a,int b)
{
        AddEdge(a,b);
        AddEdge(b,a);
}

void dfs(int now,int father,bool opt)
{
        register int CurE=nodes[now].LastE;
        if(opt){//计算ansa
                nodes[now].ansa=1;
                while(CurE)
                {
                        if(edges[CurE].to==father){CurE=edges[CurE].next;continue;}
                        dfs(edges[CurE].to,now,0);
                        nodes[now].ansa+=nodes[edges[CurE].to].ansb;
                        CurE=edges[CurE].next;
                }
        } else {//计算ansb
                while(CurE)
                {
                        if(edges[CurE].to==father){CurE=edges[CurE].next;continue;}
                        dfs(edges[CurE].to,now,1);
                        nodes[now].ansb+=MAX(nodes[edges[CurE].to].ansa,nodes[edges[CurE].to].ansb);
                        CurE=edges[CurE].next;
                }
        }
}
#ifdef ACANS2
void dfs2(int now,int father,int opt)//opt: 0 100 1 010 2 001
{
        register int CurE=nodes[now].LastE;
        if(opt==0){//计算ansa
                nodes[now].ansa=1;
                while(CurE)
                {
                        if(edges[CurE].to==father){CurE=edges[CurE].next;continue;}
                        dfs(edges[CurE].to,now,1);
                        dfs(edges[CurE].to,now,2);
                        nodes[now].ansa+=nodes[edges[CurE].to].ansc;
                        CurE=edges[CurE].next;
                }
        } else if(opt==1) {//计算ansb
                while(CurE)
                {
                        if(edges[CurE].to==father){CurE=edges[CurE].next;continue;}
                        dfs(edges[CurE].to,now,0);
                        dfs(edges[CurE].to,now,2);
                        nodes[now].ansb+=nodes[edges[CurE].to].ansc;
                        CurE=edges[CurE].next;
                }
        } else if(opt==2) {
                while(CurE)
                {
                }
        }
}
#endif
int main()
{
        scanf("%d%d",&n,&k);
        for(register int i=1;i<n;i++)
        {
                int tmp1,tmp2;
                scanf("%d%d",&tmp1,&tmp2);
                AddDEdge(tmp1,tmp2);
        }
        if(k==1)
        {
                dfs(1,0,1);
                dfs(1,0,0);
                printf("%d",MAX(nodes[1].ansa,nodes[1].ansb));
        }
        return 0;
}
