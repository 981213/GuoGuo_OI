/*************************************************************************
	> File Name: calc.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年10月21日 星期二 16时08分46秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a,b,k,n,m;
long long aaaaa(int _in,int _in2)//阶乘
{
    long long _result=1;
    for(long long i=_in;i>=_in2;i--)
    {
        _result=(_result*i);
    }
    return _result;
}
long long _c(int _m,int _n)//组合
{
    return ((aaaaa(_m,_m-_n+1))/(aaaaa(_n,1)));
}
int main()
{
    #ifndef DEBUG
    freopen("calc.in","r",stdin);
    freopen("calc.out","w",stdout);
    #endif
    cin>>a>>b>>k>>n>>m;
    cout<<((long long)(((_c(k,(k-int(max(float(k-n+1),float(k-m+1)))+1)))*pow(a,n)*pow(b,m)))%10007);
    #ifndef DEBUG
    fclose(stdin);
    fclose(stdout);
    #endif
}
