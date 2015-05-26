#include<cstdio>
#include<cstdlib>
using namespace std;
struct NODE{
	int e,c,u,iec,oec,lev;
} nodes[120];
struct EDGE{
	int w,ne,f,t;
} edges[3000];
int edc=1;
int n,p,tmp1,tmp2,tmp3,maxlev;

inline void ae(int f,int t,int w)//from,to,weight
{
	edges[edc].f=f;
	edges[edc].t=t;
	edges[edc].w=w;
	edges[edc].ne=nodes[f].e;
	nodes[f].e=edc;
	edc++;
	nodes[f].oec++;
	nodes[t].iec++;
}

//Queue
int QUE[100000],QF,QT;
#define QEMP (QF==QT)
#define AQ(a) QUE[(QT++)%100000]=a
#define DQ QUE[(QF++)%100000]

//Update
inline void Update()
{
	while(!QEMP)
	{
		int NowN=DQ;
		int NowE=nodes[NowN].e;
		if(nodes[NowN].c>0)
		{
			while(NowE)
			{
				nodes[edges[NowE].t].c+=(nodes[NowN].c*edges[NowE].w);
				nodes[edges[NowE].t].lev=nodes[NowN].lev+1;
				maxlev=maxlev>nodes[edges[NowE].t].lev?maxlev:nodes[edges[NowE].t].lev;
				AQ(edges[NowE].t);
				NowE=edges[NowE].ne;
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&nodes[i].c,&nodes[i].u);
	}
	for(int i=0;i<p;i++)
	{
		scanf("%d%d%d",&tmp1,&tmp2,&tmp3);
		ae(tmp1,tmp2,tmp3);
	}
	for(int i=1;i<=n;i++)
	{
		if(!nodes[i].iec)AQ(i);
		else nodes[i].c-=nodes[i].u;
	}
	Update();
	int cntR=0;
	for(int i=1;i<=n;i++)
	{
		if((nodes[i].lev==maxlev)&&(nodes[i].c>0))
		{
			cntR++;
			printf("%d %d\n",i,nodes[i].c);
		}
	}
	if(!cntR)puts("NULL");
	return 0;
}
