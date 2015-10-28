/*************************************************************************
	> File Name: p1302.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月01日 星期二 17时37分09秒
 ************************************************************************/

#include<cstdio>
using namespace std;
inline long long gcd(long long a,long long b)
{
        long long c;
        while(b)
        {
                c=a%b;
                a=b;
                b=c;
        }
        return a;
}
int main()
{
        int T;
        scanf("%d\n",&T);
        long long a,b,c,d;
        while(T--)
        {
                scanf("%lld/%lld-%lld/%lld",&a,&b,&c,&d);
                register long long tmp=gcd(b,a);
                a/=tmp;
                b/=tmp;
                tmp=gcd(d,c);
                c/=tmp;
                d/=tmp;
                tmp=gcd(b,d);
                register long long ansm=b*d/tmp;
                a=a*d/tmp;
                c=c*b/tmp;
                register long long ansz=a-c;
                if(ansz==0)puts("0");
                else if(ansz%ansm==0)printf("%d\n",ansz/ansm);
                else{
                        tmp=gcd(ansz>0?ansz:-ansz,ansm);
                        ansm/=tmp;
                        ansz/=tmp;
                        printf("%lld/%lld\n",ansz,ansm);
                }
        }
        return 0;
}
