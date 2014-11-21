/*************************************************************************
	> File Name: p1200.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年11月20日 星期四 20时58分09秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int routernum,n;
int homes[100010];
bool check_avail(float numtocheck)
{
    #ifdef DEBUG
    cout<<numtocheck<<endl;
    #endif
    float covered=homes[0]-11111;
    int routercount=0;
    for(int i=0;i<n;i++)
    {
        if(homes[i]<=covered)continue;
        #ifdef DEBUG
        cout<<"Put a router at"<<homes[i];
        #endif
        covered=homes[i]+numtocheck*2;
        routercount++;
        #ifdef DEBUG
        cout<<"Now covered "<<covered<<endl;
        #endif
        if(routercount>routernum)return 0;
    }
    return 1;
}
float cust_abs(float a)
{
    return a<0?-a:a;
}
int main()
{
    scanf("%d%d",&routernum,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&homes[i]);
    }
    sort(homes,homes+n);
    float ansleft=0,ansright=homes[n-1];
    while(cust_abs(ansleft-ansright)>=0.01)
    {
        float ansmid=(ansleft+ansright)/2;
        if(check_avail(ansmid))
        {
            ansright=ansmid;
        }
        else
        {
            ansleft=ansmid;
        }
    }
    printf("%.1f",ansright);
    return 0;
}
