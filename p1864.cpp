/*************************************************************************
	> File Name: p1864.cpp
	> Author: GuoGuo
	> Mail: gch981213@gmail.com
	> Created Time: 2015年06月28日 星期日 10时50分07秒
 ************************************************************************/

#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define calc() tmp=(((a*res+b)*res+c)*res+d)
float hackres(float res)
{
    if(res>0)res+=0.004;
    return res;
}
int main()
{
    register float a,b,c,d,res,tmp;
    scanf("%f%f%f%f",&a,&b,&c,&d);
    for(res=-100.00;res<60;res+=0.1)
    {
        calc();
        if((tmp<3)&&(tmp>-3))
        {
            for(;res<60;res+=0.01)
            {
                calc();
                if((tmp<0.1)&&(tmp>-0.1))break;
            }
            for(;res<60;res+=0.001)
            {
                calc();
                if((tmp<0.05)&&(tmp>-0.05))break;
            }
            for(;res<60;res+=0.00001)
            {
                calc();
                if((tmp<0.008)&&(tmp>-0.008)){printf("%.02f ",hackres(res));break;
            }}
        }
    }
    return 0;
}

