/*************************************************************************
	> File Name: punct.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年10月24日 星期五 14时05分44秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
vector<string> dictionary;
string langtoseparate;
int counter=0;//计数
string convertcharacter(string inputstring)
{
    for(int i=0;i<inputstring.length();i++)
    {
        if(inputstring[i]<'a') inputstring[i]+=('a'-'A');
    }
    return inputstring;
}
void sepstring(int start,int count)
{
    if (start==langtoseparate.length())
    {
        if(count!=0)
        if (langtoseparate.length()%count==0) counter++;
    }
    else
    for(int i=0;i<dictionary.size();i++)
    {
        if((langtoseparate.length()-start-dictionary[i].length())<0) continue;
        bool mark=1;
        for(int j=0;j<dictionary[i].length();j++)
        {
            if(dictionary[i][j]!=langtoseparate[j+start])
            {
                mark=0;
                break;
            }
        }
        if(mark)
        {
            sepstring(start+dictionary[i].length(),count+1);
        }
    }
}
int main()
{
#ifndef DEBUG
    freopen("punct.in","r",stdin);
    freopen("punct.out","w",stdout);
#endif
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        dictionary.push_back(convertcharacter(temp));
    }
    cin>>langtoseparate;
    langtoseparate=convertcharacter(langtoseparate);
    sepstring(0,0);
    cout<<counter;
//    sort(dictionary.begin(),dictionary.end());
#ifndef DEBUG
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
