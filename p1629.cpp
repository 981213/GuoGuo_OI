/*************************************************************************
	> File Name: p1629.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年11月21日 星期五 16时01分36秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
int n,m;
char maptocalc[801][801];
bool searchedmap[801][801];
struct POINT{
    int x,y;
    short from,to;
    //0上1左2下3右
    bool operator== (const struct POINT & other) const
    {
        return((x==other.x)&&(y==other.y)&&(((from==from)&&(to==to))||((from==to)&&(to==from))));
    }
};
struct PNTRETVAL{
    struct POINT point1;
    struct POINT point2;
    short point_count;
};
static const short nextpntx[]={-1,0,1,0};
static const short nextpnty[]={0,-1,0,1};
struct PNTRETVAL next_point(struct POINT & point_from)
{
    struct PNTRETVAL retval;
    retval.point_count=0;
    struct POINT temppnt;
    temppnt.x=point_from.x+nextpntx[point_from.to];
    temppnt.y=point_from.y+nextpnty[point_from.to];
    if((temppnt.x>=0)&&(temppnt.x<m)&&(temppnt.y>=0)&&(temppnt.y<n))
    {
        if(maptocalc[temppnt.x][temppnt.y]=='S')
        {
            temppnt.to=temppnt.from+2%4;
            retval.point1=temppnt;
            retval.point_count++;
            return retval;
        }
        else if(maptocalc[temppnt.x][temppnt.y]='T')
        {
            temppnt.to=temppnt.from+1%4;
            retval.point1=temppnt;
            retval.point_count++;
            temppnt.to=temppnt.from+3%4;
            retval.point2=temppnt;
            retval.point_count++;
            return retval;
        }
    }
    return retval;
}
bool search_map(struct POINT & point_to_search,struct POINT & first_point,bool iftop=0)
{
    if((searchedmap[point_to_search.x][point_to_search.y]))
    {
        if((point_to_search==first_point))
        {
            if(!iftop)
            {
                return 1;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        searchedmap[point_to_search.x][point_to_search.y]=1;
    }
    struct PNTRETVAL retval=next_point(point_to_search);
    if(retval.point_count==1)
    {
        return search_map(retval.point1,first_point);
    }
    else if(retval.point_count==0)
    {
        return 0;
    }
    else if(retval.point_count==2)
    {
        return search_map(retval.point1,first_point)&&search_map(retval.point2,first_point);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=0;i<n;i++)
    {
        for(int j=0;i<m;i++)
        {
            maptocalc[i][j]=getchar();
        }
        getchar();
    }
    
    return 0;
}
