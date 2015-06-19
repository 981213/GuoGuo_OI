/*************************************************************************
	> File Name: p1503.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年06月14日 星期日 10时09分12秒
 ************************************************************************/

#include<cstdio>
using namespace std;
long long ways[100]={1,1,1},n;
int main()
{
        scanf("%d",&n);
        for(int i=3;i<=n;i++)
        {
                ways[i]=ways[i-1]+ways[i-3];
        }
        printf("%lld",ways[n]);
        return 0;
}
