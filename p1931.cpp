/*************************************************************************
	> File Name: p1931.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年12月29日 星期一 12时34分50秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
long long numlist[1000010];
int n,m,i;
long long temp,temp2,temp3;
int main()
{
    scanf("%d%d%d",&n,&m,&numlist[1]);
    temp=numlist[1];

    for(i=2;i<=n;i++)
    {
        temp2=temp;
        scanf("%lld",&temp);
        numlist[i]=temp-temp2;
    }
    for(i=0;i<m;i++)
    {
        scanf("%lld%lld%lld",&temp,&temp2,&temp3);
        numlist[temp]+=temp3;
        numlist[temp2+1]-=temp3;
    }
    temp=numlist[1];
    for(i=1;i<=n;i++)
    {
        printf("%lld\n",temp);
        temp+=numlist[i+1];
    }
    return 0;
}
