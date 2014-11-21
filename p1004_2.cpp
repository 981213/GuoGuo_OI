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
unsigned long long countera=1,counterb=1;
int main()
{
    cin>>n;
    for(int i=2;i<n;i++)
    {
        long long temp=countera;
        countera=counterb;
        counterb=(countera+temp)%7654321;
    }
    if(n==0) cout<<0;
    else cout<<counterb;
    return 0;
}
