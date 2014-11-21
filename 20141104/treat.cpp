/*************************************************************************
	> File Name: treat.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年11月04日 星期二 17时16分48秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100009];
int n;
int sum;
bool cust_compare(int a,int b)
{
    return a>b;
}
int main()
{
    #ifndef DEBUG
    freopen("treat.in","r",stdin);
    freopen("treat.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int q;
    scanf("%d",&q);
    sort(a,a+n,cust_compare);
    for(int i=0;i<q;i++)
    {
        int ki;
        scanf("%d",&ki);
        for(int i=0;i<ki;i++)
        {
            sum+=a[i]--;
        }
    }
    cout<<sum;
    #ifndef DEBUG
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}
