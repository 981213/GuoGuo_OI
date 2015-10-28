/*************************************************************************
	> File Name: p1966.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月22日 星期二 16时45分18秒
 ************************************************************************/

#include<cstdio>
#include<cstring>
using namespace std;
struct _Loc_T{
	int vals[30];
	int top;
}places[30];
struct _Box_T{
	int place;
	int loc;
}boxes[30];
inline void Reset(int box)
{
	#define CurPlace places[boxes[box].place]
	#define CurLoc boxes[box].loc
	for(CurPlace.top--;CurPlace.top>CurLoc;CurPlace.top--)
	{
		boxes[CurPlace.vals[CurPlace.top]].place=CurPlace.top;
		boxes[CurPlace.vals[CurPlace.top]].loc=0;
		places[CurPlace.vals[CurPlace.top]].top=1;
		places[CurPlace.vals[CurPlace.top]].vals[0]=CurPlace.vals[CurPlace.top];
	}
	CurPlace.top++;
}
char opt1[8],opt2[8];
int n,val1,val2,opt1d,opt2d;
int main()
{
	scanf("%d",&n);
	for(register int i=0;i<n;i++)
	{
		places[i].top=1;
		places[i].vals[0]=i;
		boxes[i].place=i;
		boxes[i].loc=0;
	}
	while(scanf("%s%d%s%d",opt1,&val1,opt2,&val2)==4)
	{
		opt1d=(strcmp(opt1,"move")==0);
		opt2d=(strcmp(opt2,"onto")==0);
                if((val1==val2)||(boxes[val1].place==boxes[val2].place))continue;
		if(opt1d)//move
		{
			if(opt2d)//onto
			{
				Reset(val1);
				Reset(val2);
				#define OPT_CurPlace places[boxes[val2].place]
				OPT_CurPlace.vals[OPT_CurPlace.top++]=val1;
				places[boxes[val1].place].top--;
				boxes[val1].place=boxes[val2].place;
				boxes[val1].loc=OPT_CurPlace.top-1;
			}
			else//over
			{
				Reset(val1);
				OPT_CurPlace.vals[OPT_CurPlace.top++]=val1;
				places[boxes[val1].place].top--;
				boxes[val1].place=boxes[val2].place;
				boxes[val1].loc=OPT_CurPlace.top-1;
			}
		}
		else//pile
		{
			if(opt2d)//onto
                        {
                                Reset(val2);
                                int tmptop=boxes[val1].loc;
                                int tmpplace=boxes[val1].place;
                                for(int i=boxes[val1].loc;i<places[tmpplace].top;i++)
                                {
					OPT_CurPlace.vals[OPT_CurPlace.top++]=places[tmpplace].vals[i];
					boxes[places[tmpplace].vals[i]].place=boxes[val2].place;
					boxes[places[tmpplace].vals[i]].loc=OPT_CurPlace.top-1;
                                }
                                places[tmpplace].top=tmptop;
                        }
			else//over
			{
                                int tmptop=boxes[val1].loc;
                                int tmpplace=boxes[val1].place;
                                for(int i=boxes[val1].loc;i<places[tmpplace].top;i++)
                                {
					OPT_CurPlace.vals[OPT_CurPlace.top++]=places[tmpplace].vals[i];
					boxes[places[tmpplace].vals[i]].place=boxes[val2].place;
					boxes[places[tmpplace].vals[i]].loc=OPT_CurPlace.top-1;
                                }
                                places[tmpplace].top=tmptop;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d:",i);
		for(int j=0;j<places[i].top;j++)
		{
			printf(" %d",places[i].vals[j]);
		}
		putchar('\n');
	}
	return 0;
}
