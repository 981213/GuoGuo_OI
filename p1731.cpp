/*************************************************************************
	> File Name: p1731.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月08日 星期二 17时55分07秒
 ************************************************************************/

#include<cstdio>
#include<algorithm>
using namespace std;
struct _PNT_T {
        int dist;
        int val;
        int prev;
        bool operator<(const struct _PNT_T another) const
        {
                return dist<another.dist;
        }
}points[200010];
int n;
//LIS DP 最长下降子序列 f[i]表示长度为i的LIS的结尾最大值
struct _DP_OBJ_T{
        int val;
        int pnt;
        bool operator<(const struct _DP_OBJ_T another) const
        {
                return val<another.val;
        }
        bool operator<(const int anval)const
        {
                return val<anval;
        }
} f[200010];
int fstart=1;
inline void callis()
{
        f[fstart].val=points[1].val;
        f[fstart++].pnt=1;
        for(int i=2;i<n;i++)
        {
                if(points[i].val<f[fstart-1].val) {
                        points[i].prev=f[fstart-1].pnt;
                        f[fstart].val=points[i].val;
                        f[fstart++].pnt=i;
                } else if(points[i].val>f[1].val) {
                        f[1].val=points[i].val;
                        f[1].pnt=i;
                }
                else {
                        register struct _DP_OBJ_T *calobj=lower_bound(f+1,f+n+1,points[i].val);
                        calobj->pnt=i;
                        calobj->val=points[i].val;
                        points[i].prev=(calobj-1)->pnt;
                }
        }
}
inline long long calans()
{
        long long ans=0;
        register int pnt=f[fstart-1].pnt;
        register int prevdist;
        
        /*while(~pnt)
        {
                printf("Dist=%d,Val=%d-->\n",points[pnt].dist,points[pnt].val);
                pnt=points[pnt].prev;
        }*/
        while(~pnt)
        {
                prevdist=points[pnt].dist;
                pnt=points[pnt].prev;
                ans+=points[pnt].val*(prevdist-points[pnt].dist);
        }
        return ans;
}
int main()
{
        scanf("%d",&n);
        for(register int i=0;i<n;i++)
                scanf("%d%d",&points[i].dist,&points[i].val);
        sort(points,points+n);
        points[0].prev=-1;
        callis();
        printf("%lld",calans());
        return 0;
}
