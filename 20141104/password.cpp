/*************************************************************************
	> File Name: password.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年11月04日 星期二 16时00分29秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cmath>
#include<vector>
using namespace std;
char solve_key[10];
vector<char> pwdres;
int main()
{
    #ifndef DEBUG
    freopen("password.in","r",stdin);
    freopen("password.out","w",stdout);
    #endif
    int x;
    cin>>x;
    getchar();
    for(int i=0;i<7;i++)
    {
        solve_key[i]=getchar();
        getchar();
    }
    int m;
    cin>>m;
    solve_key[7]='+';
    solve_key[8]='-';
    solve_key[9]='*';
    long long num=0;
    int powhead=0;
    long long maxuse=pow(10,m);
    while(x!=0)
    {
        int numbit=(x&1);
        x>>=1;
        num+=numbit*pow(7,powhead);
        num%=maxuse;
        powhead++;
        #ifdef DEBUG
        printf("%d ",numbit);
        #endif
    }
    #ifdef DEBUG
    printf("converted num: %lld",num);
    cout<<pow(7,27);
    #endif
    while(num>0)
    {
        int pwdtemp=num%10;
        num/=10;
        pwdres.push_back(solve_key[pwdtemp]);
        if (pwdres.size()==m)break;
    }
    for(int i=0;i<m-pwdres.size();i++) putchar(solve_key[0]);
    for(int i=pwdres.size()-1;i>=0;i--)putchar(pwdres[i]);
    #ifndef DEBUG
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}
