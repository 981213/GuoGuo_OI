#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
//#define FAIL_RUN
using namespace std;
stack<int> rightlist;
struct charnode
{
       char originvalue;
       char value;
       int prev;
       int next;
} charlist[100010];
void resetchain(int l,int r)
{
        charlist[l-1].prev=0;
        charlist[l-1].next=0;
    charlist[r+1].prev=0;
    charlist[r+1].next=0;
    for(int i=l;i<=r;i++)
    {
        charlist[i].value=charlist[i].originvalue;
        charlist[i].prev=i-1;
        charlist[i].next=i+1;
    }
}
void node_delete(int nodenum)
{
    charlist[charlist[nodenum].prev].next=charlist[nodenum].next;
    charlist[charlist[nodenum].next].prev=charlist[nodenum].prev;
}
void node_connect(int a,int b)
{
    if(a<b)
    {
        charlist[a].next=b;
        charlist[b].prev=a;
    }
    else if(a>b)
    {
        charlist[b].next=a;
        charlist[a].prev=b;
    }
}
void solve(int l,int r)
{
    rightlist.empty();
    bool way_dist=1;//1:right 0:left
    int point=l;
    int numcounter[10]={0,0,0,0,0,0,0,0,0,0};
    while((point>=l)&&(point<=r))
    {
        #ifdef FAIL_RUN
        //预先处理><之间的内容
        /*
         * ERROR:
*** Error in `./turing': free(): invalid pointer: 0x0000000000d12271 ***
======= Backtrace: =========
/lib64/libc.so.6[0x34bc275a4f]
/lib64/libc.so.6[0x34bc27cd78]
./turing[0x4025d8]
./turing[0x401f9c]
./turing[0x4019c2]
./turing[0x401843]
./turing[0x4017c2]
./turing[0x40156e]
./turing[0x401709]
/lib64/libc.so.6(__libc_start_main+0xf5)[0x34bc221d65]
./turing[0x400a59]
======= Memory map: ========
00400000-00405000 r-xp 00000000 fd:02 2359481                            /home/user/src/noip/win/20141031/turing
00604000-00605000 r--p 00004000 fd:02 2359481                            /home/user/src/noip/win/20141031/turing
00605000-00606000 rw-p 00005000 fd:02 2359481                            /home/user/src/noip/win/20141031/turing
00606000-0072b000 rw-p 00000000 00:00 0 
00d12000-00d33000 rw-p 00000000 00:00 0                                  [heap]
34bbe00000-34bbe20000 r-xp 00000000 fd:00 2229219                        /usr/lib64/ld-2.18.so
34bc01f000-34bc020000 r--p 0001f000 fd:00 2229219                        /usr/lib64/ld-2.18.so
34bc020000-34bc021000 rw-p 00020000 fd:00 2229219                        /usr/lib64/ld-2.18.so
34bc021000-34bc022000 rw-p 00000000 00:00 0 
34bc200000-34bc3b4000 r-xp 00000000 fd:00 2229221                        /usr/lib64/libc-2.18.so
34bc3b4000-34bc5b3000 ---p 001b4000 fd:00 2229221                        /usr/lib64/libc-2.18.so
34bc5b3000-34bc5b7000 r--p 001b3000 fd:00 2229221                        /usr/lib64/libc-2.18.so
34bc5b7000-34bc5b9000 rw-p 001b7000 fd:00 2229221                        /usr/lib64/libc-2.18.so
34bc5b9000-34bc5be000 rw-p 00000000 00:00 0 
34bce00000-34bcf05000 r-xp 00000000 fd:00 2231950                        /usr/lib64/libm-2.18.so
34bcf05000-34bd105000 ---p 00105000 fd:00 2231950                        /usr/lib64/libm-2.18.so
34bd105000-34bd106000 r--p 00105000 fd:00 2231950                        /usr/lib64/libm-2.18.so
34bd106000-34bd107000 rw-p 00106000 fd:00 2231950                        /usr/lib64/libm-2.18.so
34bee00000-34bee15000 r-xp 00000000 fd:00 2237334                        /usr/lib64/libgcc_s-4.8.3-20140911.so.1
34bee15000-34bf014000 ---p 00015000 fd:00 2237334                        /usr/lib64/libgcc_s-4.8.3-20140911.so.1
34bf014000-34bf015000 r--p 00014000 fd:00 2237334                        /usr/lib64/libgcc_s-4.8.3-20140911.so.1
34bf015000-34bf016000 rw-p 00015000 fd:00 2237334                        /usr/lib64/libgcc_s-4.8.3-20140911.so.1
34c5200000-34c52e9000 r-xp 00000000 fd:00 2230725                        /usr/lib64/libstdc++.so.6.0.19
34c52e9000-34c54e9000 ---p 000e9000 fd:00 2230725                        /usr/lib64/libstdc++.so.6.0.19
34c54e9000-34c54f1000 r--p 000e9000 fd:00 2230725                        /usr/lib64/libstdc++.so.6.0.19
34c54f1000-34c54f3000 rw-p 000f1000 fd:00 2230725                        /usr/lib64/libstdc++.so.6.0.19
34c54f3000-34c5508000 rw-p 00000000 00:00 0 
7f1b639c3000-7f1b639c8000 rw-p 00000000 00:00 0 
7f1b639e3000-7f1b639e6000 rw-p 00000000 00:00 0 
7fff565b8000-7fff565d9000 rw-p 00000000 00:00 0                          [stack]
7fff565fc000-7fff565fe000 r-xp 00000000 00:00 0                          [vdso]
7fff565fe000-7fff56600000 r--p 00000000 00:00 0                          [vvar]
ffffffffff600000-ffffffffff601000 r-xp 00000000 00:00 0                  [vsyscall]
         * 
         */
        for(int point2=l;point2<=r;point2=charlist[point2].next)
        {
            if(charlist[point2].value=='>')
            {
                if((charlist[charlist[point2].prev].value=='>')&&(charlist[point2].prev>=l))
                {
                    node_delete(point2);
                }
                else rightlist.push(point2);
            }
            else if(charlist[point2].value=='<')
            {
                if (rightlist.size()==0) break;
                int right=point2;
                int left=rightlist.top();
                int numcounter2[10]={0,0,0,0,0,0,0,0,0,0};
                bool if2n=1;
                for(int i=left;i<=right;i=charlist[i].next)
                {
                    if((charlist[i].value-'0')%2!=0) if2n=0;
                    numcounter2[charlist[i].value-'0']++;
                }
                for(int i=0;i<10;i++)
                {
                    for(int j=0;j<=i;j++)
                    {
                        numcounter[j]+=numcounter2[i];
                    }
                }
                if(if2n)//偶数,需要往回走并删除>
                {
                    rightlist.pop();
                    node_connect(charlist[left].prev,right);//直接链接>的前一个字符和<
                    point=charlist[right].prev;
                    if(rightlist.size()==0)
                    {
                        way_dist=0;
                        break;
                    }
                    int nextleft=rightlist.top();
                    for(int i=charlist[right].prev;i>=nextleft;i=charlist[i].prev)
                    {
                        if((charlist[i].value<='9')&&(charlist[i].value>'0'))
                        {
                            numcounter[charlist[i].value-'0']++;
                            charlist[i].value--;
                        }
                        else if(charlist[i].value=='0')
                        {
                            numcounter[charlist[i].value-'0']++;
                            node_delete(i);
                        }
                    }
                }
                else//奇数,直接链接>和<后一个
                {
                    rightlist.pop();
                    node_connect(left,charlist[right].next);
                    point=charlist[left].next;
                }

            }
        }
        //结束
        if(!((point>=l)&&(point<=r)))
        {
            break;
        }
        #endif
        if((charlist[point].value<='9')&&(charlist[point].value>'0'))
        {
            numcounter[charlist[point].value-'0']++;
            charlist[point].value--;
        }
        else if(charlist[point].value=='0')
        {
            numcounter[charlist[point].value-'0']++;
            node_delete(point);
        }
        else if(charlist[point].value=='>')
        {
            int lastpoint=(way_dist?charlist[point].prev:charlist[point].next);
            if((charlist[lastpoint].value=='>')||(charlist[lastpoint].value=='<'))
            {
                node_delete(lastpoint);
            }
            way_dist=1;
        }
        else if(charlist[point].value=='<')
        {
            int lastpoint=(way_dist?charlist[point].prev:charlist[point].next);
            if((charlist[lastpoint].value=='>')||(charlist[lastpoint].value=='<'))
            {
                node_delete(lastpoint);
            }
            way_dist=0;
        }
        if(way_dist)
        {
            point=charlist[point].next;
        }
        else
        {
            point=charlist[point].prev;
        }
    }
    printf("%d %d %d %d %d %d %d %d %d %d\n",numcounter[0],numcounter[1],numcounter[2],numcounter[3],numcounter[4],numcounter[5],numcounter[6],numcounter[7],numcounter[8],numcounter[9]);
}
int main()
{
    #ifndef DEBUG
    freopen("turing.in","r",stdin);
    freopen("turing.out","w",stdout);
    #endif
    int n,q;
    cin>>n>>q;
    getchar();
    for(int i=1;i<=n;i++)
    {
        charlist[i].originvalue=getchar();
    }
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        resetchain(l,r);
        solve(l,r);
    }
    #ifndef DEBUG
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}
