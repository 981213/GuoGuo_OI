/*************************************************************************
	> File Name: p1188.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年06月02日 星期二 19时29分49秒
 ************************************************************************/

#include<cstdio>
using namespace std;
int num[1010],res[1010];
char opt;
int tot;
int num2;
int main()
{
        scanf("%c %d\n",&opt,&tot);
        for(int i=tot-1;~i;i--)
        {
                num[i]=getchar()-'0';
        }
        getchar();
        num2=getchar()-'0';
        if(opt=='M')
        {
                for(int i=0;i<tot;i++)
                {
                        res[i]+=num[i]*num2;
                        res[i+1]+=res[i]/10;
                        res[i]%=10;
                }
                if(res[tot]!=0)putchar(res[tot]+'0');
                for(int i=tot-1;~i;i--)putchar(res[i]+'0');
                
        } else {
                for(int i=tot-1;i>0;i--)
                {
                        res[i]=num[i]/num2;
                        num[i-1]+=(num[i]%num2)*10;
                }
                res[0]=num[0]/num2;
                if(res[tot-1]!=0)putchar(res[tot-1]+'0');
                for(int i=tot-2;~i;i--)putchar(res[i]+'0');
        }
        return 0;
}
