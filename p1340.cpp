/*************************************************************************
	> File Name: p1340.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月08日 星期二 16时05分46秒
 ************************************************************************/

#include<cstdio>
using namespace std;
//带取摸快速幂
long long fastpow(int baseval,int powval,int modnum)
{
        long long ans=1;
        while(powval)
        {
                if(powval&1)
                        ans=(ans*baseval)%modnum;
                baseval=(baseval*baseval)%modnum;
                powval>>=1;
        }
        return ans;
}
int t;
int n,x;
int nlist[100000];

inline bool checkans(int modnum)
{
        long long sumval=0;
        for(int i=0;i<=n;i++)
        {
                sumval=(sumval+nlist[i]*fastpow(x,n-i,modnum))%modnum;
        }
        return (sumval==0);
}

int main()
{
        scanf("%d",&t);
        while(t--)
        {
                //读入
                scanf("%d%d",&n,&x);
                for(register int i=0;i<=n;i++)
                        scanf("%d",nlist+i);
                printf("%d\n",(checkans(261529)&&checkans(259991)&&checkans(261389)));
                
        }
        return 0;
}
