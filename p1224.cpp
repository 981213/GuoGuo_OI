/*************************************************************************
	> File Name: p1224.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年01月04日 星期日 18时30分07秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int DPNums[200010];
int n;
int i;
int start=1;
int numcounts=1;
int Temp;
int Head,Tail,Mid;
inline void Find_And_Insert(int & num)
{
    Head=1;
    Tail=numcounts;
    if(DPNums[Tail]<num)
    {
        DPNums[++numcounts]=num;
        return;
    }
    if(DPNums[Head]>num)
    {
        DPNums[Head]=num;
        return;
    }
    while(Tail-Head!=1)
    {
        Mid=(Head+Tail)>>1;
        if(DPNums[Mid]<num)
        {
            Head=Mid;
        }
        else
        {
            Tail=Mid;
        }
    }
    DPNums[Tail]=num;
}
int main()
{
    scanf("%d",&n);
    scanf("%d",&DPNums[1]);
    for(i=1;i<n;i++)
    {
        scanf("%d",&Temp);
        Find_And_Insert(Temp);
    }
    printf("%d",numcounts);
    return 0;
}
