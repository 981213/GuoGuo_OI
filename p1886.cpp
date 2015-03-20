/*************************************************************************
	> File Name: p1886.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年03月06日 星期五 16时31分44秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    long long p,q;
    scanf("%lld%lld",&p,&q);
    long long maxa=(p-1)/2;
    long long maxb=(q-1)/2;
    long long sum=0;
    for(int i=1;i<=maxa;i++)
    {
        sum+=(long long)((i*q)/p);
    }
    for(int i=1;i<=maxb;i++)
    {
        sum+=(long long)((i*p)/q);
    }
    printf("%lld",sum);
    return 0;
}
