/*************************************************************************
	> File Name: p1970.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年11月03日 星期一 20时29分36秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
long long FASTPOW(long long a,long long b,long long modnum)
{
    int result=1;
    while(b!=0)
    {
        if(b&1)
        {
            result=result*a%modnum;
        }
        a=a*a%modnum;
        b>>=1;
    }
    return result;
}
int main()
{
    long long n,m,k,x;
    cin>>n>>m>>k>>x;
    cout<<(FASTPOW(10,k,n)*m+x)%n;
    return 0;
}
