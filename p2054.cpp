/*************************************************************************
	> File Name: p2054.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年03月13日 星期五 19时07分18秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int nums[1000010];
int nnum;
inline long long FuncJudge(int & x)
{
    long long Ans=0;
    for(int i=0;i<nnum;i++)
    {
        Ans+=(nums[i]/x+nums[i]%x);
    }
    return Ans;
}
int main()
{
    int left=1,right=0;
    scanf("%d",&nnum);
    for(int i=0;i<nnum;i++)
    {
        scanf("%d",&nums[i]);
        if(nums[i]>right)right=nums[i];
    }
    #ifdef DEBUG
    puts("BOOMFUNC!!!");
    for(int i=1;i<=right;i++)
    {
        printf("CalAns for %d:%lld\n",i,FuncJudge(i));
    }
    #endif
    int mid,mmid;
    while((right-left)>1)
    {
        #ifdef DEBUG
        printf("Step.Left=%d Right= %d \n",left,right);
        #endif
        mid=(left+right)>>1;
        mmid=(mid+right)>>1;
        #ifdef DEBUG
        printf("mid=%d mmid=%d \nFunc %lld %lld\n",mid,mmid,FuncJudge(mid),FuncJudge(mmid));
        #endif
        if(FuncJudge(mid)<FuncJudge(mmid))
        {
            right=mmid;
        } else {
            left=mid;
        }
    }
    printf("%d",((FuncJudge(left)<FuncJudge(right)?left:right)));
    return 0;
}
