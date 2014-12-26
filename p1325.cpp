/*************************************************************************
	> File Name: p325.cpp priority_queue
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年09月28日 星期日 12时22分43秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
priority_queue<long long,vector<long long>,greater<long long> > fruit;
int main()
{
    int n;
    scanf("%d",&n);
    long long counter=0;
    for (int i=0;i<n;i++)
    {
        int temp1;
        scanf("%d",&temp1);
        fruit.push(temp1);
    }
    while( fruit.size() != 1 )
    {
        long long temp2=fruit.top();
        fruit.pop();
        temp2+=fruit.top();
        fruit.pop();
        fruit.push(temp2);
        counter+=temp2;
    }
    printf("%lld",counter);
    return 0;
}
