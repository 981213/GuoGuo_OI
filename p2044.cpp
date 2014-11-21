#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
struct EDGE{
	int from,to,prevedge;
}edges[400020];
int edge_count=1;

struct NODE{
//	vector<int> all_edge;
	int weight;
    int lastedge;
}nodes[200010];
int n_node;

int weight_sum=0;
int max_weight=0;
void add_edge(int from,int to)
{
    edges[edge_count].prevedge=nodes[from].lastedge;
	edges[edge_count].from=from;
	edges[edge_count].to=to;
    nodes[from].lastedge=edge_count;
	edge_count++;
}
void connect_node(int a,int b)
{
    add_edge(a,b);
    add_edge(b,a);
}

void cal_weight(int a)
{
    int maxweight1=0,maxweight2=0;//2<1
    int weight_sum_cnt=0;
	for(int edgea=nodes[a].lastedge;edges[edgea].from;edgea=edges[edgea].prevedge)
	{
        int nodeaweight=nodes[edges[edgea].to].weight;
        if(nodeaweight>maxweight1)maxweight1=nodeaweight;
        else if(nodeaweight>maxweight2)maxweight2=nodeaweight;
        weight_sum_cnt=(weight_sum_cnt+nodeaweight)%10007;
	}
    #ifdef DEBUG
    cout<<maxweight1<<"*"<<maxweight2<<"="<<maxweight1*maxweight2<<endl;
    #endif
    if(maxweight1*maxweight2>max_weight)max_weight=maxweight1*maxweight2;
    for(int edgea=nodes[a].lastedge;edges[edgea].from;edgea=edges[edgea].prevedge)
    {
        int nodeaweight=nodes[edges[edgea].to].weight;
        weight_sum=(weight_sum+nodeaweight*(weight_sum_cnt-nodeaweight)+10007)%10007;
    }
}
int main()
{
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
    #ifdef DEBUG
    printf("Read Completed.\n");
    #endif
	for(int i=1;i<=n_node;i++)
	{
		cal_weight(i);
	}
	printf("%d %d",max_weight,weight_sum%10007);
	return 0;
}
