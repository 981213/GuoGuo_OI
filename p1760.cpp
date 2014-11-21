/*************************************************************************
	> File Name: p1760.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年10月27日 星期一 13时22分58秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<((b+a-1)*(c+a-1)-a*(a-1));
    return 0;
}
