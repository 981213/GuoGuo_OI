/*************************************************************************
	> File Name: p1764.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年07月07日 星期二 20时16分25秒
 ************************************************************************/

#include<cstdio>
using namespace std;
int a,b,c;
#define Jud(num) ((num%3==a)&&(num%5==b)&&(num%7==c))
int main()
{
        scanf("%d%d%d",&a,&b,&c);
        for (register int i=0;i<101;i++)
        {
                if(Jud(i))
                {
                        printf("%d",i);
                        return 0;
                }
        }
        puts("no answer");
        return 0;
}
