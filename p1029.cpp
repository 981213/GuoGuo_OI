/*************************************************************************
	> File Name: p1029.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年09月21日 星期日 19时41分25秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
unsigned int numlist[1000005];
unsigned int sortedlist[1000005];
unsigned int templist[1000005];
unsigned int counter=0;
int merge(int _start,int _end)
{
        int _middle = (_start+_end)/2;
        memcpy(templist+_start,sortedlist+_start,sizeof(int)*(_end-_start+1));
        int a=_start;
        int b=_middle+1;
        int c=_start;
        while((a<=_middle)&&(b<=_end))
        {
            if(templist[a]<=templist[b])
            {
                sortedlist[c++]=templist[a++];
            }
            else
            {
                sortedlist[c++]=templist[b++];
                counter+=(_middle-a+1);
            }

        }
        while(a<=_middle)
        {
            sortedlist[c++]=templist[a++];
        }
        while(b<=_end)
        {
            sortedlist[c++]=templist[b++];
        }
        return 0;
}
int sort(int _start,int _end)
{
    if(_start<_end)
    {
        int _middle=(_start+_end)/2;
        sort(_start,_middle);
        sort(_middle+1,_end);
        merge(_start,_end);
    }
    else
    {
        sortedlist[_start]=numlist[_start];
    }
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>numlist[i];
    }
    sort(0,n-1);
    cout<<counter;
    return 0;
}

