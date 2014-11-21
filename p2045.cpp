#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,k;
struct STATUS{
	int mintouch;
	int isable;
}f[10000][1000];
struct PIPE{
	int high,low;
	int up,down;
	bool ifpipe;
}pipes[10010];

int passed_pipes=0;
/*
int calc_mintouch(int x,int y)
{
	#ifdef DEBUG
	cout<<"calc_mintouch("<<x<<","<<y<<")"<<endl;
	#endif
	int mintouch_temp=1000001;
	if(f[x-1][y+pipes[x-1].down].isable)
	{
		mintouch_temp=f[x-1][y+pipes[x-1].down].mintouch;
			#ifdef DEBUG
			cout<<"		mintouch_res_a="<<mintouch_temp<<","<<f[x-1][y+pipes[x-1].down].mintouch<<endl;
			#endif
	}
	if((pipes[x].high==m)&&(!pipes[x].ifpipe)&&(y==m))
	{
		for(int i=m;i>pipes[x].high-pipes[x-1].up;i--)
		{
			#ifdef DEBUG
			cout<<"		mintouch_test2,"<<i<<"isable"<<f[x-1][i].isable<<" ";
			#endif
			if(f[x-1][i].isable)
			{
				mintouch_temp=(mintouch_temp>f[x-1][i].mintouch+1)?f[x-1][i].mintouch+1:mintouch_temp;
			}
			#ifdef DEBUG
			cout<<"		mintouch_res="<<mintouch_temp<<","<<f[x-1][i].mintouch+1<<endl;
			#endif
		}
	}
	for(int i=1;y-i*pipes[x-1].up>pipes[x-1].low;i++)
	{
		if(f[x-1][y-i*pipes[x-1].up].isable)
		{
			mintouch_temp=(mintouch_temp>f[x-1][y-i*pipes[x-1].up].mintouch+i)?f[x-1][y-i*pipes[x-1].up].mintouch+i:mintouch_temp;
		}
	}
	#ifdef DEBUG
	cout<<"	mintouch="<<mintouch_temp<<endl;
	#endif
	return mintouch_temp;
}
*/
void calc_mintouch(int x,int y)
{
    
}
bool test_line(int x)
{
	#ifdef DEBUG
	cout<<"			testing"<<x<<endl;
	#endif
	for(int i=1;i<=m;i++)
	{
		
		if(f[x][i].isable)
		{
			return 1;
		}
	}
	return 0;
}

int calc_mintouch_line(int x)
{
	int mintouch_temp=1000001;
	for(int i=1;i<=m;i++)
	{
		if((f[x][i].isable)&&(f[x][i].mintouch<mintouch_temp))
		{
			mintouch_temp=f[x][i].mintouch;
		}
	}
	return mintouch_temp;
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++)
	{
		pipes[i].high=m;
		pipes[i].low=0;
		scanf("%d%d",&pipes[i].up,&pipes[i].down);
	}
	pipes[n].high=m;
	pipes[n].low=0;
	for(int i=0;i<k;i++)
	{
		int tempx;
		scanf("%d",&tempx);
		pipes[tempx].ifpipe=1;
		scanf("%d%d",&pipes[tempx].low,&pipes[tempx].high);
	}
	for(int i=0;i<=m;i++)
	{
		f[0][i].mintouch=0;
		f[0][i].isable=1;
	}
    for(int i=0;i<n;i++)
	{
        for(int j=pipes[i].low!=0?:1;j<=pipes[i].high;j++)
		{
            if(f[i][j].isable)
            {
                calc_mintouch(i,j);
            }
        }
    }
    /*
	for(int i=0;i<=m;i++)
	{
		f[n][i].mintouch=1000000;
		f[n][i].isable=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j].mintouch=1000000;
			#ifdef DEBUG
			cout<<endl<<"test_"<<pipes[i].low<<" "<<pipes[i].high<<" "<<pipes[i].ifpipe<<" "<<j<<endl;
			#endif
			if((j>pipes[i].low)&&((j<pipes[i].high)||((j==pipes[i].high)&&(!pipes[i].ifpipe))))
			{
				f[i][j].isable=1;
				f[i][j].mintouch=calc_mintouch(i,j);
				if(f[i][j].mintouch>=1000000)
				{
					f[i][j].isable=0;
				}
			}
			else
			{
				f[i][j].isable=0;
			}
			#ifdef DEBUG
			cout<<"f "<<i<<" "<<j<<" isable="<<f[i][j].isable<<endl;
			#endif
		}
		if(test_line(i))
		{
			#ifdef DEBUG
			cout<<"line_test for "<<i<<" passed"<<endl;
			#endif
			if(pipes[i].ifpipe) passed_pipes++;
		}
		else
		{
			#ifdef DEBUG
			cout<<"line_test for "<<i<<" FAILED!"<<endl;
			#endif
			printf("0\n%d",passed_pipes);
			return 0;
		}
	}
	printf("1\n%d",calc_mintouch_line(n));
    */
	return 0;
}
