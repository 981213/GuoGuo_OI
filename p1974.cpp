/*************************************************************************
	> File Name: p1974.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年11月06日 星期四 13时09分55秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int cust_abs(int a)
{
    return a>0?a:-a;
}
int main()
{
    int n;
    scanf("%d",&n);
    int maxnum=2;
    int prev;
    bool fullequal=1;
    scanf("%d",&prev);
    int prevstate=1;//< = >
    for(int i=1;i<n;i++)
    {
        int temp;
        scanf("%d",&temp);
        int nowstate;
        if(temp==prev)
        {
            nowstate=1;
        }
        else if(temp<prev)
        {
            nowstate=0;
            fullequal=0;
        }
        else if(temp>prev)
        {
            nowstate=2;
            fullequal=0;
        }
        if(cust_abs(nowstate-prevstate)==2)
        {
            maxnum++;
        }
        prevstate=nowstate;
        prev=temp;
    }
    if(fullequal)maxnum=1;
    printf("%d",maxnum);
    return 0;
}
