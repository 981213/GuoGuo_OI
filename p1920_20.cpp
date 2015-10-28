/*************************************************************************
	> File Name: p1920_20.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月25日 星期五 18时54分17秒
 ************************************************************************/
//骗分……
#include<cstdio>
using namespace std;
int main()
{
        int maxval=2147483647;
        int tmpval;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
                scanf("%d",&tmpval);
                maxval=maxval>tmpval?tmpval:maxval;
        }
        printf("%d",n*maxval);
        return 0;
}

