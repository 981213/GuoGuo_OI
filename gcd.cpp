/*************************************************************************
	> File Name: p1964.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月08日 星期二 17时39分05秒
 ************************************************************************/

#include<cstdio>
using namespace std;

int val1,val2;
int GCD(int a,int b){return b==0?a:GCD(b,a%b);}
int main()
{
        scanf("%d%d",&val1,&val2);
        printf("%d\n",GCD(val1,val2));
        return 0;
}
