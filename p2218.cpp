/*************************************************************************
	> File Name: p2218.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年10月16日 星期五 17时16分46秒
 ************************************************************************/

#include<cstdio>
#include<algorithm>
using namespace std;
int e[3];
int main()
{
        scanf("%d%d%d",e,e+1,e+2);
        sort(e,e+3);
        if(e[0]+e[1]<=e[2])puts("not a triangle");
        else if(e[0]*e[0]+e[1]*e[1]==e[2]*e[2])puts("yes");
        else puts("no");
        return 0;
}
