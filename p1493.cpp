/*************************************************************************
	> File Name: p1493.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年09月16日 星期二 14时15分11秒
 ************************************************************************/

#include<iostream>
using namespace std;
int a,b,c,resultcount=0;
int result[100];
int main()
{
    cin>>a>>b>>c;
    if ((c<a)&&(c<b))
    {
        cout<<0<<" "<<c;
    }
    else if(b<c)
    {
        cout<<c-b<<" "<<c;
    }
    else if((a<c)&&(c<b))
    {
        while(1)
        {
            
        }
    }
    return 0;
}
