/*************************************************************************
	> File Name: p1281.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年06月09日 星期二 19时02分17秒
 ************************************************************************/

#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct _TASK{
        long long mark,time;
        bool operator<( const struct _TASK another ) const
        {
                return mark>another.mark;
        }
} tasks[1000010];
priority_queue<struct _TASK> tskhp;
int n,fa[700010];
long long sum;
int maxtime;
int getfa(int num)
{
        if(num==fa[num])return num;
        return fa[num]=getfa(fa[num]);
}
int main()
{
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
                scanf("%d%d",&tasks[i].time,&tasks[i].mark);
                if(tasks[i].time>maxtime)maxtime=tasks[i].time;
        }
        for(int i=1;i<=maxtime;i++)fa[i]=i;
        sort(tasks,tasks+n);
        int nowfa;
        for(int i=0;i<n;i++)
        {
                nowfa=getfa(tasks[i].time);
                if(nowfa)
                {
                        sum+=tasks[i].mark;
                        fa[nowfa]=getfa(nowfa-1);
                }
        }
        printf("%lld",sum);
        return 0;
}
