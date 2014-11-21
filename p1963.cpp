/*************************************************************************
	> File Name: p1963.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年10月20日 星期一 13时43分46秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<unsigned short> num;
unsigned short result[102];
unsigned int reslen;
int main()
{
    string tempinput;
    cin>>tempinput;
    for(int i=0;i<tempinput.length();i++)
    {
        unsigned char temp=tempinput[i];
        num.push_back(temp-'0');
    }
    int left=0;
    for(int i=0;i<num.size();i++)
    {
        unsigned short temp=(num[i]+left*10)%2;
        num[i]=(num[i]+left*10)/2;
        left=temp;
    }
    vector<unsigned short> num1=num;
    vector<unsigned short> num2=num;
    num2[num2.size()-1]+=left;
    for(int i=num1.size()-1;i>=0;i--)
    {
        for(int j=num2.size()-1;j>=0;j--)
        {
            unsigned short temp=num1[i]*num2[j];
            int temp2=(result[num2.size()-1-j+(num1.size()-1-i)]+temp);
            result[num2.size()-1-j+(num1.size()-1-i)]=temp2%10;
            result[num2.size()-1-j+(num1.size()-1-i)+1]+=temp2/10;
            reslen=num2.size()-1-j+(num1.size()-1-i)+1;
        }
    }
    bool mark=1;
    for(int i=reslen;i>=0;i--)
    {
        if(mark)
        {
            if(result[i]==0) continue;
            else mark=0;
        }
        cout<<result[i];
    }
    return 0;
}
