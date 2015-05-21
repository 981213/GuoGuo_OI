/*************************************************************************
	> File Name: p1208.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年05月17日 星期日 09时27分31秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int map[6][6];
int vis[6][6];
int sx,sy,fx,fy;
int m,n,t;
int tmp1,tmp2;
int Ans;
#define Aval(x,y) ((x>0)&&(x<=m)&&(y>0)&&(y<=n)&&(!map[x][y])&&(!vis[x][y]))
#define TDFS(x,y) {if(Aval(x,y)){vis[x][y]=1;dfs(x,y);vis[x][y]=0;}}
void dfs(int x,int y)
{
    if((x==fx)&&(y==fy))
    {
        Ans++;
        return;
    }
    TDFS(x-1,y);
    TDFS(x,y-1);
    TDFS(x,y+1);
    TDFS(x+1,y);
}
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
    for(int i=0;i<t;i++)
    {
        scanf("%d%d",&tmp1,&tmp2);
        map[tmp1][tmp2]=1;
    }
    vis[sx][sy]=1;
    dfs(sx,sy);
    printf("%d",Ans);
    return 0;
}
