/*************************************************************************
	> File Name: p2096.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年03月01日 星期日 21时02分10秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
char stra[510],strb[510];
char strc[510];
int counta=0,countb=0,countc=0;
int main()
{
    while((stra[counta++]=getchar()-'0')>=0);
    counta-=2;
    if((strb[countb]=getchar()-'0')>=0)countb++;//Workaroud for input3.txt
    while((strb[countb++]=getchar()-'0')>=0);
    countb-=2;
    while(counta>=0||countb>=0)
    {
        strc[countc]+=(
        (counta>=0?stra[counta]:0)+
        (countb>=0?strb[countb]:0));
        strc[countc+1]=strc[countc]/10;
        strc[countc]%=10;
        counta--;countb--;
        countc++;
    }
    if(strc[countc]!=0)putchar(strc[countc]+'0');
    countc--;
    while(countc>=0)
    {
        putchar(strc[countc--]+'0');
    }
    return 0;
}
