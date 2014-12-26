/*************************************************************************
	> File Name: p1762.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年12月21日 星期日 18时59分55秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define YEAR 31104000
#define MONTH 2592000
#define DAY 86400
using namespace std;

int main()
{
    int temp;
    scanf("%d",&temp);
    printf("%d ",1980+(temp/YEAR));
    temp%=YEAR;
    printf("%d ",1+(temp/MONTH)); 
    temp%=MONTH;
    printf("%d",1+(temp/DAY));
    return 0;
}
