#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
struct EDGE{
	int nodea,nodeb;
}edges[200010];
int edge_count=0;

struct NODE{
	vector<int> all_edge;
	int weight;
}nodes[200010];
int n_node;

int weight_sum=0;
int max_weight=0;
void connect_node(int a,int b)
{
	edges[edge_count].nodea=a;
	edges[edge_count].nodeb=b;
	nodes[a].all_edge.push_back(edge_count);
	nodes[b].all_edge.push_back(edge_count);
	edge_count++;
}

void weight_add(int a)
{
	weight_sum=(weight_sum+a)%10007;
	if(max_weight<a)
	{
		max_weight=a;
	}
}

void cal_weight(int a)
{
	for(int i=0;i<nodes[a].all_edge.size();i++)
	{
		int nowedge=nodes[a].all_edge[i];
		int nextnode=((edges[nowedge].nodea==a)?edges[nowedge].nodeb:edges[nowedge].nodea);
		for(int j=0;j<nodes[nextnode].all_edge.size();j++)
		{
			int nowedge2=nodes[nextnode].all_edge[j];
			int nextnode2=((edges[nowedge2].nodea==nextnode)?edges[nowedge2].nodeb:edges[nowedge2].nodea);
			if(nextnode2==a) continue;
			weight_add(nodes[a].weight*nodes[nextnode2].weight);
		}
	}
}
int main()
{
	freopen("link.in","r",stdin);
	freopen("link.out","w",stdout);
	scanf("%d",&n_node);
	for(int i=0;i<n_node-1;i++)
	{
		int tempa,tempb;
		scanf("%d%d",&tempa,&tempb);
		connect_node(tempa,tempb);
	}
	for(int i=1;i<=n_node;i++)
	{
		scanf("%d",&nodes[i].weight);
	}
	for(int i=1;i<=n_node;i++)
	{
		cal_weight(i);
	}
	printf("%d %d",max_weight,weight_sum);
	return 0;
}
