/*************************************************************************
	> File Name: p1599.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年06月26日 星期五 16时40分17秒
 ************************************************************************/

#include<cstdio>
using namespace std;
long long fibtab[510]={1,1};
int main()
{
        int n,k;
        for(int i=2;i<501;i++)
        {
                fibtab[i]=(fibtab[i-1]+fibtab[i-2])%100003;
        }
        scanf("%d",&k);
        while(k--)
        {
                scanf("%d",&n);
                printf("%d\n",fibtab[n-1]);
        }
        return 0;
}
