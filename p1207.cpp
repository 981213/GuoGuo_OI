/*************************************************************************
	> File Name: p1207.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年04月07日 星期二 16时20分52秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
unsigned char Aval[1005][1005];
unsigned char Vis[1005][1005];
struct Pnt{
    int x,y;
    bool operator == (const struct Pnt Another) const
    {
        return ((x==Another.x)&&(y==Another.y));
    }
};
struct Item {
    Pnt Cur;
    int Prev;
    int Len;
}ItemQue[1005*1005*100];
int QueT=1;
int QueH=1;
#define Push(A) ItemQue[QueT++]=A
#define Head ItemQue[QueH++]
#define Emp (QueT==QueH)
Pnt End;
Pnt Start;
int m,n,t;
#define PntAval(A) ((A.x>0)&&(A.x<=m)&&(A.y>0)&&(A.y<=n))
#define ItemAval(A) ((PntAval(A.Cur))&&(!Aval[A.Cur.x][A.Cur.y])&&(!(Vis[A.Cur.x][A.Cur.y])))
Item Now;
Item Temp;
inline void AddItem(int NowItem)
{
    if(Vis[ItemQue[NowItem].Cur.x][ItemQue[NowItem].Cur.y]) return;
    #ifdef DEBUG
    printf("Now Add QueItem %d (%d,%d)\n",NowItem,ItemQue[NowItem].Cur.x,ItemQue[NowItem].Cur.y);
    #endif
    Temp=ItemQue[NowItem];
    Vis[Temp.Cur.x][Temp.Cur.y]=1;
    Temp.Prev=NowItem;
    Temp.Len++;
    Temp.Cur.x--;
    if(ItemAval(Temp))Push(Temp);
    Temp.Cur.x+=2;
    if(ItemAval(Temp))Push(Temp);
    Temp.Cur.x--;
    Temp.Cur.y--;
    if(ItemAval(Temp))Push(Temp);
    Temp.Cur.y+=2;
    if(ItemAval(Temp))Push(Temp);
}
int tmpa,tmpb;
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    scanf("%d%d%d%d",&Start.x,&Start.y,&End.x,&End.y);
    for(int i=0;i<t;i++)
    {
        scanf("%d%d",&tmpa,&tmpb);
        Aval[tmpa][tmpb]=1;
    }
    bool Mark=0;
    Temp.Cur=End;
    Temp.Len=1;
    Temp.Prev=0;
    if(ItemAval(Temp)) //特判:如果起始搜索点有障碍物
        Push(Temp);
    while(!Emp)
    {
        Now=Head;
        if(Now.Cur==Start)
        {
            Mark=1;
            break;
        }
        AddItem(QueH-1);
    }
    if(Mark)
    {
        printf("%d\n",Now.Len);
        while(Now.Prev)
        {
            printf("%d %d\n",Now.Cur.x,Now.Cur.y);
            Now=ItemQue[Now.Prev];
        }
    printf("%d %d\n",Now.Cur.x,Now.Cur.y);
    } else {
        puts("-1");
    }
    return 0;
}
