/*************************************************************************
	> File Name: ada.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年11月12日 星期三 18时35分15秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int nums[20][20];
int n,m,k;
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d",&k);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&nums[n][m]);
        }
    }

    return 0;
}
