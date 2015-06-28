/*************************************************************************
	> File Name: p1202.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年10月28日 星期二 12时28分39秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int q,p,n;
int TotN;
unsigned char IfSched[1000][1000];
int ans[1000];
int anscnt;
#define AdA(a) ans[anscnt++]=a
void dfs(int nowq,int nowp)
{
    if(IfSched[nowq][nowp])return;
    IfSched[nowq][nowp]=1;
    int nown=n-nowq-nowp;
    if(nowq==0)AdA(nown);
    //n->p
    if(p-nowp>nown)dfs(nowq,nowp+nown);else dfs(nowq,p);
    //n->q
    if(q-nowq>nown)dfs(nowq+nown,nowp);else dfs(q,nowp);
    //p->q
    if(q-nowq>nowp)dfs(nowq+nowp,0);else dfs(q,nowp-q+nowq);
    //q->p
    if(p-nowp>nowq)dfs(0,nowq+nowp);else dfs(nowq-p+nowp,p);
    //p->n
    if(n-nown>nowp)dfs(nowq,0);else dfs(nowq,nowp-n+nown);
    //q->n
    if(n-nown>nowq)dfs(0,nowp);else dfs(nowq-n+nown,nowp);
}
int main()
{
    scanf("%d%d%d",&q,&p,&n);
    TotN=n;
    dfs(0,0);
    sort(ans,ans+anscnt);
    for(int i=0;i<anscnt;i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}
