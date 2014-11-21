/*************************************************************************
	> File Name: p2033.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年09月19日 星期五 16时02分40秒
 ************************************************************************/

#include<iostream>
using namespace std;
short passage[1000];
short ramdicttime[1000];
bool iframdict[1000];
short m,n;
short start=0,end=0;
short ramdictcount=0;
short firstword;
bool iffirstword;
int main()
{
    cin>>m>>n;
    for(short i=0;i<n;i++)
    {
        cin>>passage[i];
    }
    for(short i=0;i<n;i++)
    {
        if(!(iframdict[passage[i]]))//已在内存中,则跳过该词
        {
            ramdicttime[end]=passage[i];//查词
            iframdict[passage[i]]=1;
            end++;
            ramdictcount++;
            if((end-start)>m)//内存已满
            {
                iframdict[ramdicttime[start]]=0;
                start++;
            }
        }
    }
    cout<<ramdictcount;
    return 0;

}
