/*************************************************************************
	> File Name: p1495.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年11月14日 星期五 18时31分11秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
struct BLOCK
{
    int x,y;//方块坐标
    int sch_time;
    short state;
    /*方块状态
     * 0:
     * 000
     * 0X0
     * 000
     * 1:
     * 000
     * 0XT
     * 000
     * 2:
     * 0T0
     * 0X0
     * 000
     */
};
bool ifstates[5555555];
queue<BLOCK> blockstates;
char chlist[509][509];
int n,m;
int holex,holey;
//状态:上下左右
static const int state0nextpntx[]={-1,2,0,0};
static const int state0nextpnty[]={0,0,-2,1};
static const int state0nextpntstate[]={2,2,1,1};
static const int state1nextpntx[]={-1,1,0,0};
static const int state1nextpnty[]={0,0,-1,2};
static const int state1nextpntstate[]={1,1,0,0};
static const int state2nextpntx[]={-2,1,0,0};
static const int state2nextpnty[]={0,0,-1,1};
static const int state2nextpntstate[]={0,0,2,2};
bool check_if_block_ok(struct BLOCK blocktocheck)
{
    if(!((blocktocheck.x>=0)&&(blocktocheck.x<n)&&(blocktocheck.y>=0)&&(blocktocheck.y<m)))return 0;//当前所在位置不合法
    switch(blocktocheck.state)
    {
        case 0:
        return 1;
        case 1:
        if(blocktocheck.y+1<m)return 1;
        case 2:
        if(blocktocheck.x-1>=0)return 1;
    }
    return 0;
}
bool check_available(struct BLOCK blocktocheck)
{
    if(!check_if_block_ok(blocktocheck))return 0;
    if(ifstates[blocktocheck.state+blocktocheck.x*10+blocktocheck.y*10000])return 0;else ifstates[blocktocheck.state+blocktocheck.x*10+blocktocheck.y*10000]=1;
    #ifdef DEBUG
    cout<<"     Testing x="<<blocktocheck.x<<" y="<<blocktocheck.y<<" state="<<blocktocheck.state<<"Walked:"<<blocktocheck.sch_time<<endl;
    #endif
    switch(blocktocheck.state)
    {
        case 0:
            if((chlist[blocktocheck.x][blocktocheck.y]=='.')||(chlist[blocktocheck.x][blocktocheck.y]=='O'))return 1;
            break;
        case 1:
            if(chlist[blocktocheck.x][blocktocheck.y]!='#')
                if(/*!*/(blocktocheck.y+1<m))/* return 0;*/
                if(chlist[blocktocheck.x][blocktocheck.y+1]!='#') return 1;
                break;
        case 2:
            if(chlist[blocktocheck.x][blocktocheck.y]!='#')
                if(/*!*/(blocktocheck.x-1>=0))/* return 0;*/
                if(chlist[blocktocheck.x-1][blocktocheck.y]!='#') return 1;
                break;
        break;
    }
    #ifdef DEBUG
    cout<<"     Result:false"<<endl;
    #endif
    return 0;
}
int search_block(struct BLOCK blocktocheck)
{
    #ifdef DEBUG
    cout<<"Search x="<<blocktocheck.x<<" y="<<blocktocheck.y<<" state="<<blocktocheck.state<<"Walked:"<<blocktocheck.sch_time<<endl;
    #endif
    if((blocktocheck.state==0)&&(blocktocheck.x==holex)&&(blocktocheck.y==holey))return blocktocheck.sch_time;
    struct BLOCK tempblock;
    tempblock.sch_time=blocktocheck.sch_time+1;
    for(int i=0;i<4;i++)
    switch(blocktocheck.state)
    {
        case 0:
            tempblock.state=state0nextpntstate[i];
            tempblock.x=blocktocheck.x+state0nextpntx[i];
            tempblock.y=blocktocheck.y+state0nextpnty[i];
            if(check_available(tempblock))blockstates.push(tempblock);
            break;
        case 1:
            tempblock.state=state1nextpntstate[i];
            tempblock.x=blocktocheck.x+state1nextpntx[i];
            tempblock.y=blocktocheck.y+state1nextpnty[i];
            if(check_available(tempblock))blockstates.push(tempblock);
            break;
        case 2:
            tempblock.state=state2nextpntstate[i];
            tempblock.x=blocktocheck.x+state2nextpntx[i];
            tempblock.y=blocktocheck.y+state2nextpnty[i];
            if(check_available(tempblock))blockstates.push(tempblock);
            break;
    }
    return 0;
}
int main()
{
    scanf("%d%d",&n,&m);
    getchar();
    int x1=-1,y1=-1,x2=-1,y2=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            chlist[i][j]=getchar();
            if(chlist[i][j]=='X')
            {
                if(x1==-1)
                {
                    x1=i;
                    y1=j;
                }
                else
                {
                    x2=i;
                    y2=j;
                }
            }
            else if(chlist[i][j]=='O')
            {
                holex=i;
                holey=j;
            }
        }
        getchar();
    }
    if((x2==-1)&&(y2==-1))
    {
        struct BLOCK tempblock;
        tempblock.x=x1;
        tempblock.y=y1;
        tempblock.state=0;
        tempblock.sch_time=0;
        blockstates.push(tempblock);
    }
    else if(x1==x2)
    {
        struct BLOCK tempblock;
        tempblock.x=x1;
        tempblock.sch_time=0;
        if(y1==y2)
        {
            tempblock.y=y1;
            tempblock.state=0;
        }
        else if(y1<y2)
        {
            tempblock.y=y1;
            tempblock.state=1;
        }
        else
        {
            tempblock.y=y2;
            tempblock.state=1;
        }
        blockstates.push(tempblock);
    }
    else if(x1<x2)
    {
        struct BLOCK tempblock;
        tempblock.x=x2;
        tempblock.y=y1;
        tempblock.state=1;
        tempblock.sch_time=0;
        blockstates.push(tempblock);
    }
    else
    {
        struct BLOCK tempblock;
        tempblock.x=x1;
        tempblock.y=y1;
        tempblock.state=1;
        tempblock.sch_time=0;
        blockstates.push(tempblock); 
    }
    int dotime=0;
    ifstates[blockstates.front().state+blockstates.front().x*10+blockstates.front().y*10000]=1;
    while(!blockstates.empty())
    {
        dotime=search_block(blockstates.front());
        if(dotime)break;
        blockstates.pop();
    }
    if(dotime)
    {
        printf("%d",dotime);
    }
    else
    {
        printf("Impossible");
    }
    return 0;
}
