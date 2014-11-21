/*************************************************************************
	> File Name: p1778.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年09月19日 星期五 16时33分23秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
struct person
{
    int Vi;//初始工资
    int level;//管理层
    int manager;//上司
    bool iflevel;//是否标记过管理层
    bool ifadded;//是否加过
};
struct person people[100001];
int modaction[100001];
bool ifmodaction[100001];
short numofaction=0;
int q,n;
int vsumA=0,vsumB=0;
int levelmark(int persontomark)
{
    if(people[persontomark].iflevel)
    {
        return people[persontomark].level;
    }
    else
    {
        people[persontomark].iflevel=1;
        people[persontomark].level=levelmark(people[persontomark].manager)+1;
    }
}
void addv()
{
    for(int i=1;i<=n;i++)
    {
        if(ifmodaction[people[i].level])
        people[i].Vi+=modaction[people[i].level];
    }
    memset(ifmodaction,0,sizeof(ifmodaction));
}
int result()
{
    if (vsumA>vsumB)
        return vsumA-vsumB;
    else
        return vsumB-vsumA;
}
void query(int persona,int personb,bool toplevel)
{
//    cout<<"Person A="<<persona<<" Person B="<<personb<<endl;
//    cout<<"Before Add:|Vsum|="<<result()<<" VsumA="<<vsumA<<" VsumB="<<vsumB<<endl;
    
        if(!(people[persona].ifadded))
        {
            if((people[persona].level%2)) 
            {
                vsumA+=people[persona].Vi;
            }
            else
            {
                vsumB+=people[persona].Vi;
            }
            people[persona].ifadded=1;

        }
        if(!(people[personb].ifadded))
        {
            if((people[personb].level%2)) 
            {
                vsumA+=people[personb].Vi;
            }
            else
            {
                vsumB+=people[personb].Vi;
            }
            people[personb].ifadded=1;
        }
//     cout<<"After Add:|Vsum|="<<result()<<" VsumA="<<vsumA<<" VsumB="<<vsumB<<endl;
    
    if(persona==personb)
    {
    if(toplevel)
    {
        cout<<result()<<endl;
        vsumA=0;
        vsumB=0;
    }
        people[persona].ifadded=0;
        people[personb].ifadded=0;
        return;
    }
    else
    {
        if(people[persona].level>people[personb].level)
            query(people[persona].manager,personb,0);
        else
            query(persona,people[personb].manager,0);
        people[persona].ifadded=0;
        people[personb].ifadded=0;
    }
    if(toplevel)
    {
        cout<<result()<<endl;
        vsumA=0;
        vsumB=0;
//        cout<<"After Reset(Toplevel):|Vsum|="<<result()<<" VsumA="<<vsumA<<" VsumB="<<vsumB<<endl;
    }
//    cout<<"End:|Vsum|="<<result()<<" VsumA="<<vsumA<<" VsumB="<<vsumB<<endl;
}
int main()//本题员工从1~n编号!!!!!!!!
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>people[i].Vi;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>people[i].manager;
        if(people[i].manager==-1)
        {
            people[i].level=1;
            people[i].iflevel=1;
        }
    }
    //标记管理层
    for(int i=1;i<=n;i++)
    {
        levelmark(i);
    }
    for(int i=0;i<q;i++)
    {
        char a;
        int b,c;
        cin>>a>>b>>c;
        if(a=='M')
        {
            ifmodaction[b]=1;
            modaction[b]=c;
        }
        else if(a=='A')
        {
            addv();
//            cout<<"Querying..."<<endl;
            query(b,c,1);
        }
    }
    return 0;
}
