/*************************************************************************
	> File Name: p1973.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年11月05日 星期三 18时40分36秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    int counter=0;
    scanf("%d",&n);
    int prev=0;
    for(int i=1;i<=n;i++)
    {
        int temp;
        scanf("%d",&temp);
        if(temp-prev>0)
        {
            counter+=temp-prev;
        }
        prev=temp;
    }
    printf("%d",counter);
    return 0;
}
