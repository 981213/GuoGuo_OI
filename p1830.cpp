/*************************************************************************
	> File Name: p1830.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月25日 星期五 16时46分45秒
 ************************************************************************/
#include<cstdio>
//30分，n^2枚举。。。。。。
using namespace std;
int n;
int main()
{
        scanf("%d",&n);
        long long ans=0;
        for(register int i=1;i<=n;i++)
                for(register int j=1;j<i;j++)
                        if(!(i%j))ans++;
        printf("%d",ans);
        return 0;
}
