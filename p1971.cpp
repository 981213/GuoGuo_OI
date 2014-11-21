/*************************************************************************
	> File Name: p1971.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年11月04日 星期二 09时56分09秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct CLOTHES{
    int value,m;
}clotha[100009],clothb[100009];
int sorttemp[100009];
int sortnums[100009];
int cust_compare(CLOTHES a ,CLOTHES b )
{
    return (a.value>b.value);
}
int Merge(int start,int mid,int end)
{
    memcpy(sorttemp+start,sortnums+start,(end-start+1)*sizeof(int));
    int i=start,j=mid+1,respoint=start,counter=0;
    while((i<=mid)&&(j<=end))
    {
        if(sorttemp[i]<sorttemp[j])
        {
            sortnums[respoint++]=sorttemp[i++];
        }
        else
        {
            sortnums[respoint++]=sorttemp[j++];
            counter+=(mid-i+1);
        }
    }
    while(i<=mid)
    {
        sortnums[respoint]=sorttemp[i];
        i++;
        respoint++;
    }
    while(j<=end)
    {
        sortnums[respoint]=sorttemp[j];
        j++;
        respoint++;
    }
    return counter;
}
int MergeSort(int start,int end)
{
    int counter=0;
    if(start<end)
    {
        int mid=(start+end)>>1;
        counter+=MergeSort(start,mid);
        counter+=MergeSort(mid+1,end);
        counter+=Merge(start,mid,end);
        counter%=99999997;
    }
    return counter;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&clotha[i].value);
        clotha[i].m=i;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&clothb[i].value);
        clothb[i].m=i;
    }
    sort(clotha,clotha+n,cust_compare);
    sort(clothb,clothb+n,cust_compare);
    for(int i=0;i<n;i++)
    {
        sortnums[clotha[i].m]=clothb[i].m;
        #ifdef DEBUG
        printf("%d ",sortnums[i]);
        #endif
    }
    printf("%d",MergeSort(0,n-1));
    #ifdef DEBUG
    for(int i=0;i<n;i++)
    {
        printf("%d ",sortnums[i]%99999997);
    }
    #endif
    return 0;
}
