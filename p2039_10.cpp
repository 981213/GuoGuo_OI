/*************************************************************************
	> File Name: p2039_10.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月25日 星期五 18时42分23秒
 ************************************************************************/
//10分，链
#include<cstdio>
using namespace std;
int main()
{
        int m,ans,tmp;
        scanf("%d%d",&ans,&m);
        for(int i=0;i<m;i++)
        {
                scanf("%*d%*d%d",&tmp);
                ans+=tmp;
        }
        printf("%d",ans);
        return 0;
}
