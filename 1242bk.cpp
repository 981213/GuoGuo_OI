/*************************************************************************
	> File Name: p1242.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年09月28日 星期日 12时22分43秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> fruit;
void fruit_insert(int a)
{
    bool mark=1;
    for(int i=0;i<fruit.size();i++)
    {
        if(fruit[i]>=a)
        {
            fruit.insert(fruit.begin()+i,a);
            mark=0;
            break;
        }
    }
    if(mark)
    {
        fruit.push_back(a);
    }
}
int main()
{
    int n;
    cin>>n;
    long counter=0;
    for (int i=0;i<n;i++)
    {
        int temp1;
        cin>>temp1;
        fruit.push_back(temp1);
    }
    sort(fruit.begin(),fruit.end());
    while(fruit.size()>1)
    {
        int new_fruit=(fruit[0]+fruit[1]);
        counter+=new_fruit;
        fruit.erase(fruit.begin());
        fruit.erase(fruit.begin());
        fruit_insert(new_fruit);
    }
    cout<<counter;
    return 0;
}
