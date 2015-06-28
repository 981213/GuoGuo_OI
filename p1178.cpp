/*************************************************************************
	> File Name: p1178.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年06月28日 星期日 13时21分16秒
 ************************************************************************/

#include<cstdio>
using namespace std;
int markcnt[620];
int maxmark;
int main()
{
    register int n,k,tmp,ans,ans2;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        markcnt[tmp]++;
        maxmark=tmp>maxmark?tmp:maxmark;
    }
    for(int i=0;i<k;i++)
    {
        scanf("%d",&tmp);
        if(!markcnt[tmp])
        {
            puts("Fail!");
            continue;
        }
        ans=0;
        ans2=1;
        for(int i=maxmark;i>tmp;i--)
        {
            if(markcnt[i])
            {
                ans+=markcnt[i];
                ans2++;
            }
        }
        printf("%d %d %d\n",ans2,markcnt[tmp],ans);
    }
    return 0;
}
