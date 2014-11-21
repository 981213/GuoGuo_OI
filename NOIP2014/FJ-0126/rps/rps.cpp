#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int inputa[210];
int inputb[210];
int n,na,nb;
int marka=0,markb=0;
int pointa=0,pointb=0;
int cust_check(int a,int b)//0 a:1 b:2
{
	if(a==b) return 0;
	else if(a==0)
	{
		switch(b)
		{
			case 1:
				return 2;
				break;
			case 2:
				return 1;
				break;
			case 3:
				return 1;
				break;
			case 4:
				return 2;
				break;
		}
	}
	else if(a==1)
	{
		switch(b)
		{
			case 0:
				return 1;
				break;
			case 2:
				return 2;
				break;
			case 3:
				return 1;
				break;
			case 4:
				return 2;
				break;
		}
	}
	else if(a==2)
	{
		switch(b)
		{
			case 0:
				return 2;
				break;
			case 1:
				return 1;
				break;
			case 3:
				return 2;
				break;
			case 4:
				return 1;
				break;
		}
	}
	else if(a==3)
	{
		switch(b)
		{
			case 0:
				return 2;
				break;
			case 1:
				return 2;
				break;
			case 2:
				return 1;
				break;
			case 4:
				return 1;
				break;
		}
	}
	else if(a==4)
	{
		switch(b)
		{
			case 0:
				return 1;
				break;
			case 1:
				return 1;
				break;
			case 2:
				return 2;
				break;
			case 3:
				return 2;
				break;
		}
	}
	return 0;
}
int main()
{
	freopen("rps.in","r",stdin);
	freopen("rps.out","w",stdout);
	scanf("%d%d%d",&n,&na,&nb);
	for(int i=0;i<na;i++)
	{
		scanf("%d",&inputa[i]);
	}
	for(int i=0;i<nb;i++)
	{
		scanf("%d",&inputb[i]);
	}
	for(int i=0;i<n;i++)
	{
		int temp_status=cust_check(inputa[pointa],inputb[pointb]);
		if(temp_status==1)
		{
			marka++;
		}
		else if(temp_status==2)
		{
			markb++;
		}
		pointa++;
		pointb++;
		if(pointa==na) pointa=0;
		if(pointb==nb) pointb=0;
	}
	printf("%d %d",marka,markb);
	return 0;
}
