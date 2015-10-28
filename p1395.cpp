/*************************************************************************
	> File Name: mst.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年10月23日 星期五 19时13分25秒
 ************************************************************************/

#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
struct _E_T {
        int l,r,c1,c2;
}edges[100010];
int n,l,m;
//并查集
int fa[100010];
int GetFa(int a) {return fa[a]?fa[a]=GetFa(fa[a]):a;}
inline bool CoA(int a,int b)
{
        short faa=GetFa(a),fab=GetFa(b);
        if(faa==fab)return 0;
        else{fa[faa]=fab;return 1;}
}
//二分
inline bool Check(int val)
{
        #ifdef DEBUG
        printf("Checking %d.\n",val);
        #endif
        int c1ec=0;
        memset(fa,0,sizeof(int)*(n+5));
        for(int i=0;i<m;i++)
        {
                if(edges[i].c1<=val){
                        c1ec+=CoA(edges[i].l,edges[i].r);
                        #ifdef DEBUG
                        printf("Add Edge from %d to %d.Use C1 C1 %d C2 %d\n",edges[i].l,edges[i].r,edges[i].c1,edges[i].c2);
                        #endif
                }
        }
        for(int i=0;i<m;i++)
        {
                if(edges[i].c2<=val){
                        CoA(edges[i].l,edges[i].r);
                }
        }
        int fav=GetFa(1);
        for(int i=2;i<=n;i++)if(GetFa(i)!=fav)return 0;
        #ifdef DEBUG
        printf("Use C1 %d Result %d.\n",c1ec,int(c1ec>=l));
        #endif
        return c1ec>=l;
}

int main()
{
        scanf("%d%d%d",&n,&l,&m);
        for(int i=0;i<m;i++)scanf("%d%d%d%d",&edges[i].l,&edges[i].r,&edges[i].c1,&edges[i].c2);
        register int ansl=0,ansr=30000;
        register int mid;
        while(ansr-ansl>1)
        {
                mid=(ansl+ansr)>>1;
                if(Check(mid))ansr=mid;
                else ansl=mid;
        }
        printf("%d",ansr);
        return 0;
}
