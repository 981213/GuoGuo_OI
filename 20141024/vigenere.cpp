/*************************************************************************
	> File Name: vigenere.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年10月24日 星期五 13时04分17秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
string s1;//明文
string s2;//密码
char decrypt(char k,char c)//密码,密文
{
    bool mark=0;
    if(c>='a')
    {
        mark=1;
        c=c-('a'-'A');
    }
    if(k>='a')
    {
        k=k-('a'-'A');
    }
    c-='A';
    k-='A';
    char a;
    if(c-k<0) a=c-k+26;
    else a=c-k;
    a+='A';
    if(mark)
    {
        a=a+('a'-'A');
    }
    return a;
}
int main()
{
#ifndef DEBUG
    freopen("vigenere.in","r",stdin);
    freopen("vigenere.out","w",stdout);
#endif
    cin>>s2;
    cin>>s1;
    int s2point=0;
    for(int i=0;i<s1.length();i++)
    {
        if (s2point==s2.length()) s2point=0;
        cout<<decrypt(s2[s2point],s1[i]);
        s2point++;
    }
#ifndef DEBUG
    fclose(stdin);
    fclose(stdout);
#endif
/*加密演示部分如下:
    char a,b;
    while(1)
    {
        cin>>a>>b;
        bool mark=0;
        if(a>='a')
        {
            mark=1;
            a=a-('a'-'A');
        }
        if(b>='a')
        {
            b=b-('a'-'A');
        }
        char c=char((a-'A'+b-'A')%26+'A');
        if(mark)
        {
            c=c+('a'-'A');
        }
        cout<<c<<endl;
    }
*/
    return 0;
}
