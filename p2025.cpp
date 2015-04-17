/*************************************************************************
	> File Name: p2025.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年04月17日 星期五 16时03分40秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
struct _SEGNODE
{
    int Left,Right;
    int Val;
    int SumLazy;
}SegTree[300000];
int n,q;
int BuildTree(int NodeNum,int Left,int Right)
{
    SegTree[NodeNum].Left=Left;
    SegTree[NodeNum].Right=Right;
    if(Left==Right)
    {
        scanf("%d",&SegTree[NodeNum].Val);
        return SegTree[NodeNum].Val;
    } else {
        int Mid=(Left+Right)>>1;
        return (SegTree[NodeNum].Val=(BuildTree(NodeNum*2,Left,Mid)+BuildTree(NodeNum*2+1,Mid+1,Right)));
    }
}
void PushDown(int NodeNum)
{
    if(SegTree[NodeNum].Left==SegTree[NodeNum].Right) return;
    SegTree[NodeNum*2].SumLazy+=SegTree[NodeNum].SumLazy;
    SegTree[NodeNum*2+1].SumLazy+=SegTree[NodeNum].SumLazy;
    SegTree[NodeNum].Val+=(SegTree[NodeNum].SumLazy*(SegTree[NodeNum].Right-SegTree[NodeNum].Left+1));
    SegTree[NodeNum].SumLazy=0;
}
void PushUp(int NodeNum,int Val)
{
    NodeNum>>=1;
    while(NodeNum)
    {
        SegTree[NodeNum].Val+=Val;
        NodeNum>>=1;
    }
}
int QuerySum(int NodeNum,int Left,int Right)
{
    if((SegTree[NodeNum].Left>=Left)&&(SegTree[NodeNum].Right<=Right))
    {
        return SegTree[NodeNum].Val+SegTree[NodeNum].SumLazy*(SegTree[NodeNum].Right-SegTree[NodeNum].Left+1);
    } else if((SegTree[NodeNum].Left>Right)||(SegTree[NodeNum].Right<Left)) {
        return 0;
    } else {
        return QuerySum(NodeNum*2,Left,Right)+QuerySum(NodeNum*2+1,Left,Right);
    }
}
int AddNum(int NodeNum,int Left,int Right,int Val)
{
    if(SegTree[NodeNum].SumLazy)PushDown(NodeNum);
    if((SegTree[NodeNum].Left>=Left)&&(SegTree[NodeNum].Right<=Right))
    {
        SegTree[NodeNum].SumLazy+=Val;
    } else if((SegTree[NodeNum].Left>Right)||(SegTree[NodeNum].Right<Left)) {
        return 0;
    } else {
        AddNum(NodeNum*2,Left,Right,Val);
        AddNum(NodeNum*2+1,Left,Right,Val);
        return 0;
    }
    PushUp(NodeNum,(Right-Left)*Val);
}
int Opt,Val1,Val2,Val3;
int main()
{
    scanf("%d%d",&n,&q);
    BuildTree(1,1,n);
    for(int i=0;i<q;i++)
    {
        scanf("%d%d%d",&Opt,&Val1,&Val2);
        if(Opt)
        {
            scanf("%d",&Val3);
            AddNum(1,Val1,Val2,Val3);

        } else {
            printf("%d\n",QuerySum(1,Val1,Val2));
        }
    }
    return 0;
}
