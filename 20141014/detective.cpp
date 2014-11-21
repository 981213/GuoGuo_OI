/*************************************************************************
	> File Name: detective.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2014年10月14日 星期二 16时07分36秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
using namespace std;
map<string,int> students;//同学到编号的映射
vector<string> idtostudents;//编号到同学的映射
int words[101][3];//证词
bool studentstf[30];//1说真话,0说假话
/*
 * words[0] 证人
 * words[1] 证词类别
 * words[2] 证词值
 * 证词类别     证词值      意思
 * 0            students[XXXX]  XXXX is guilty
 * 1            students[XXXX]  XXXX is not guilty
 * 2            0~6         今天是Monday~Sunday
 * 3            0~6         今天不是Monday~Sunday
 * 4            无          废话
 */
int m,n,p;//M:同学数N:说谎数P:证言数
short guilty=100;//盗贼
bool toomanyanswers=0;
void test_tf()
{
#ifdef DEBUG
    cout<<"test_tf start"<<endl<<"studentstf:";
    for(int i=0;i<m;i++)
    {
        cout<<studentstf[i]<<" ";
    }
    cout<<endl;
#endif
    short ifstudents[30];//同学是否为盗贼 2 非 1 是 0 未判断
    short ifweek[7];//今天星期几,状态同上
    short guilty_temp=100;//盗贼
    short weekday=7;//星期
    memset(ifstudents,0,sizeof(ifstudents));//重置  
    memset(ifweek,0,sizeof(ifweek));
    bool iftrue=0;
    bool ifmarked=0;
    for(int i=0;i<p;i++)
    {

        if(studentstf[words[i][0]])
        {
            if(words[i][1]==0) words[i][1]=1;
            else if(words[i][1]==1) words[i][1]=0;
            else if(words[i][1]==2) words[i][1]=3;
            else if(words[i][1]==3) words[i][1]=2;
#ifdef DEBUG
            cout<<"FAKE:";
#endif
        }
        #ifdef DEBUG
        cout<<words[i][0]<<" "<<words[i][1]<<" "<<words[i][2]<<endl;
        #endif
        iftrue=0;
        ifmarked=0;
        switch(words[i][1])
        {
            case 0:
            if(((ifstudents[words[i][2]]==0)&&(guilty_temp==100))||((ifstudents[words[i][2]]==1)&&(guilty_temp==words[i][2])))
            {
                guilty_temp=words[i][2];
                ifstudents[words[i][2]]=1;
                iftrue=1;
            }
            break;
            case 1:
            if((ifstudents[words[i][2]]==0)||((ifstudents[words[i][2]]==2)))
            {
                ifstudents[words[i][2]]=2;
                iftrue=1;
            }
            break;
            case 2:
            if(((ifweek[words[i][2]]==0)&&(weekday==7))||((ifweek[words[i][2]]==1)&&(weekday==words[i][2])))
            {
                weekday=words[i][2];
                ifweek[words[i][2]]=1;
                iftrue=1;
            }
            break;
            case 3:
            if((ifweek[words[i][2]]==0)||((ifweek[words[i][2]]==2)))
            {
                ifweek[words[i][2]]=2;
                iftrue=1;
            }
            break;
            case 4:
                iftrue=1;
            break;
            default:
            iftrue=0;
            break;
        }
        if (i==p-1) ifmarked=1;

        if(studentstf[words[i][0]])
        {
            if(words[i][1]==0) words[i][1]=1;
            else if(words[i][1]==1) words[i][1]=0;
            else if(words[i][1]==2) words[i][1]=3;
            else if(words[i][1]==3) words[i][1]=2;
        }
                if(!iftrue) break;
    }

    if(iftrue)
    {
        if((guilty==100)||(guilty==guilty_temp))
        {
            guilty=guilty_temp;
        }
        else
        {
            toomanyanswers=1;
        }
    }
    if((ifmarked)&&(guilty_temp==100))
    {
        #ifdef DEBUG
        cout<<endl<<"TEST2:";
        #endif
        int counter=0;
        int guilty_temp2;
        for(int i=0;i<m;i++)
        {
            #ifdef DEBUG
            cout<<ifstudents[i]<<" ";
            #endif
            if(ifstudents[i]==2) counter++;
            else guilty_temp2=i;
        }
        #ifdef DEBUG
        cout<<endl<<"counter:"<<counter<<" guilty_temp2:"<<guilty_temp2<<endl;
        #endif
        if (counter==m-1)
        {
            if((guilty==100)||(guilty==guilty_temp2))
        {
            guilty=guilty_temp2;
        }
        else
        {
            toomanyanswers=1;
        }
        }

    }
#ifdef DEBUG
    if(iftrue) cout<<guilty_temp<<" "<<guilty<<" "<<toomanyanswers<<endl;
    cout<<"test_tf end"<<endl;
#endif
}
void generate_tf(int head,int fnum)//起始,说谎数
{
#ifdef DEBUG
//    cout<<head<<" "<<fnum<<endl;
#endif
    if(fnum==0)
    {
        if(head=m)
        {
            test_tf();
        }
        else
        {
            studentstf[head]=1;
            generate_tf(head+1,fnum);
            studentstf[head]=0;
        }
    }
    else if(head<m)
    {
        studentstf[head]=1;
        generate_tf(head+1,fnum-1);
        studentstf[head]=0;
        generate_tf(head+1,fnum);
    }
}
int main()
{
//    freopen("detective.in","r",stdin);
//    freopen("detective.out","w",stdout);
    cin>>m>>n>>p;
    for(int i=0;i<m;i++)//输入同学
    {
        string temp;//同学名称
        cin>>temp;
        students[temp]=i;
        idtostudents.push_back(temp);
    }
    for(int i=0;i<p;i++)//记录证词  注:比较!str.compare("XXXX")
    {
        string name;
        cin>>name;
        name.erase(name.end()-1);
        string temp;
        cin>>temp;
        bool mark=0;//是不是废话
        int word[3];//证词
        word[0]=students[name];
        if(!temp.compare("I"))
        {
            cin>>temp;
            if(!temp.compare("am"))
            {
                cin>>temp;
                if(!temp.compare("not"))
                {
                    cin>>temp;
                    if(!temp.compare("guilty."))
                    {
                        word[1]=1;
                        word[2]=word[0];
                        mark=1;
                    }
                }
                else if(!temp.compare("guilty."))
                {
                    word[1]=0;
                    word[2]=word[0];
                    mark=1;
                }
            }
            if(getchar()!='\n') mark=0;
        }
        else if(!temp.compare("Today"))
        {
            cin>>temp;
            word[1]=2;
            if(!temp.compare("is"))
            {
                cin>>temp;
                mark=1;
                if(!temp.compare("Monday."))
                    word[2]=0;
                else if(!temp.compare("Tuesday."))
                    word[2]=1;
                else if(!temp.compare("Wednesday."))
                    word[2]=2;
                else if(!temp.compare("Thursday."))
                    word[2]=3;
                else if(!temp.compare("Friday."))
                    word[2]=4;
                else if(!temp.compare("Saturday."))
                    word[2]=5;
                else if(!temp.compare("Sunday."))
                    word[2]=6;
                else
                    mark=0;
            }
            if(getchar()!='\n') mark=0;
        }
        else
        {
            string name2;
            name2=temp;
            cin>>temp;
            if(!temp.compare("is"))
            {
                cin>>temp;
                if(!temp.compare("not"))
                {
                    cin>>temp;
                    if(!temp.compare("guilty."))
                    {
                        word[1]=1;
                        word[2]=students[name2];
                        mark=1;
                    }
                }
                else if(!temp.compare("guilty."))
                {
                    word[1]=0;
                    word[2]=students[name2];
                    mark=1;
                }
                if(getchar()!='\n') mark=0;
            }
            bool mark2=0;
            for(int i=0;i<idtostudents.size();i++)
            {
                if(!idtostudents[i].compare(name2))
                {
                    mark2=1;
                    break;
                }
            }
            if(!mark2)
            {
                mark=0;
            }
        }
        if(!mark)
        {
            word[1]=4;
        }
        words[i][0]=word[0];
        words[i][1]=word[1];
        words[i][2]=word[2];
#ifdef DEBUG
        cout<<word[0]<<" "<<word[1]<<" "<<word[2]<<endl;
#endif
        if (words[i][1]==4)
        while(getchar()!='\n');
    }
    //证词记录结束
    generate_tf(0,n);
    if (guilty==100)
    {
        cout<<"Impossible";
    }
    else if(toomanyanswers)
    {
        cout<<"Cannot Determine";
    }
    else
    {
        cout<<idtostudents[guilty];
    }
//    fclose(stdin);
//    fclose(stdout);
    return 0;
}
