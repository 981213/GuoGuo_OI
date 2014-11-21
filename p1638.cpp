/*************************************************************************
	> File Name: p1638.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年09月14日 星期日 20时03分04秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct starlist//星座
{
    char num; //星星数
    //以下为8种路径......
    char stars0[160];
    char stars90[160];
    char stars180[160];
    char stars270[160];
    char starsf0[160];
    char starsf90[160];
    char starsf180[160];
    char starsf270[160];
    //我在作死吧......
    bool ifstars0;
    bool ifstars90;
    bool ifstars180;
    bool ifstarts270;
    bool ifstarsf0;
    bool ifstarsf90;
    bool ifstarsf180;
    bool ifstartsf270;
};
struct starlist starlists[26];
char star[100][100];//星星
int x,y;
char marker='a';
bool markstar(int a,int b,bool toplevel)//x,y,是否递归
{
    if(star[a][b]=='1')
    {
        star[a][b]=marker;
        if(((a-1)>=0)&&((b-1)>=0))
            {
                if(markstar(a-1,b-1,0))
                {
                    
                }
            }
        if((a-1)>=0)
            {
                if(markstar(a-1,b,0))
                {
                }
            }
        if(((a-1)>=0)&&((b+1)<=y))
            {
                if(markstar(a-1,b+1,0))
                {
                }
            }
        if(((a)>=0)&&((b-1)>=0))
            {
                if(markstar(a,b-1,0))
                {
                }
            }
        if(((a)>=0)&&((b+1)<=y))
            {
               if(markstar(a,b+1,0))
                {
                }
            }
        if(((a+1)<=x)&&((b-1)>=0))
           {
               if(markstar(a+1,b-1,0))
                {
                }
           }
        if((a+1)<=x)
           {
               if(markstar(a+1,b,0))
                {
                }
           }
        if(((a+1)<=x)&&((b+1)<=y))
           {
               if(markstar(a+1,b+1,0))
                {
                }
           }
        if(toplevel) marker++;
        return 1;
    }
    return 0;
}
int main()
{
    cin>>x>>y;
    for(int i=0;i<x;i++)//输入星星
    {
        getchar();
        for(int j=0;j<y;j++)
        {
            star[i][j]=getchar();
        }
    }

    for(int i=0;i<x;i++)//遍历
    {
        for(int j=0;j<y;j++)
        {
            markstar(i,j,1);
        }
    }

    for(int i=0;i<x;i++)//输出星星
    {
        for(int j=0;j<y;j++)
        {
            cout<<star[i][j];
        }
        cout<<endl;
    }
    return 0;
}
