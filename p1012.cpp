/*************************************************************************
	> File Name: p1012.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年06月02日 星期二 10时51分12秒
 ************************************************************************/

#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct Peo{
        string Name,Num;
        bool operator < (const struct Peo ano) const{
                if((Num.length()>ano.Num.length()))
                        return 1;
                else if(Num.length()==ano.Num.length())
                for(int i=0;(((i<Num.length())&&(i<ano.Num.length())));i++)
                        if(Num[i]>ano.Num[i])return 1;else if (Num[i]<ano.Num[i])return 0;
                if(Num==ano.Num)
                        return Name<ano.Name;
                else return 0;
        }
}peo[1010];
int main()
{
        int a;
        scanf("%d",&a);
        for(int i=0;i<a;i++)
                cin>>peo[i].Name>>peo[i].Num;
        sort(peo,peo+a);
        for(int i=0;i<a;i++)cout<<peo[i].Name<<endl;
        return 0;
}

