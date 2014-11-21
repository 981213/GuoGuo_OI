/*************************************************************************
	> File Name: p1182.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年10月26日 星期日 20时14分18秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
map<int,int> numcount;
map<int,bool> ifnum;
set<int> nums;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int num;
        scanf("%d",&num);
        if(ifnum[num])
        {
            numcount[num]++;
        }
        else
        {
            ifnum[num]=1;
            numcount[num]=1;
            nums.insert(num);
        }
    }
    for(set<int>::iterator it =nums.begin();it!=nums.end();++it)
    {
        printf("%d %d\n",(*it),numcount[*it]);
    }
    return 0;
}

