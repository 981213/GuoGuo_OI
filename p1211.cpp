/*************************************************************************
	> File Name: p1211.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年09月16日 星期二 19时42分30秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
 char _map[1000][1000];
 char originmap[1000][1000];
 short testx1[4]={-1, 0, 0,1};
 short testy1[4]={ 0,-1, 0,0};
 short testx2[4]={-1,-1, 1,1};
 short testy2[4]={-1, 1,-1,1};
 int x,y;
 void restoremap()
 {
     for(int i=0;i<x;i++)
     {
         for(int j=0;j<y;j++)
         {
             _map[i][j]=originmap[i][j];
         }
     }
 }
 int countdist(int a,int b,bool toplevel)
 {
     if(_map[a][b]=='1') return 0;
     for(int k=0;k<4;k++)
     {
        if((a+testx1[k]>=0)&&(a+testx1[k]<x)&&(b+testy1[k]>=0)&&(b+testy1[k]<y)&&(_map[a][b]!='M'))
            {
                _map[a][b]='M';
               int temp=(countdist(a+testx1[k],b+testy1[k],0)+1);
                if (temp==-1) return -1; else return temp;
            }
     }
     for(int k=0;k<4;k++)
     {
        if((a+testx2[k]>=0)&&(a+testx2[k]<x)&&(b+testy2[k]>=0)&&(b+testy2[k]<y)&&(_map[a][b]!='M'))
         {
            _map[a][b]='M'; 
            int temp2=(countdist(a+testx2[k],b+testy2[k],0)+2);
             if (temp2==-1) return -1;else return temp2;

        }
     }
     if(toplevel) restoremap();
     return -1;
}
 int main()
 {
     cin>>x>>y;
     for(int i=0;i<x;i++)//输入
    {
        getchar();
        for(int j=0;j<y;j++)
        {
            _map[i][j]=getchar();
            originmap[i][j]=_map[i][j];
        }
    }
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            cout<<countdist(i,j,1)<<" ";
        }
        cout<<endl<<endl;
    }


     return 0;
 }
