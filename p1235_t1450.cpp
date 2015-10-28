/*************************************************************************
	> File Name: p1235_t1450.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月01日 星期二 18时32分55秒
 ************************************************************************/

#include<cstdio>
#include<algorithm>
using namespace std;
int stats[310];
//stats[第1个序列第i个结尾][第二个序列第j个结尾]=构成的长度 边界stats[0][0]=0
//str1[i]!=str2[j]则沿用上一次的答案stats[i-1][j]
//str1[i]==str2[j]则为max stats[i-1][k](k=1~j-1且str2[k]<str2[j]以保证严格递增)  +1
//以上为n^3算法
//考虑优化k枚举
//
int lista[310],listb[310];
int numstu;
int main()
{
        scanf("%d",&numstu);
        for(register int i=1;i<=numstu;i++)scanf("%d",lista+i);
        for(register int i=1;i<=numstu;i++)scanf("%d",listb+i);
        //DP
        for(register int i=1;i<=numstu;i++)
        {
                register int maxv=0;
                for(register int j=1;j<=numstu;j++)
                {
                        if((lista[i]>listb[j])&&(maxv<stats[j]))maxv=stats[j];
                        else if(lista[i]==listb[j])stats[j]=maxv+1;
                        //else f[i][j]=f[i-1][j]
                }

        }
        printf("%d",*max_element(stats+1,stats+numstu+1));
        return 0;
}
