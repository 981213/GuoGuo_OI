/*************************************************************************
	> File Name: p2241_60.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月22日 星期二 16时35分24秒
 ************************************************************************/
//60分暴力，a*b/gcd(a,b)
#include<cstdio>
using namespace std;
long long gcd(long long a,long long b)
{
        return b==0?a:gcd(b,a%b);
}
long long val,ans;
int main()
{
        scanf("%lld",&val);
        ans=1;
        for(register long long i=1;i<=val;i++)
        {
                ans=(ans*i/gcd(ans,i))%10000019;
        }
        printf("%lld",ans);
        return 0;
}
