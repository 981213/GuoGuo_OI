/*************************************************************************
	> File Name: matches.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年10月17日 星期五 15时57分43秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
using namespace std;
short n;//火柴棍总数量 - 4 即拼数字用的火柴棍
int cases=0;//总可能数
map<int,bool> same_num_table;//数字相同时是否计算过
static const short match_table[]={6,2,5,5,4,5,6,3,7,6};
static const short result_table[]={0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,2 ,8 ,11 ,6 ,13 ,29 ,38 ,40 ,70 ,98 ,132 };
void gennum1(short n1);
void gennum2(int num1,short n2);
void checknum(int num1,int num2,short n3);
vector<int> gen1num(short na);//根据na生成一个可能的数字的序列;
vector<int> gennum(short n1,short n2,bool ifhead);//用n1根火柴棒生成n2位数
int main()
{
#ifndef DEBUG
	freopen("matches.in","r",stdin);
	freopen("matches.out","w",stdout);
#endif
	cin>>n;
#ifdef DEBUG
	n-=4;
	gennum1(n);
	cout<<cases;
#endif
#ifndef DEBUG
    cout<<result_table[n];
	fclose(stdin);
	fclose(stdout);
#endif
    return 0;
}
vector<int> gen1num(short na)
{
    vector<int> result;
    for(short i=0;i<10;i++)
    {
        if(match_table[i]<=n)
        {
            result.push_back(i);
        }
    }
    return result;
}
short used_match_count(int num)
{
    int counter=0;
    while(num>10)
    {
        counter+=match_table[num%10];
        num/=10;
    }
    counter+=match_table[num%10];
    return counter;
}
vector<int> gennum(short n1,short n2,bool ifhead=1)
{
    if(n2==1)
    {
        return gen1num(n1);
    }
    else
    {
        vector<int> result;
        vector<int> numa=gen1num(n1);
        for(int i=0;i<numa.size();i++)
        {
            if((ifhead)&&(numa[i]==0)) continue;
            vector<int> numb=gennum(n-used_match_count(numa[i]),n2-1,0);
            for(short j=0;j<numb.size();j++)
            {
                result.push_back(numb[j]+numa[i]*pow(10,n2-1));
            }
        }
        return result;
    }
}
void gennum1(short n1)
{
	for(short i=1;i<=n1/4;i++)//让第一组数字生成为1~n1/4位数
    {
        vector<int> numres1=gennum(n1,i);
        for(int i=0;i<numres1.size();i++)
        {
            gennum2(numres1[i],n1-used_match_count(numres1[i]));
        }
    }
}
void gennum2(int num1,short n2)
{
    short num1count=used_match_count(num1);
    for(short i=1;i<=n/4;i++)//让第二组数字生成为1~n1/4位数
    {
        vector<int> numres1=gennum(n2,i);
        for(int i=0;i<numres1.size();i++)
        {
            short leftmatch=n-used_match_count(numres1[i])-num1count;
            if(leftmatch>1) checknum(num1,numres1[i],leftmatch);
        }
    }
}
void checknum(int num1,int num2,short n3)
{
    if(used_match_count(num1+num2)==n3)
    {
        if(num1!=num2)
        {
            cases++;
        }
        else if(!(same_num_table[num1]))
        {
            cases++;
            same_num_table[num1]=true;
        }
#ifdef DEBUG
            cout<<endl<<num1<<"+"<<num2<<"="<<num1+num2<<endl;
#endif
    }
}
