/*************************************************************************
	> File Name: p1203.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年10月27日 星期一 20时37分16秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
bool a[10][10];
int counter=0;
void find(int x,int y,bool iftop)
{
    if (!a[x][y]) return;
    if (iftop) counter++;
    a[x][y]=0;
    if(x-1>=0)find(x-1,y,0);
    if(x+1<10)find(x+1,y,0);
    if(y-1>=0)find(x,y-1,0);
    if(y+1<10)find(x,y+1,0);
}
int main()
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            char temp=getchar();
            if(temp=='1') a[i][j]=1;
            else a[i][j]=0;
        }
        getchar();
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            find(i,j,1);
        }
    }
    cout<<counter;
    return 0;
}
