/*************************************************************************
	> File Name: p1020.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年09月16日 星期二 19时01分19秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
char _map[1000][1000];
int n,m;
int marker=0;
short testx[13]={-2,-1,-1,-1, 0, 0,0,0, 1,1,1,2};
short testy[13]={ 0,-1, 0, 1,-2,-1,1,2,-1,0,1,0};
bool mark_map(int a,int b,bool toplevel)//x,y,是否递归
{
    if(_map[a][b]=='#')
    {
        _map[a][b]='M';
        for(int k=0;k<13;k++)
        {
            if((a+testx[k]>=0)&&(a+testx[k]<m)&&(b+testy[k]>=0)&&(b+testy[k]<n))
                mark_map(a+testx[k],b+testy[k],0);
        }
        if(toplevel) marker++;
        return 1;
    }
    return 0;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        getchar();
        for(int j=0;j<n;j++)
        {
            _map[i][j]=getchar();
        }
    }
     for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            mark_map(i,j,1);
        }
    }

/*    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<_map[i][j];
        }
        cout<<endl;
    }*/
    cout<<int(marker);
    return 0;

}
