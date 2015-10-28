/*************************************************************************
	> File Name: p1989.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月19日 星期六 18时08分14秒
 ************************************************************************/

#include<cstdio>
using namespace std;
int n,a[10010],b[10010],t;
inline bool ChkAval(int & val)
{
        int poola=0;
        int poolb=0;
        int aval=0;
        for(int i=0;i<n;i++)
        {
                poola+=a[i];
                poolb+=b[i];
                if(poola>val)
                {
                        aval-=(poola-val);
                        poola=val;
                }
                if(poolb>val)
                {
                        aval-=(poolb-val);
                        poolb=val;
                }
                if(aval<0)return 0;
                if((poola)&&(poolb))aval++;
                else if(poola)poola--;
                else if(poolb)poolb--;
        }
        return 1;
}

int main()
{
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d",&n);
                for(int i=0;i<n;i++)
                        scanf("%d%d",a+i,b+i);
                int left=1;
                int right=200001;
                while(right-left>1)
                {
                        int mid=(left+right)>>1;
                        if(ChkAval(mid))
                                right=mid;
                        else
                                left=mid;
                }
                printf("%d\n",left);
        }
        return 0;
}
