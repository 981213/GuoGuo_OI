/*************************************************************************
	> File Name: classroom.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年11月04日 星期二 18时09分07秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int avail_class[1000000010];
int main()
{
    #ifndef DEBUG
    freopen("classroom.in","r",stdin);
    freopen("classroom.out","w",stdout);
    #endif
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&avail_class[i]);
    }
    bool mark=0;
    for(int i=1;i<=m;i++)
    {
        int dj,sj,tj;
        scanf("%d%d%d",&dj,&sj,&tj);
        if(*min_element(avail_class+sj,avail_class+dj+1)>=dj)
        {
            for(int i=sj;i<=tj;i++)
            {
                avail_class[i]-=dj;
            }
        }
        else
        {
            cout<<"-1"<<endl<<i;
            mark=1;
            break;
        }
    }
    if(!mark)cout<<"0";
    #ifndef DEBUG
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}
