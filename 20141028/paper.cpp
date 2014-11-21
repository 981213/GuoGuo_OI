/*************************************************************************
	> File Name: paper.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年10月28日 星期二 16时09分26秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
string inputstring;
map<char,vector<int> > characterlist;
map<char,bool> ifcharacter;
vector<char> charappear;//for func_test
bool func_char_test(char _char,int leng)
{
    //characterlist[_char];
    //if(characterlist[_char].size()==1) return
    bool mark=1;
    for(int i=0;i<characterlist[_char].size()-1;i++)
    {
        bool mark2=1;
        string compare1=inputstring.substr(characterlist[_char][i],leng);
        for(int j=i+1;j<characterlist[_char].size();j++)
        {
            string compare2=inputstring.substr(characterlist[_char][j],leng);
            if(!compare1.compare(compare2))
            {
                mark2=0;
                break;
            }
        }
        if(!mark2)
        {
            mark=0;
            break;
        }
    }
    return mark;
}
bool func_test(int leng)
{
    bool mark=1;
    for(int i=0;i<charappear.size();i++)
    {
        mark=func_char_test(charappear[i],leng);
        if(!mark) break;
    }
    return mark;
}
int main()
{
#ifndef DEBUG
    freopen("paper.in","r",stdin);
    freopen("paper.out","w",stdout);
#endif
    cin>>inputstring;
    for(int i=0;i<inputstring.length();i++)
    {
        characterlist[inputstring[i]].push_back(i);
        if(!ifcharacter[inputstring[i]])
        {
            ifcharacter[inputstring[i]]=1;
            charappear.push_back(inputstring[i]);
        }
    }
    for(int i=1;i<=inputstring.length();i++)
    {
        if(func_test(i))
        {
            cout<<i-1;
            break;
        }
    }
#ifndef DEBUG
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
