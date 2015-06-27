/*************************************************************************
	> File Name: p1114.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年02月13日 星期五 14时15分28秒
 ************************************************************************/

#include<cstdio>
#include<cmath>
using namespace std;
char CharList[110];
int ChCnt=0;
inline int GetR(int & a)
{
    int MaxNum=sqrt(a);
    while(a%MaxNum)--MaxNum;
    return MaxNum;
}
int main()
{
    while((CharList[ChCnt]=getchar())!='\n')++ChCnt;
    int Roll=GetR(ChCnt);
    int Col=ChCnt/Roll;
    for(int i=0;i<Roll;i++)
    {
        for(int j=0;j<Col;j++)
        {
            putchar(CharList[i+j*Roll]);
        }
    }
    return 0;
}

