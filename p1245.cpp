/*************************************************************************
	> File Name: p1245.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年10月27日 星期一 13时26分06秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
map<string,bool> ifstu;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string temp;
        cin>>temp;
        if(ifstu[temp])
        {
            cout<<i<<endl;
        }
        else
        {
            ifstu[temp]=1;
        }
    }
    return 0;
}
