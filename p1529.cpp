/*************************************************************************
	> File Name: p1529.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年06月27日 星期六 17时45分04秒
 ************************************************************************/

#include<cstdio>
using namespace std;
//Nodes
int laste[20000100],
visited[20000100],
//Edges
efrom[20000010],
eto[20000010],
ene[20000010],
edc=1,
FNCnt=1000010,
n,m;

inline void AddEdge(int from,int to)
{
    efrom[edc]=from;
    eto[edc]=to;
    ene[edc]=laste[from];
    laste[from]=edc;
    edc++;
}
//Queue
#define QuSz 20001000
struct QuItem{
    int node,step;
} Que[QuSz];
int QuH,QuT;
#define AdQ(a) Que[(QuH++)]=a
#define DeQ() Que[(QuT++)]
#define QEMP QuH==QuT
//这TM是我第一次用输入优化!!
int aa,bb;char ch;int scan(){
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');ch=='-'?aa=bb=0:(aa=ch-'0',bb=1);
	while(ch=getchar(),ch>='0'&&ch<='9')aa=aa*10+ch-'0';return bb?aa:-aa;
}

int main()
{
    n=scan();m=scan();
    register int from,to,len;
    while(m--)
    {
        from=scan();to=scan();len=scan();
        if(len==1)
        {
            AddEdge(from,to);
        }
        else
        {
            AddEdge(from,FNCnt);
            AddEdge(FNCnt++,to);
        }
    }
    register struct QuItem tmpitem,nown;
    tmpitem.node=1;
    tmpitem.step=0;
    AdQ(tmpitem);
    while(QuH!=QuT)
    {
        nown=DeQ();
        if(nown.node==n)break;
        if(visited[nown.node])continue;
        visited[nown.node]=1;
        register int nowe=laste[nown.node];
        while(nowe)
        {
            if(visited[eto[nowe]])goto ne;
            tmpitem.node=eto[nowe];
            tmpitem.step=nown.step+1;
            AdQ(tmpitem);
            ne:
            nowe=ene[nowe];
        }
    }
    printf("%d",nown.step);
    return 0;
}

