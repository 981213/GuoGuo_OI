/*************************************************************************
	> File Name: p1174.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年06月19日 星期五 18时20分31秒
 ************************************************************************/

#include<cstdio>
using namespace std;
unsigned char ifprime[1000010];
unsigned int  prime[1000000],primecnt=0;
int n;
int main()
{
        scanf("%d",&n);
        for(int i=2;i<=n;i++)
        {
                (!ifprime[i])&&(prime[primecnt++]=i);
                for(int j=0;((j<primecnt)&&(i*prime[j]<=n));j++)
                {
                        ifprime[i*prime[j]]=1;
                        if(!(i%prime[j]))break;
                }
        }
        for(int i=0;i<primecnt;i++)
        {
                printf("%d ",prime[i]);
        }
        return 0;
}
