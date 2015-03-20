/*************************************************************************
	> File Name: p1809.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年03月20日 星期五 17时42分16秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m;
int svr[100010];
struct E{
    int f;
    int t;
    int w;
    int p;
}e[800010];
int le[100010];
int ed[100010];
int pp[100010];
int ec=1;

int spq[500010];
int qst,qed;
#define adq(a) spq[(qed++)%500009]=a
#define gtq ((spq[qst++])%500009)
#define teq (qst!=qed)

inline void ae(int & ef,int & et,int & ew)
{
    e[ec].f=ef;
    e[ec].t=et;
    e[ec].w=ew;
    e[ec].p=le[ef];
    le[ef]=ec++;
}
inline void ade(int e1,int e2,int ew)
{
    ae(e1,e2,ew);
    ae(e2,e1,ew);
}
inline void sp(int f)
{
    memset(ed,60,(n+5)*sizeof(int));
    ed[1]=0;
    adq(1);
    int NoE;
    int NoP;
    while(teq)
    {
        NoP=gtq;
        NoE=le[NoP];
        while(NoE)
        {
            #ifdef DEBUG
            printf("Now edge from %d to %d weight %d.\n",e[NoE],f,e[NoE].t,e[NoE].w);
            #endif
            if(ed[e[NoE].t]>ed[e[NoE].f]+e[NoE].w)
            {
                ed[e[NoE].t]=ed[e[NoE].f]+e[NoE].w;
                adq(e[NoE].t);
                pp[e[NoE].t]=NoE;
            }
            NoE=e[NoE].p;
        }
    }
}

inline int GtT(int a)
{
    while(pp[a])a=pp[a];
    return a;
}

int t1,t2,t3;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        ade(t1,t2,t3);
    }
    scanf("%d",&t1);
    for(int i=0;i<t1;i++)
    {
        scanf("%d",&t2);
        ade(n+1,t2,0);
    }
    sp(n+1);
    scanf("%d",&t1);
    for(int i=0;i<t1;i++)
    {
        scanf("%d",&svr[i]);
    }
    int svr
    return 0;
}
