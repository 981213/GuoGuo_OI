/*************************************************************************
	> File Name: p2251.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月11日 星期五 16时14分57秒
 ************************************************************************/

#include<cstdio>
#include<cstring>
using namespace std;
char str1[200010];
char str2[200010];
int T;
bool CheckAns(char* str1,char* str2,int len)
{
        if(len==1) {
                return (*str1)==(*str2);
        } else {
                #define str1l str1
                #define str1r str1+mid
                #define str2l str2
                #define str2r str2+mid
                int mid=(len>>1);
                return ((CheckAns(str1l,str2l,mid)&&CheckAns(str1r,str2r,mid)) || (CheckAns(str1l,str2r,mid)&&(CheckAns(str2l,str1r,mid))));
        }
}
int main()
{
        scanf("%d",&T);
        while(T--)
        {
                register int len1=0,len2=0;
                scanf("%s",str1);
                scanf("%s",str2);
                len1=strlen(str1);
                len2=strlen(str2);
                if((len1!=len2)||(len1%2)||(len2%2))
                {
                        puts("NO");
                        continue;
                }
                puts(CheckAns(str1,str2,len1)?"YES":"NO");
        }
        return 0;
}
