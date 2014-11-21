/*************************************************************************
	> File Name: p1240.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年10月19日 星期日 20时46分02秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int x,y;
int numlist[101][101];
int result=-2147483648;

int main()
{
    scanf("%d%d", &x, &y);
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=y;j++)
        {
            int temp;
            scanf("%d",&temp);
            numlist[i][j]=numlist[i][j-1]+numlist[i-1][j]+temp-numlist[i-1][j-1];
        }
    }
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=y;j++)
        {
            for(int k=0;k+i<=x;k++)
            {
                for(int l=0;l+j<=y;l++)
                {
                    int tempa=numlist[k+i][l+j]-numlist[k+i][j-1]-numlist[i-1][l+j]+numlist[i-1][j-1];
                    if(tempa>result) result=tempa;
                }
            }
        }
    }
    cout<<result;
    return 0;
}
