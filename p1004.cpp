/*************************************************************************
	> File Name: p1004.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年10月10日 星期五 21时11分19秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int n;//层
long long counter=0;
void search(int a,int b)//a:科目 0=政治 1=历史 2=地理 3=综合 b:层
{
    if(b==n)
    {
        counter++;
        return;
    }
    switch(a)
    {
        case 0:
        search(1,b+1);
        break;
        case 1:
        search(0,b+1);
        search(2,b+1);
        break;
        case 2:
        search(1,b+1);
        search(3,b+1);
        break;
        case 3:
        search(2,b+1);
        break;
    }
    return;
}
int main()
{
    cin>>n;
    search(0,1);
    cout<<counter;
    return 0;
}
