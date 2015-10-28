/*************************************************************************
	> File Name: p2219.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年10月16日 星期五 17时33分41秒
 ************************************************************************/

#include<cstdio>
using namespace std;
int n,x,y;
int main()
{
        scanf("%d%d%d",&n,&x,&y);
        int ans=n-(y/x)-(!!(y%x));
        printf("%d",ans>0?ans:0);
        return 0;
}
