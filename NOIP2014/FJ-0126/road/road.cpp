#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct EDGE{
	int from,to,prev;
}edges[200010];
int edge_count=0;
struct NODE{
	int last;
	bool have_edge;
	bool searched;
}nodes[100010];
int n,m;
void connect_nodes(int from,int to)
{
	edges[edge_count].from=from;
	edges[edge_count].to=to;
	if (nodes[from].have_edge)
	{
		edges[edge_count].prev=nodes[from].last;
	}
	else
	{
		edges[edge_count].prev=edge_count;
		nodes[from].have_edge=1;
	}
	nodes[from].last=edge_count;
	edge_count++;
}
int search(int start,int end,int value)
{
	#ifdef DEBUG
	cout<<"Searching:"<<start<<" "<<end<<" "<<value<<endl;
	#endif
	if(nodes[start].searched)
	{
		#ifdef DEBUG
		cout<<"-1"<<endl;
		#endif
		return -1;
	}
	else if(start==end)
	{
		#ifdef DEBUG
		cout<<value<<endl;
		#endif
		return value;
	}
	else if(!nodes[start].have_edge)
	{
		#ifdef DEBUG
		cout<<"-3"<<endl;
		#endif
		return -3;
	}
	else
	{
		bool markfail=0;
		int nextedge=nodes[start].last;
		int return_val=999999999;
		do
		{
			nodes[start].searched=1;
			int return_value_temp=search(edges[nextedge].to,end,value+1);
			nodes[start].searched=0;
			if(return_value_temp==-3)
			{
				markfail=1;
			}
			else if(return_value_temp==0)
			{
				//return 0;
			}
			else if((return_value_temp<return_val)&&(return_value_temp!=-1))
			{
				return_val=return_value_temp;
				markfail=0;
			}
			nextedge=edges[nextedge].prev;
		}
		while(edges[nextedge].prev!=nextedge);
			nodes[start].searched=1;
			int return_value_temp=search(edges[nextedge].to,end,value+1);
			nodes[start].searched=0;
			if(return_value_temp==-3)
			{
				markfail=1;
			}
			else if(return_value_temp==0)
			{
				//return 0;
			}
			else if((return_value_temp<return_val)&&(return_value_temp!=-1))
			{
				return_val=return_value_temp;
			}
		if((return_val!=999999999))
		{
			return (!markfail)?return_val:0;
		}
		else
		{
		#ifdef DEBUG
		cout<<(markfail?-3:0)<<endl;
		#endif
			return markfail?-3:0;
		}
	}
}
int main()
{
	#ifndef DEBUG
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int tempfrom,tempto;
		scanf("%d%d",&tempfrom,&tempto);
		connect_nodes(tempfrom,tempto);
	}
	int startnode,endnode;
	scanf("%d%d",&startnode,&endnode);
	int return_val_res=0;
	if((n<=100)&&(m<=200))
	return_val_res=search(startnode,endnode,0);
	if((return_val_res==0)||(return_val_res==-3))
	{
		printf("-1");
	}
	else
	{
		printf("%d",return_val_res);
	}
	
	return 0;
}
