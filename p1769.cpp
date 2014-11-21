/*************************************************************************
	> File Name: p1769.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年10月27日 星期一 13时38分29秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int counter=0;
    while(n!=1)
    {
        if(n%2==1)
        {
            n=3*n+1;
        }
        else
        {
            n=n/2;
        }
        counter++;
    }
    cout<<counter;
    return 0;
}
