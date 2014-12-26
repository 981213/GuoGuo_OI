/*************************************************************************
	> File Name: p1248.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年12月19日 星期五 17时15分08秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;

int minnum,n;
long long workjudge;
multiset<int,greater<int> > nums;
int main()
{
    scanf("%d %d",&n,&minnum);
    char Operate;
    int Num;
    for(int i=0;i<n;i++)
    {
        scanf("\n%c %d",&Operate,&Num);
        switch(Operate)
        {
            case 'I':
            {
                if(Num<minnum)break;
                nums.insert(Num);
                break;
            }
            case 'A':
            {
                workjudge+=Num;
                break;
            }
            case 'S':
            {
                workjudge-=Num;
                break;
            }
            case 'F':
            {
                if((Num<=nums.size())&&(*(nums.begin()+Num-1)+workjudge>=minnum))
                printf("%d\n",AllocateNum[Num-1]+workjudge);
                else
                printf("-1\n");
                nums.get_allocator().deallocate(AllocateNum,Num);
                break;
            }
        }
    }
    int counter=0;
    int * AllocateNum=nums.get_allocator().allocate(nums.size());
    for(int i=0;i<nums.size();i++)
    {
        if(AllocateNum[i]+workjudge>=minnum)counter++;
    }
    printf("%d",counter);
    return 0;
}
