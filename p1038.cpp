/*************************************************************************
	> File Name: p1038.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年10月23日 星期五 13时21分21秒
 ************************************************************************/

#include<cstdio>
#include<cstdlib>
using namespace std;
//并查集
short fa[101010];
short GetFa(short a) {return fa[a]?fa[a]=GetFa(fa[a]):a;}
inline bool CoA(short a,short b)
{
        short faa=GetFa(a),fab=GetFa(b);
        if(faa==fab)return 0;
        else{fa[faa]=fab;return 1;}
}
//鬼畜的输入优化
char tmpstr[6];
#define Read(a) { scanf("%s",tmpstr);a=atoi(tmpstr); }
//主程序
int main()
{
        register short k,m,t1,t2;
        register short ans=0;
        scanf("%*s");
        Read(k);
        Read(m);
        while(k--)
        {
                Read(t1);
                Read(t2);
                CoA(t1,t2);
        }
        while(m--)
        {
                Read(t1);
                Read(t2);
                ans+=CoA(t1,t2);
        }
        printf("%hd",ans);
        return 0;
}
