/*************************************************************************
	> File Name: classroom.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年11月04日 星期二 18时09分07秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int avail_class[1000010];
int temp_avail_class[1000010];
struct ORDER
{
    int dj,sj,tj;
}orders[1000010];
bool cust_check(int end)
{
    memcpy(temp_avail_class,avail_class,(n+1)*sizeof(int));
    for(int i=1;i<=end;i++)
    {
        temp_avail_class[orders[i].sj]-=orders[i].dj;
        temp_avail_class[orders[i].tj+1]+=orders[i].dj;
    }
    int prev=0;
    for(int i=1;i<=n;i++)
    {
        prev=prev+temp_avail_class[i];
        if(prev<0)return 0;
    }
    return 1;
}
int main()
{
    scanf("%d %d",&n,&m);
    int prev=0;
    for(int i=1;i<=n;i++)
    {
        int temp;
        scanf("%d",&temp);
        avail_class[i]=temp-prev;
        prev=temp;
    }//读入数据并建立差分序列
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&orders[i].dj,&orders[i].sj,&orders[i].tj);
    }//读入订单
    int temp_part=m;
    int value_start=1;
    int value_end=m;
    if(cust_check(m))
    {
        printf("0");
    }
    else{
        while(value_start!=value_end)
        {
            int mid=(value_start+value_end)>>1;
            if(cust_check(mid))
            {
                #ifdef DEBUG
                printf("cust_check(%d)succeed!\n",mid);
                #endif
                value_start=mid+1;
            }
            else
            {
                #ifdef DEBUG
                printf("cust_check(%d)failed!\n",mid);
                #endif
                value_end=mid;
            }
        }
        printf("-1\n%d",value_start);
    }
    return 0;
}
