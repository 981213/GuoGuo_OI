/*************************************************************************
	> File Name: p1202.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年10月28日 星期二 12时28分39秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<queue>
using namespace std;
bitset<1002> ifsearched[1002];
bitset<1002> ifisAns;
queue<int> BFSQue;
int q,p,n;
int TotN;
int NowP,NowQ,NowN;
inline void Search()
{
    BFSQue.push(q*10000+p);
    while(!BFSQue.empty())
    {
        NowQ=BFSQue.front()/10000;
        NowP=BFSQue.front()%10000;
        BFSQue.pop();
        if(ifsearched[NowQ][NowP])
        {
            continue;
        }
        else
        {
            ifsearched[NowQ][NowP]=1;
            NowN=n-NowP-NowQ;

        }
    }
}
int main()
{
    scanf("%d%d%d",&q,&p,&n);
    TotN=n;

    return 0;
}
