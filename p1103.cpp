/*************************************************************************
	> File Name: p1103.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年12月28日 星期日 18时48分05秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;

int TotMoney,MoneyPerMonth,TotPayMonth;

inline bool CheckAns(float & PaTest)
{
    float LeftMoney=TotMoney;
    for(int i=0;i<TotPayMonth;i++)
    {
        LeftMoney=LeftMoney*(PaTest+1.0)-MoneyPerMonth;
    }
    return LeftMoney>0?0:1;
}

int main()
{
    scanf("%d%d%d",&TotMoney,&MoneyPerMonth,&TotPayMonth);
    float TestF=0.0,TestT=1.0;
    float TestMid;
    while(TestT-TestF>0.0009)
    {
        TestMid=(TestF+TestT)/2;
        if(CheckAns(TestMid))
        {
            TestF=TestMid;
        }
        else
        {
            TestT=TestMid;
        }
    }
    printf("%.1f",TestF*100);
    return 0;
}
