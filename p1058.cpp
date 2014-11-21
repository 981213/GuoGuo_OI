/*************************************************************************
	> File Name: p1058.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年10月26日 星期日 20时38分54秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int counter=0;
    while(n!=0)
    {
        int l=int(sqrt(float(n)));
        n=n-l*l;
        counter++;
    }
    cout<<counter;
    return 0;
}
