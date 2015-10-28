/*************************************************************************
	> File Name: king.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年10月20日 星期二 16时22分43秒
 ************************************************************************/

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct _P_T {
        int l,r,val;
}ps[1010];
bool cmp(struct _P_T a,struct _P_T b)
{
        return a.val<b.val;
}
int n;
long long lval;
inline int readint()
{
	register int aa; register char ch;
	while (ch = getchar(), ch < '0' || ch > '9'); 
	aa = ch - 48;
	while (ch = getchar(), ch >= '0' && ch <= '9') aa = aa * 10 + ch - 48;
	
	return aa;
}
#define LMT 100000000000000LL
struct BigNum {
        long long nums[260];
        int len;
        void Read()
        {
                len=1;
                nums[0]=readint();
        }
        void operator*=(const int val)
        {
                register long long tmpv=0;
                for(register int i=0;i<len;i++)
                {
                        nums[i]=val*nums[i]+tmpv;
                        tmpv=(nums[i]/LMT);
                        nums[i]%=LMT;
                }
                if(tmpv)
                {
                        nums[len]=tmpv;
                        len++;
                }
        }
        struct BigNum operator/(const int val) const
        {
                struct BigNum ans;
                ans.len=len;
                memset(ans.nums,0,8*len+1);
                register long long tmpleft=0,tmpval;
                for(register int i=len-1;~i;i--)
                {
                        tmpval=(nums[i]+tmpleft*LMT);
                        ans.nums[i]=tmpval/val;
                        tmpleft=tmpval%val;
                }
                while(!ans.nums[ans.len-1])ans.len--;
                return ans;
        }
        inline void Print()
        {
                printf("%lld",nums[len-1]);
                for(int i=len-2;~i;i--)printf("%014lld",nums[i]);
        }
        bool operator>(const struct BigNum b) const
        {
                if(len>b.len)return 1;
                else if(len<b.len)return 0;
                else {
                        for(register int i=len-1;~i;i--)
                        {
                                if(nums[i]>b.nums[i])return 1;
                                else if(nums[i]<b.nums[i])return 0;
                        }
                }
                return 0;
        }
        void operator= (long long val)
        {
                nums[0]=val;
                len=1;
        }
}prevans,ans;
struct BigNum cmax(struct BigNum a,struct BigNum b)
{
        return a>b?a:b;
}
int main()
{
//        scanf("%d%lld%*d",&n,&lval);
	n=readint();
	lval=readint();
	readint();
        for(register int i=0;i<n;i++)
        {
                ps[i].l=readint();
                ps[i].r=readint();
                ps[i].val=ps[i].r*ps[i].l;
        }
        sort(ps,ps+n,cmp);
        prevans=lval;
        for(register int i=0;i<n;i++)
        {
                ans=cmax(prevans/ps[i].r,ans);
                prevans*=ps[i].l;
        }
        ans.Print();
        return 0;
}
