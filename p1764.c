int main(){short a,b,c,i;scanf("%hd%hd%hd",&a,&b,&c);for (i=0;i<101;i++){if((i%3==a)&&(i%5==b)&&(i%7==c)){printf("%d",i);return 0;}}exit(!puts("no answer"));}
