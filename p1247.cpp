/*************************************************************************
	> File Name: p1247.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月25日 星期五 16时04分22秒
 ************************************************************************/
//在一棵完全二叉树上找LCA
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,q,a,b,ans;

int m2table[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912};
int clog2(int num)
{
        int first=0,last=28;
        while(last-first>1)
        {
                int mid=(first+last)>>1;
                if(m2table[mid]>num)
                        last=mid;
                else
                        first=mid;
        }
        return first;
}
int main()
{
        scanf("%d%d",&n,&q);
        while(q--)
        {
                scanf("%d%d",&a,&b);
                int alev=clog2(a);
                int blev=clog2(b);
                #ifdef DEBUG
                printf("LogLevel a:%d b:%d ",alev,blev);
                #endif
                if(alev>blev) {
                        a>>=(alev-blev);
                        ans=(alev-blev);
                } else {
                        b>>=(blev-alev);
                        ans=(blev-alev);
                }
                while(a!=b)//倍增找LCA
                {
                        int uplevel=0;
                        while((a>>uplevel)!=(b>>uplevel))
                                uplevel++;
                        a>>=uplevel;
                        b>>=uplevel;
                        ans+=(2*uplevel);
                }
                printf("%d\n",ans);
        }
        return 0;
}
