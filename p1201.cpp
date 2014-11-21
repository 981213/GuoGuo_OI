/*************************************************************************
	> File Name: p1201.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年11月02日 星期日 19时41分48秒
    >RMQ
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int dpnums[200010][20];
int pows2[30]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
int n;
int toplevel;
int cust_log(int a,int b)//log a b
{
    return int(log(float(b))/log(float(a)));
}
int cust_max(int a,int b)
{
    if(a>b) return a;else return b;
}
int cust_query(int a,int b)
{
    int query_lev=(int)log2((b-a+1));
    return cust_max(dpnums[a][query_lev],dpnums[b-pows2[query_lev]+1][query_lev]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&dpnums[i][0]);
    }
    //dpnums[i][j]从i起2^j个数的最大值
    //dpnums[i][j]=cust_max(dpnums[i][j-1],dpnums[i+2^(j-1)][j-1])
    int custpow=2;
    for(int j=1;custpow<=n;j++,custpow*=2)
    {
        for(int i=1;i+custpow-1<=n;i++)
        {
            dpnums[i][j]=cust_max(dpnums[i][j-1],dpnums[i+custpow/2][j-1]);
        }
    }
    #ifdef DEBUG
    for(int j=0;j<19;j++)
    {
        for(int i=0;i<=n;i++)
        {
            printf("%d      ",dpnums[i][j]);
        }
        printf("\n");
    }
    #endif
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",cust_query(a,b));
    }
    return 0;
}

