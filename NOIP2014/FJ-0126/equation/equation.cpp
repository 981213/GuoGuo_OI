#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
long long fastpow(int x,int y)
{
	int base=x;
	int res=1;
	while(y!=0)
	{
		if(y&1)
		{
			res*=base;
		}
		base*=base;
		y>>=1;
	}
	return res;
}
int n,m;
int an[110];
bool test_solve(int x)
{
	long long sum=0;
	for(int i=0;i<=n;i++)
	{
		sum+=an[i]*fastpow(x,i);
		#ifdef DEBUG
		//cout<<sum<<endl;
		#endif
	}
	return (sum==0)?1:0;
}
vector<int> solves;
int main()
{

	freopen("equation.in","r",stdin);
	#ifndef DEBUG
	freopen("equation.out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
	{
		scanf("%d",&an[i]);
	}
	if(m<=100)
	{
	for(int i=1;i<=m;i++)
	{
		if(test_solve(i))
		solves.push_back(i);
	}
	printf("%d\n",solves.size());
	for(int i=0;i<solves.size();i++)
	{
		printf("%d\n",solves[i]);
	}
	}
	else
	{
		printf("0");
	}
	return 0;
}
