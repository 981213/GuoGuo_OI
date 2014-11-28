/*************************************************************************
	> File Name: p1596.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年11月28日 星期五 12时47分40秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int nums[200010];
int numstat[200010];
int n;
int maxnum=-1<<30;
inline int getnowstat(int bt)
{
    return numstat[bt-1]<0?nums[bt]:numstat[bt-1]+nums[bt];
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&nums[i]);
    }
    numstat[0]=nums[0];
    for(int i=1;i<n;i++)
    {
        numstat[i]=getnowstat(i);
        if(numstat[i]>maxnum)maxnum=numstat[i];
    }
    printf("%d",maxnum);
    return 0;
}
