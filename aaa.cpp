/*************************************************************************
	> File Name: p1759.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年03月20日 星期五 16时11分34秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
#include<cstring>

using namespace std;

map<string,int> stmap;
string temp;
int temp2;

int n,m;
int nmcnt;

struct E{
    int f;
    int t;
    int w;
    int p;
}e[200010];
int le[50010];
int ed[50010];
int ec=1;

int spq[200010];
int qst,qed;
#define adq(a) spq[(qed++)%200009]=a
#define gtq ((spq[qst++])%200009)
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
            }
            NoE=e[NoE].p;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        stmap[temp]=(++nmcnt);
    }
    for(int i=0;i<m;i++)
    {
        cin>>temp;
        int Fr=stmap[temp];
        cin>>temp;
        int To=stmap[temp];
        scanf("%d",&temp2);
        if(Fr!=To)
        ade(Fr,To,temp2);
    }
    sp(1);
    printf("%d",ed[2]);
    return 0;
}

