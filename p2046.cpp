#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
int d,n;
int citycount[150][150];
struct NODE{
	int x,y,maxn;
}maxnode;
int maxx,maxy;
int maxnodecount=0;
using namespace std;
int main()
{
	scanf("%d",&d);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int tempx,tempy;
		scanf("%d%d",&tempx,&tempy);
		scanf("%d",&citycount[tempx][tempy]);
		if(tempx>maxx)maxx=tempx;
		if(tempy>maxy)maxy=tempy;
	}
	for(int i=1;i<150;i++)
	{
		citycount[i][0]+=citycount[i-1][0];
	}
	for(int i=1;i<150;i++)
	{
		citycount[0][i]+=citycount[0][i-1];
	}
	for(int i=1;i<150;i++)
	{
		for(int j=1;j<150;j++)
		{
			citycount[i][j]+=citycount[i-1][j]+citycount[i][j-1]-citycount[i-1][j-1];
		}
	}
	#ifdef DEBUG
	for(int i=0;i<=maxx;i++)
	{
		for(int j=0;j<=maxy;j++)
		{
			cout<<citycount[i][j]<<" ";
		}
		cout<<endl;
	}
	#endif
	for(int i=0/*d*/;i<129/*-d*/;i++)
	{
		for(int j=0/*d*/;j<129/*-d*/;j++)
		{
			struct NODE tempnode;
			tempnode.x=i;
			tempnode.y=j;
			tempnode.maxn=citycount[i+d][j+d]
				-(((j-d-1>=0))?citycount[i+d][j-d-1]:0)
				-((i-d-1>=0)?citycount[i-d-1][j+d]:0)
				+(((i-d-1>=0)&&(j-d-1>0))?citycount[i-d-1][j-d-1]:0);
			if(tempnode.maxn>maxnode.maxn)
			{
				#ifdef DEBUG
				cout<<i<<" "<<j<<" "<<tempnode.maxn<<endl;
				#endif
				maxnode=tempnode;
				maxnodecount=1;
			}
			else if(tempnode.maxn==maxnode.maxn)
			{
				maxnodecount++;
			}
		}
	}
	printf("%d %d",maxnodecount,maxnode.maxn);
	return 0;
}
