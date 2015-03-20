/*************************************************************************
	> File Name: p1835.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年01月06日 星期二 10时08分32秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define CROSS(a,b,c) ((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x))
using namespace std;
struct POINT{
    double x,y;
}points[13];
struct LINE{
    int point1,point2;
}lines[13],RealDist[200];

int Point_Count;
int RealDist_Count;
int Tot_Point;
int i,j,k;
double Answer,DistTemp;
inline double CalDist(struct POINT & pnt1,struct POINT & pnt2)
{
    return sqrt((pnt1.x-pnt2.x)*(pnt1.x-pnt2.x)+(pnt1.y-pnt2.y)*(pnt1.y-pnt2.y));
}
#define L1P1 points[line1.point1]
#define L1P2 points[line1.point2]
#define L2P1 points[line2.point1]
#define L2P2 points[line2.point2]
inline bool If_Crossed(struct LINE & line1,struct LINE & line2)
{
    return ((CROSS(L2P1,L2P2,L1P1)*CROSS(L1P1,L2P2,L1P2)<=0)&&
            (CROSS(L1P1,L1P2,L2P1)*CROSS(L1P1,L1P2,L2P2)<=0)&&
            (CROSS(L1P1,L1P2,L2P1)!=0)&&
            (CROSS(L1P1,L1P2,L2P2)!=0));
}
int main()
{
    scanf("%d",&Tot_Point);
    for(Point_Count=1;Point_Count<=Tot_Point;++Point_Count)
    {
        scanf("%lf%lf",&points[Point_Count].x,&points[Point_Count].y);
    }
    for(i=0;i<=Tot_Point;++i)
    {
        scanf("%d%d",&lines[i].point1,&lines[i].point2);
    }
    for(i=1;i<=Tot_Point;i++)
    {
        for(j=i;j<=Tot_Point;j++)
        {
            RealDist[RealDist_Count].point1=i;
            RealDist[RealDist_Count].point2=j;
            for(int k=0;k<Tot_Point;k++)
            {
                if(If_Crossed(lines[k],RealDist[RealDist_Count]))
                {
                    RealDist_Count--;
                    break;
                }
            }
            RealDist_Count++;
        }
    }
    for(i=0;i<RealDist_Count;i++)
    {
        DistTemp=CalDist(points[RealDist[i].point1],points[RealDist[i].point2]);
        Answer=Answer>DistTemp?Answer:DistTemp;
    }
    printf("%.4lf",Answer);
    return 0;
}
