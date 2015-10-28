/*************************************************************************
	> File Name: p1767.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月18日 星期五 16时03分08秒
 ************************************************************************/

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
//EDGE
struct _EDGE_T{
        int from,to,weight,nexte;
}edges[1000*2+10];
int edc=1;
int nle[1000+10];
inline void AddEdge(int & from,int & to,int & weight)
{
        edges[edc].from=from;
        edges[edc].to=to;
        edges[edc].weight=weight;
        edges[edc].nexte=nle[from];
        nle[from]=edc;
        edc++;
}
inline void AddDEdge(int & a,int & b,int & weight)
{
        AddEdge(a,b,weight);
        AddEdge(b,a,weight);
}
//SPFA
int ndist[1010];
//SPFA_QUEUE
#define TOTQ 40100
int QUE[TOTQ];
int QH=0,QT=0;
#define ADQ(a) QUE[(QT++)%TOTQ]=a
#define DEQ() QUE[(QH++)%TOTQ]
#define QHAS() (QH!=QT)
int spfa(int start,int end)
{
        memset(ndist,60,sizeof(ndist));
        QH=0;
        QT=0;
        ndist[start]=0;
        ADQ(start);
        register int CurN,CurE;
        while(QHAS())
        {
                CurN=DEQ();
                CurE=nle[CurN];
                while(CurE)
                {
                        if(ndist[CurN]+edges[CurE].weight<ndist[edges[CurE].to])
                        {
                                ndist[edges[CurE].to]=ndist[CurN]+edges[CurE].weight;
                                ADQ(edges[CurE].to);
                        }
                        CurE=edges[CurE].nexte;
                }
        }
        return ndist[end];
}
//main
int h,k;
int n,m,s,t;
int tmp1,tmp2,tmp3;
int anslist[105];
int main()
{
        scanf("%d%d",&h,&k);
        if(h==k)//20%数据
        {
                puts("0");
                return 0;
        }
        for(int curlay=0;curlay<h;curlay++)
        {
                edc=1;
                scanf("%d%d%d%d",&n,&m,&s,&t);
                memset(nle,0,(n+2)*sizeof(int));
                for(int i=0;i<m;i++)
                {
                        scanf("%d%d%d",&tmp1,&tmp2,&tmp3);
                        AddDEdge(tmp1,tmp2,tmp3);
                }
                anslist[curlay]=spfa(s,t);
        }
        sort(anslist,anslist+h);
        int totans=0;
        for(int i=0;i<h-k;i++)totans+=anslist[i];
        printf("%d",totans);
        return 0;
}
