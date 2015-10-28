/*************************************************************************
	> File Name: p2263.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月22日 星期二 11时49分38秒
 ************************************************************************/

#include<cstdio>
#define MIN(a,b)((a)<(b)?(a):(b))
using namespace std;
struct _SegTree_Node_T{
        struct _SegTree_Node_T *lc, *rc;
        int l,r;
        int pair,sl,sr;
}nodes[400000*4+10],*Root;
int NodeCnt=0;
int n,m;
void BuildTree(int left,int right,struct _SegTree_Node_T *nownode)
{
        nownode->l=left;
        nownode->r=right;
        if(left==right)
        {
                char tmp=getchar();
                if(tmp==')')nownode->sr=1;
                else nownode->sl=1;
        }
        else
        {
                int mid=(left+right)>>1;
                nownode->lc=nodes+(NodeCnt++);
                nownode->rc=nodes+(NodeCnt++);
                BuildTree(left,mid,nownode->lc);
                BuildTree(mid+1,right,nownode->rc);
                nownode->pair=nownode->lc->pair+nownode->rc->pair;
                int newpair=MIN(nownode->lc->sl,nownode->rc->sr);
                nownode->pair+=newpair;
                nownode->sl=nownode->lc->sl-newpair+nownode->rc->sl;
                nownode->sr=nownode->rc->sr-newpair+nownode->lc->sr;
        }
}

int Query(int left,int right,struct _SegTree_Node_T *cur)
{
        int mid=(left+right)>>1;
        if((cur->l>=left)&&(cur->r<=right))return cur->pair;
        else return Query(left,mid,cur->lc)+Query(mid+1,right,cur->rc);
}

int main()
{
        scanf("%d%d",&n,&m);
        Root=nodes+(NodeCnt++);
        BuildTree(1,n,Root);
        while(m--)
        {
                int leftv,rightv;
                scanf("%d%d",leftv,rightv);
                printf("%d\n",Query(leftv,rightv,Root));
        }
        return 0;
}
