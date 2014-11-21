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
int cust_max(int a,int b)
{
    return a>b?a:b;
}
int cal_pnt(int x,int y,int _level,bool toplevel=0)
{
    #ifdef DEBUG
    if(toplevel)cout<<"=========Top========"<<endl;
    for(int i=0;i<_level;i++)cout<<"    ";
    cout<<"cal_"<<x<<" "<<y<<" "<<marks[x][y]<<endl;
    #endif
    if(marks[x][y]>0) return 0;
    if(x-1>=0)
    {
        if(y-1>=0) marks[x-1][y-1]=(marks[x-1][y-1]==2?2:1);
        if(1) marks[x-1][y]=(marks[x-1][y]==2?2:1);
        if(y+1<m) marks[x-1][y+1]=(marks[x-1][y+1]==2?2:1);
    }
    if(1)
    {
        if(y-1>=0) marks[x][y-1]=(marks[x][y-1]==2?2:1);
        if(1) marks[x][y]=(marks[x][y]==2?2:1);
        if(y+1<m) marks[x][y+1]=(marks[x][y+1]==2?2:1);
    }
    if(x+1<n)
    {
        if(y-1>=0) marks[x+1][y-1]=(marks[x+1][y-1]==2?2:1);
        if(1) marks[x+1][y]=(marks[x+1][y]==2?2:1);
        if(y+1<m) marks[x+1][y+1]=(marks[x+1][y+1]==2?2:1);
    }

    int cal_max_num=0;
    if(x-2>=0)
    {
        if((y-2>=0)&&(!marks[x-2][y-2])) cal_max_num=cust_max(cal_max_num,cal_pnt(x-2,y-2,_level+1));
        if((y-1>=0)&&(!marks[x-2][y-1])) cal_max_num=cust_max(cal_max_num,cal_pnt(x-2,y-1,_level+1));
        if(!marks[x-2][y]) cal_max_num=cust_max(cal_pnt(x-2,y,_level+1),cal_max_num);
        if((y+1<m)&&(!marks[x-2][y+1])) cal_max_num=cust_max(cal_max_num,cal_pnt(x-2,y+1,_level+1));
        if((y+2<m)&&(!marks[x-2][y+2])) cal_max_num=cust_max(cal_pnt(x-2,y+2,_level+1),cal_max_num);
    }
    if(x-1>=0)
    {
        if((y-2>=0)&&(!marks[x-1][y-2])) cal_max_num=cust_max(cal_max_num,cal_pnt(x-1,y-2,_level+1));
        if((y-1>=0)&&(!marks[x-1][y-1])) cal_max_num=cust_max(cal_max_num,cal_pnt(x-1,y-1,_level+1));
        if(!marks[x-1][y]) cal_max_num=cust_max(cal_pnt(x-1,y,_level+1),cal_max_num);
        if((y+1<m)&&(!marks[x-1][y+1])) cal_max_num=cust_max(cal_max_num,cal_pnt(x-1,y+1,_level+1));
        if((y+2<m)&&(!marks[x-1][y+2])) cal_max_num=cust_max(cal_pnt(x-1,y+2,_level+1),cal_max_num);
    }
    if(1)
    {
        if((y-2>=0)&&(!marks[x][y-2])) cal_max_num=cust_max(cal_pnt(x,y-2,_level+1),cal_max_num);
        if((y-1>=0)&&(!marks[x][y-1])) cal_max_num=cust_max(cal_max_num,cal_pnt(x,y-1,_level+1));
        if((y+1<m)&&(!marks[x][y+1])) cal_max_num=cust_max(cal_max_num,cal_pnt(x,y+1,_level+1));
        if((y+2<m)&&(!marks[x][y+2])) cal_max_num=cust_max(cal_pnt(x,y+2,_level+1),cal_max_num);
    }
    if(x+1<n)
    {
        if((y-2>=0)&&(!marks[x+1][y-2])) cal_max_num=cust_max(cal_pnt(x+1,y-2,_level+1),cal_max_num);
        if((y-1>=0)&&(!marks[x+1][y-1])) cal_max_num=cust_max(cal_max_num,cal_pnt(x+1,y-1,_level+1));
        if(marks[x+1][y]) cal_max_num=cust_max(cal_pnt(x+2,y,_level+1),cal_max_num);
        if((y+1<m)&&(!marks[x+1][y+1])) cal_max_num=cust_max(cal_max_num,cal_pnt(x+1,y+1,_level+1));
        if((y+2<m)&&(!marks[x+1][y+2])) cal_max_num=cust_max(cal_pnt(x+1,y+2,_level+1),cal_max_num);
    }
    if(x+2<n)
    {
        if((y-2>=0)&&(!marks[x+2][y-2])) cal_max_num=cust_max(cal_pnt(x+2,y-2,_level+1),cal_max_num);
        if((y-1>=0)&&(!marks[x-2][y-1])) cal_max_num=cust_max(cal_max_num,cal_pnt(x+2,y-1,_level+1));
        if(marks[x+2][y]) cal_max_num=cust_max(cal_pnt(x+2,y,_level+1),cal_max_num);
        if((y+1<m)&&(!marks[x+1][y+1])) cal_max_num=cust_max(cal_max_num,cal_pnt(x+2,y+1,_level+1));
        if((y+2<m)&&(!marks[x+2][y+2])) cal_max_num=cust_max(cal_pnt(x+2,y+2,_level+1),cal_max_num);
    }

    if(x-1>=0)
    {
        if(y-1>=0) marks[x-1][y-1]=(marks[x-1][y-1]==2?2:0);
        if(1) marks[x-1][y]=(marks[x-1][y]==2?2:0);
        if(y+1<m) marks[x-1][y+1]=(marks[x-1][y+1]==2?2:0);
    }
    if(1)
    {
        if(y-1>=0) marks[x][y-1]=(marks[x][y-1]==2?2:0);
        if(1) marks[x][y]=(marks[x][y]==2?2:0);
        if(y+1<m) marks[x][y+1]=(marks[x][y+1]==2?2:0);
    }
    if(x+1<n)
    {
        if(y-1>=0) marks[x+1][y-1]=(marks[x+1][y-1]==2?2:0);
        if(1) marks[x+1][y]=(marks[x+1][y]==2?2:0);
        if(y+1<m) marks[x+1][y+1]=(marks[x+1][y+1]==2?2:0);
    }
    cal_max_num+=nums[x][y];
    #ifdef DEBUG
    for(int i=0;i<_level;i++)cout<<"    ";
    cout<<"max_"<<cal_max_num<<endl;
    #endif
    if(toplevel)
    {
        _maxnum=cust_max(_maxnum,cal_max_num);
    }
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
            cal_pnt(i,j,0,1);
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
