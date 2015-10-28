/*************************************************************************
	> File Name: p1505_mark30.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月11日 星期五 18时03分10秒
 ************************************************************************/
//三十分暴力
#include<cstdio>
using namespace std;
long long ways[10]={1,1,1};
int n;
#define WAYD(a) ways[(a)%10]
int main()
{
        scanf("%d",&n);
        for(int i=3;i<=n;i++)
        {
                WAYD(i)=WAYD(i-1)+WAYD(i-3);
        }
        printf("%lld",WAYD(n));
        return 0;
}

