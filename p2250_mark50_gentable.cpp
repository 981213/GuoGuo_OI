/*************************************************************************
	> File Name: p2250_mark50_gentable.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年09月11日 星期五 16时43分13秒
 ************************************************************************/

#include<cstdio>
using namespace std;
int num1[]={1,2,3,4,5,6,7,8,9,11,22,33,44,55,66,77,88,99};
int num2[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int n1c=0;
int n2c=0;
int main()
{
        int val=0;
        for(int i=0;i<101;i++)
        {
                if(num1[n1c]==i)
                {
                        val++;
                        n1c++;
                }
                printf("%d,",val);
        }
        putchar('\n');
        val=0;
        for(int i=0;i<101;i++)
        {
                if(num2[n2c]==i)
                {
                        val++;
                        n2c++;
                }
                printf("%d,",val);
        }
        return 0;
}
