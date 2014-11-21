/*************************************************************************
	> File Name: rank.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年10月28日 星期二 18时23分27秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
vector<string> codelist;
int main()
{
#ifndef DEBUG
    freopen("rank.in","r",stdin);
    freopen("rank.out","w",stdout);
#endif
    int n;
    cin>>n;
    int minleng=1000000;
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        if(temp.length()<minleng)
        {
            codelist.clear();
            minleng=temp.length();
        }
        if(temp.length()==minleng) codelist.push_back(temp);
    }
    //处理!?!?!?!?!?!?
    //
    //
    //
    //
    //
    cout<<codelist.size()<<endl;
    for(int i=0;i<codelist.size();i++)
    {
        cout<<codelist[i]<<endl;
    }
#ifndef DEBUG
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}

