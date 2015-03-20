/*************************************************************************
	> File Name: p1880.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年03月06日 星期五 16时10分58秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
#define SUM(a,b) (((a+b)*(b-a+1))/2)
long long n,k;
int main()
{
    scanf("%lld%lld",&n,&k);
    if(n>(SUM(2,k-1))+2)
    {
        puts("-1");
    }
    else if(k>=n)
    {
        puts("1");
    }
    else{
        long long start=1,end=k-1;
        long long mid;
        while(end-start!=1)
        {
            #ifdef DEBUG
            cout<<start<<","<<end<<endl;
            #endif
            mid=(start+end)>>1;
            #ifdef DEBUG
            cout<<"MID="<<mid<<" SUM="<<SUM(mid,k-1)+(mid)+1<<endl<<endl;
            #endif
            if(SUM(mid,k-1)+(mid)-1>=n)
            {
                start=mid;
            }
            else
            {
                end=mid;
            }
        }
        printf("%lld",k-start+1);
    }
    return 0;
}
