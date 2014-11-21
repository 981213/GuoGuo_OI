/*************************************************************************
	> File Name: p1783.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年09月26日 星期五 18时34分58秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
using namespace std;
int testednum=0;
int _length;
string _before;
string _after;
void _pair(bool _change)
{
    char a='+';//运算符
    if(testednum>0)
    {
        a=_before[testednum-1];
    }
    if(((a=='+')&&!(_change))||((a=='-')&&(_change)))
    {
        testednum++;
        for(;_before[testednum]!=')';testednum++)//  )不会被算入
        {
            if(_before[testednum]=='(')
            {
                _pair(_change);
            }
            else _after+=_before[testednum];
        }
    }
    else if(((a=='-')&&!(_change))||((a=='+')&&(_change)))
    {
        testednum++;
        for(;_before[testednum]!=')';testednum++)// 同上
        {
            if(_before[testednum]=='+')
            {
                _after+='-';
            }
            else
            if(_before[testednum]=='-')
            {
                _after+='+';
            }
            else
            if(_before[testednum]=='(')
               {
                   _pair(!_change);
               }
            else
            _after+=_before[testednum];
        }
    }
    else if(((a=='*')))
               {

               }
    else if(((a=='/')))
               {
                   
               }

}

int main()
{
    cin>>_before;
    _length=_before.length();
    for(testednum=0;testednum<_length;testednum++)
    {
        _after+=_before[testednum];
        if(_before[testednum]=='(')
           {
               _pair(0);
           }
    }
    
    return 0;
}
