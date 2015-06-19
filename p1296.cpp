/*************************************************************************
	> File Name: p1296.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年06月19日 星期五 18时44分05秒
 ************************************************************************/

#include<cstdio>
using namespace std;
//递归处理
//k=n/2
//q<=k时将会出现在右半段第k-q+1个
//否则在左半段第n-q+1个
int func(int n,int q)//询问phi(n,q)的答案
{
        if(n==1)return 1;
        int k=n/2;
        if(q>k)
                return func(n-k,n-q+1);
        else
                return n-k+func(k,k-q+1);//n-k为左段长度
}
int main()
{
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d",func(a,b));
        return 0;
}
