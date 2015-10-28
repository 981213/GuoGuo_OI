/*************************************************************************
	> File Name: p1962.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月15日 星期二 16时12分02秒
 ************************************************************************/

#include<cstdio>
#include<cstring>
#include<cassert>
using namespace std;
char tmpstr[120];
#define ObjCnt 10000
struct BigNum {
        int nums[ObjCnt];
        int cnt;
        inline void read()
        {
                register char tmpchr;
                int strcnt=0;
                cnt=0;
                while(((tmpstr[strcnt]=getchar())>='0')&&(tmpstr[strcnt]<='9'))strcnt++;
                while(strcnt--)
                {
                        nums[cnt++]=tmpstr[strcnt]-'0';
                }
        }
        inline void write()
        {
                int numcnt=cnt;
                while(numcnt--)printf("%d",nums[numcnt]);
        }
        inline void operator/=(const int optval)
        {
                int numcnt=cnt;
                while(--numcnt)
                {
                        nums[numcnt-1]+=(nums[numcnt]%optval)*10;
                        nums[numcnt]/=optval;
                }
                nums[numcnt]/=optval;
                while(nums[cnt-1]==0)cnt--;
        }
        struct BigNum operator*(const struct BigNum b) const
        {
                static struct BigNum retval;
                register int tmpval,nextadd=0;
                memset(retval.nums,0,sizeof(retval.nums));
                for(int i=0;i<cnt;i++)
                {
                        for(int j=0;j<b.cnt;j++)
                        {
                                tmpval=nums[i]*b.nums[j]+retval.nums[i+j];
                                retval.nums[i+j]=tmpval%10;
                                retval.nums[i+j+1]+=tmpval/10;
                        }
                }
                retval.cnt=cnt*b.cnt+2;
                assert(retval.cnt<ObjCnt);
                while(retval.nums[retval.cnt-1]==0)retval.cnt--;
                return retval;
        }
}test1,test2;
int main()
{
        test1.read();
        int ifadd=test1.nums[0]%2;
        test1/=2;
        test2=test1;
        test2.nums[0]+=ifadd;
        (test1*test2).write();
        return 0;
}
