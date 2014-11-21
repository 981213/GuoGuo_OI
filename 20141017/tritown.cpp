/*************************************************************************
	> File Name: tritown.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年10月17日 星期五 18时48分24秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
//骗分版
int p,q,n;
vector<int> tritownlist;//0~9
int main()
{
#ifndef DEBUG
    freopen("tritown.in","r",stdin);
    freopen("tritown.out","w",stdout);
#endif
    cin>>p>>q;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        tritownlist.push_back(a);
    }
#ifndef DEBUG
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
