/*************************************************************************
	> File Name: p1249.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年12月09日 星期二 12时17分57秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int fruitfather[200000];
bool Query(int mark1,int mark2);
int GetFather(int num);
inline void Connect(int mark1,int mark2)
{
    if(Query(mark1,mark2))return;
    fruitfather[GetFather(mark2)]=GetFather(mark1);
}
int GetFather(int num)
{
    if(fruitfather[num])
    {
        return fruitfather[num]=GetFather(fruitfather[num]);
    }
    else
    {
        return num;
    }
}
inline bool Query(int mark1,int mark2)
{
    return GetFather(mark1)==GetFather(mark2);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int _operate,_num1,_num2;
        scanf("%d%d%d",&_operate,&_num1,&_num2);
        switch(_operate)
        {
            case 1:
            {
                Connect(_num1,_num2);
                break;
            }
            case 2:
            {
                if(Query(_num1,_num2))
                {
                    puts("same");
                }
                else
                {
                    puts("diff");
                }
                break;
            }
        }

    }
    return 0;
}
