/*************************************************************************
	> File Name: p1756.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年04月21日 星期二 19时15分58秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
struct _SEGTREE_NODE {
    int l,r;
    int v;//minval
}tree[3000000];
inline int min(int a,int b){return a>b?b:a;}
int BuildTree(int node,int left,int right)
{
    tree[node].l=left;
    tree[node].r=right;
    if(left==right)
    {
        scanf("%d",&tree[node].v);
    } else {
        int mid=(left+right)>>1;
        tree[node].v=min(BuildTree(node*2,left,mid),BuildTree(node*2+1,mid+1,right));
    }
    return tree[node].v;
}
int Query(int node,int left,int right)
{
    if((tree[node].l>=left)&&(tree[node]));
}

int main()
{
    return 0;
}
