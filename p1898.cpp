/*************************************************************************
	> File Name: p1898.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月22日 星期二 16时05分13秒
 ************************************************************************/

#include<cstdio>
using namespace std;
char ChrMap1[28];
char ChrMap2[28];
#define MAP1(a) ChrMap1[a-'A']
#define MAP2(a) ChrMap2[a-'A']
char StrHash[110];
char StrOrig[110];
char StrCarck[110];
int main()
{
        gets(StrHash);
        gets(StrOrig);
        register int i=0;
        while(StrHash[i])
        {
                if((MAP1(StrHash[i]))&&(MAP1(StrHash[i])!=StrOrig[i]))
                {
                        puts("Failed");
                        return 0;
                }
                MAP1(StrHash[i])=StrOrig[i];
                if((MAP2(StrOrig[i]))&&(MAP2(StrOrig[i])!=StrHash[i]))
                {
                        puts("Failed");
                        return 0;
                }
                MAP2(StrOrig[i])=StrHash[i];
                i++;
        }
        for(i='A';i<='Z';i++)
        {
                if(!MAP1(i))
                {
                        puts("Failed");
                        return 0;
                }
        }
        gets(StrCarck);
        i=0;
        while(StrCarck[i])
        {
                putchar(MAP1(StrCarck[i]));
                i++;
        }
        return 0;
}
