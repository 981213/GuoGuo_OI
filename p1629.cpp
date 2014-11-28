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
        return((x==other.x)&&(y==other.y)&&(from==other.from)&&(to==other.to));
    }
};
struct PNTRETVAL{
    struct POINT point1;
    struct POINT point2;
    short point_count;
};
vector<struct POINT> Search_Result;
static const short nextpntx[]={-1,0,1,0};
static const short nextpnty[]={0,-1,0,1};
struct PNTRETVAL next_point(struct POINT & point_from)
{
    struct PNTRETVAL retval;
    retval.point_count=0;
    struct POINT temppnt;
    temppnt.x=point_from.x+nextpntx[point_from.to];
    temppnt.y=point_from.y+nextpnty[point_from.to];
    #ifdef DEBUG
    cout<<"CUR"<<temppnt.x<<" "<<temppnt.y<<" "<<char(maptocalc[temppnt.x][temppnt.y]);
    #endif
    temppnt.from=(point_from.to+2)%4;
    if((temppnt.x>=0)&&(temppnt.x<n)&&(temppnt.y>=0)&&(temppnt.y<m))
    {
        if(maptocalc[temppnt.x][temppnt.y]=='S')
        {
            temppnt.to=(temppnt.from+2)%4;
            retval.point1=temppnt;
            retval.point_count++;
                #ifdef DEBUG
    cout<<"NEXTNUM=1"<<endl;
    #endif
            return retval;
        }
        else if(maptocalc[temppnt.x][temppnt.y]=='T')
        {
            temppnt.to=(temppnt.from+1)%4;
            retval.point1=temppnt;
            retval.point_count++;
            temppnt.to=(temppnt.from+3)%4;
            retval.point2=temppnt;
            retval.point_count++;
    #ifdef DEBUG
    cout<<"NEXTNUM=2"<<endl;
    #endif
            return retval;
        }
    }
    #ifdef DEBUG
    cout<<"NEXTNUM=0"<<endl;
    #endif
    return retval;
}
bool search_map(struct POINT & point_to_search,struct POINT & first_point,bool iftop=0)
{
    if(((point_to_search.x<0)||(point_to_search.x>=n)||(point_to_search.y<0)||(point_to_search.y>=m)))return 0;
    #ifdef DEBUG
    cout<<"("<<point_to_search.x<<","<<point_to_search.y<<")from "<<point_to_search.from<<" to"<<point_to_search.to<<endl;
    #endif
    if((searchedmap[point_to_search.x][point_to_search.y]))
    {
        if((point_to_search==first_point))
        {
            {
                Search_Result.push_back(point_to_search);
                searchedmap[point_to_search.x][point_to_search.y]=0;
                return 1;
            }
        }
        else
        {
            searchedmap[point_to_search.x][point_to_search.y]=0;
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
        if(search_map(retval.point1,first_point))
        {
            Search_Result.push_back(point_to_search);
            searchedmap[point_to_search.x][point_to_search.y]=0;
            return 1;
        }
    }
    else if(retval.point_count==0)
    {
        searchedmap[point_to_search.x][point_to_search.y]=0;
        return 0;
    }
    else if(retval.point_count==2)
    {
        if(search_map(retval.point1,first_point))
        {
            Search_Result.push_back(point_to_search);
            searchedmap[point_to_search.x][point_to_search.y]=0;
            return 1;
        }
        else if(search_map(retval.point2,first_point))
        {
            Search_Result.push_back(point_to_search);
            searchedmap[point_to_search.x][point_to_search.y]=0;
            return 1;
        }
    }
    searchedmap[point_to_search.x][point_to_search.y]=0;
    return 0;
}
void Print_Res()
{
    return;
}
int main()
{
    #ifdef DEBUG
    freopen ("data","r",stdin);
    #endif
    scanf("%d%d",&n,&m);
    struct POINT firstpnttemp;
    for(int i=0;i<n;i++)
    {
        getchar();
        for(int j=0;j<m;j++)
        {
            maptocalc[i][j]=getchar();
            if(maptocalc[i][j]=='T')
            {
                firstpnttemp.x=i;
                firstpnttemp.y=j;
            }
        }
    }
    firstpnttemp.from=0;
    firstpnttemp.to=1;
    if(!search_map(firstpnttemp,firstpnttemp,1))
    {
        firstpnttemp.to=3;
        if(!search_map(firstpnttemp,firstpnttemp,1))
        {
            firstpnttemp.from=2;
            if(!search_map(firstpnttemp,firstpnttemp,1))
            {
                firstpnttemp.to=1;
                search_map(firstpnttemp,firstpnttemp,1);
            }
        }
    }
    Print_Res();
    return 0;
}
