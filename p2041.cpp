/*************************************************************************
	> File Name: treat.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年12月16日 星期二 17时33分44秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
priority_queue<int> HEAP;
stack<int> TEMPSTACK;
int n,q;
long long Sum;
inline void TreatN(int k)
{
    int temp2;
    for(int i=0;i<k;i++)
    {
        temp2=HEAP.top();
        HEAP.pop();
        Sum+=temp2;
        TEMPSTACK.push(temp2-1);
    }
    while(!TEMPSTACK.empty())
    {
        HEAP.push(TEMPSTACK.top());
        TEMPSTACK.pop();
    }
}
int main()
{
    scanf("%d",&n);
    int temp;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        HEAP.push(temp);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d",&temp);
        TreatN(temp);
    }
    printf("%lld",Sum);
#ifndef DEBUG
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
