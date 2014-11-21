/*************************************************************************
	> File Name: p1583.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年11月14日 星期五 16时06分03秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int nums[7][7];
int T,n,m;
int marks[7][7];
int _maxnum=0;
int markrange[]={-1,0,1};
int calrangex[]={-2,-2,-2,-2,-2,-1,-1,-1,-1,-1, 0, 0,0,0, 1, 1,1,1,1, 2, 2,2,2,2};
int calrangey[]={-2,-1, 0, 1, 2,-2,-1, 0, 1, 2,-2,-1,1,2,-2,-1,0,1,2,-2,-1,0,1,2};
int cust_max(int a,int b)
{
    return a>b?a:b;
}
int cal_pnt(int x,int y,int _level,bool toplevel=0)
{
    if(marks[x][y])return 0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int mkxtemp=x+markrange[i];
            int mkytemp=y+markrange[j];
            if((mkxtemp>=0)&&(mkxtemp<n)&&(mkytemp>=0)&&(mkytemp<m))marks[mkxtemp][mkytemp]++;
        }
    }
    int cal_max_num=0;
    for(int i=0;i<24;i++)
    {
        int mkxtemp=x+calrangex[i];
        int mkytemp=y+calrangey[i];
        if((mkxtemp>=0)&&(mkxtemp<n)&&(mkytemp>=0)&&(mkytemp<m))
        {
            cal_max_num=cust_max(cal_pnt(mkxtemp,mkytemp,_level+1),cal_max_num);
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int mkxtemp=x+markrange[i];
            int mkytemp=y+markrange[j];
            if((mkxtemp>=0)&&(mkxtemp<n)&&(mkytemp>=0)&&(mkytemp<m))marks[mkxtemp][mkytemp]--;
        }
    }
    cal_max_num+=nums[x][y];
    return cal_max_num;
}
void max_calculate()
{
    _maxnum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            memset(marks,0,sizeof(int)*7*7);
            _maxnum=cust_max(cal_pnt(i,j,0,1),_maxnum);
        }
    }
}
int main()
{
    scanf("%d",&T);
    for(;T>0;T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&nums[i][j]);
            }
        }
        max_calculate();
        printf("%d\n",_maxnum);
    }
    return 0;
}
