/*************************************************************************
	> File Name: p1143.cpp 30分暴力
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月08日 星期二 16时42分43秒
 ************************************************************************/

#include<cstdio>
using namespace std;

int n;
int tasklist[21][2];
int minval=2147483640;
//暴力算法，30分 O(2^n)
void dfs(int layer,int atime,int btime)
{
        if(layer==n)
        {
                register int tmp=atime>btime?atime:btime;
                minval=minval<tmp?minval:tmp;
        }
        else
        {
                dfs(layer+1,atime+tasklist[layer][0],btime);
                dfs(layer+1,atime,btime+tasklist[layer][1]);
        }
}
int main()
{
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
                scanf("%d%d",tasklist[i],tasklist[i]+1);
        }
        dfs(0,0,0);
        printf("%d",minval);
        return 0;
}
