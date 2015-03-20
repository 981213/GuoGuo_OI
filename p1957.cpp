/*************************************************************************
	> File Name: p1957.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年01月05日 星期一 18时58分21秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
short chs[4][4];
int TotNum,i,j,testnum;
int main()
{
    scanf("%d",&TotNum);
    while(TotNum)
    {
        for(i=0;i<4;i++)
        {
            getchar();
            for(j=0;j<4;j++)
            {
                chs[i][j]=getchar()=='#'?1:0;
            }
        }
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(chs[i][j]+
                  chs[i][j+1]+
                  chs[i+1][j]+
                  chs[i+1][j+1]!=2)
                {
                    testnum=1;
                    goto PrintAns;
                }
            }
        }
        testnum=0;
        PrintAns:
        puts(testnum?"Yes":"No");
        --TotNum;
    }
    return 0;
}
