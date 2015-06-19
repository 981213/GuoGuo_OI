/*************************************************************************
	> File Name: p1859.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年06月02日 星期二 10时04分30秒
 ************************************************************************/

#include<cstdio>
using namespace std;
int fa[200010];
int GetF(int Node)
{
        return fa[Node]=(Node==fa[Node]?Node:GetF(fa[Node]));
}
inline void Con(int a,int b)
{
        int FaA=GetF(a);
        int FaB=GetF(b);
        fa[FaB]=FaA;
}
inline bool Tst(int a,int b)
{
        return GetF(a)==GetF(b);
}
int main()
{
        int n,m,opt,val1,val2;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
                fa[i]=i;
        }
        while(m--)
        {
                scanf("%d%d%d",&opt,&val1,&val2);
                if(opt==1)Con(val1,val2);
                else puts(Tst(val1,val2)?"Yes":"No");
        }
        return 0;
}
