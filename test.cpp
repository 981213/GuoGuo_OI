#include<stdio.h>
int a[3000];
int main()
{
	int n,i,j,ans=0;
	scanf("%d",&n);
	n-=4;
	a[0]=6;
	a[1]=2;
	a[2]=5;        
	a[3]=5;        
	a[4]=4;
    a[5]=5;        
	a[6]=6;        
	a[7]=3;        
	a[8]=7;        
	a[9]=6;
    for(i=10;i<=99;i++)
    {
    	a[i]=a[i%10]+a[i/10];
    }
    for(i=100;i<=999;i++)
    {
    	a[i]=a[i%10]+a[i/100]+a[i%100/10];
    }
    for(i=1000;i<=2000;i++)
    {
    	a[i]=a[i%10]+a[i%100/10]+a[i%1000/10]+a[i%10000/10];
    }
    for(i=0;i<1000;i++)
    	for(j=0;j<1000;j++)
    	{
    		if(a[i]+a[j]+a[i+j]==n)
    		{
    			ans++;
			printf("%d+%d=%d Used:%d+%d+%d+4=%d\n",i,j,i+j,a[i],a[j],a[i+j],a[i]+a[j]+a[i+j]+4);
    		}
    	}
    printf("%d",ans);
    return 0;
}
