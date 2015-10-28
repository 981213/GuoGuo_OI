/*************************************************************************
	> File Name: prime_template.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月25日 星期五 19时13分07秒
 ************************************************************************/

#include<cstdio>
using namespace std;
#define MAXN 100000
bool notprime[MAXN];
int primetab[MAXN];
int nprime=0;
inline void MakePrimeTab(int num)
{
        notprime[0]=1;
        notprime[1]=1;
        for(int i=2;i<=num;i++)
        {
                if(!notprime[i])primetab[nprime++]=i;
                for(int j=0;(j<nprime)&&(i*primetab[j]<=num);j++)
                {
                        notprime[i*primetab[j]]=1;
                        if(!(i%primetab[j]))break;
                }
        }
}

int main()
{
        int n;
        scanf("%d",&n);
        MakePrimeTab(n);
        for(int i=0;i<nprime;i++)printf("%d ",primetab[i]);
        return 0;
}
