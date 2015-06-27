#include<cstdio>
#define MAX(a,b) (a>b?a:b)
using namespace std;
struct NODE{
	NODE * father;
	NODE * leftson;
	NODE * rightson;
	int MaxNum;
	int Left,Right;
}Root;
int n,m;
void BuildTree(int Left,int Right,NODE * Now)
{
	Now->Left=Left;
	Now->Right=Right;
	if(Left==Right)
	{
		scanf("%d",&Now->MaxNum);
		return;
	}
	Now->leftson=new NODE;
	Now->rightson=new NODE;
	Now->leftson->father=Now;
	Now->rightson->father=Now;
	int Mid=(Left+Right)>>1;
	BuildTree(Left,Mid,Now->leftson);
	BuildTree(Mid+1,Right,Now->rightson);
	Now->MaxNum=MAX(Now->leftson->MaxNum,Now->rightson->MaxNum);
}
inline void PushUp(NODE * NowNode)
{
	bool Modified=1;
	NODE * AnoSon;
	while(NowNode->father&&Modified)
	{
		AnoSon=((NowNode==NowNode->father->leftson)?(NowNode->father->rightson):(NowNode->father->leftson));
		if(Modified=(NowNode->MaxNum != AnoSon->MaxNum))
		{
			NowNode->father->MaxNum=MAX(NowNode->MaxNum,AnoSon->MaxNum);
			NowNode=NowNode->father;
		}
	}
}
inline void Modify(int Loc,int Val)
{
	NODE * NowNode = &Root;
	while(NowNode->Left!=NowNode->Right)
	{
    #ifdef DEBUG
        if(NowNode)
        printf("Getting Leaf Node : Left=%d Right=%d Val=%d\n",NowNode->Left,NowNode->Right,NowNode->MaxNum);
    #endif
		NowNode=((NowNode->Left+NowNode->Right)>>1)>=Loc?NowNode->leftson:NowNode->rightson;
	}
	NowNode->MaxNum=Val;
    #ifdef DEBUG
    if(NowNode)
    printf("Modified Node : Left=%d Right=%d Val=%d\n",NowNode->Left,NowNode->Right,NowNode->MaxNum);
    #endif
	PushUp(NowNode);
}
int QueryNum(NODE * NowNode,int & Left,int & Right)
{
    #ifdef DEBUG
    if(NowNode)
    printf("Query:Left=%d Right=%d Now Node : Left=%d Right=%d Val=%d\n",Left,Right,NowNode->Left,NowNode->Right,NowNode->MaxNum);
    else
    printf("Pointer Empty!!\n");
    #endif
    
    if(((NowNode->Left)>=Left)&&((NowNode->Right)<=Right))
    {
        #ifdef DEBUG
        puts("Query End.Return.");
        #endif
        return NowNode->MaxNum;
    }
    else if(((NowNode->Left)<=Right)&&((NowNode->Right)>=Left))
    {
        #ifdef DEBUG
        puts("PushDown.");
        #endif
        int Num1=QueryNum(NowNode->leftson,Left,Right);
        int Num2=QueryNum(NowNode->rightson,Left,Right);
        return MAX(Num1,Num2);
    }
    else return -1;
}
int i,optype,num1,num2;
int main()
{
	scanf("%d%d",&n,&m);
	BuildTree(1,n,&Root);
	for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&optype,&num1,&num2);
        if(optype)
        Modify(num1,num2);
        else
        printf("%d\n",QueryNum(&Root,num1,num2));
    }
}
