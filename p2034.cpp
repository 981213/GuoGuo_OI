#include<stdio.h>
int a,b,c=1,d;
int main(){scanf("%d",&a);getchar();for(;a;a--){while((b=getchar())!='\n')c=((d=!d)?(b=='l'?c*2:c*2+2):(b=='l'?c*2-1:c*2+1))%1000000007;printf("%d\n",c);c=!(d=0);}}
