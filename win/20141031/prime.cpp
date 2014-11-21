#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
vector<long long> primes;
long long solved=2;
void prime_print(int m,int n)
{
     for(int i=0;i<primes.size();i++)
     {
             if(primes[i]<m)continue;
             if(primes[i]>n)break;
             printf("%d\n" , primes[i]);
     }
     printf("\n");
}
void solve(int m,int n)
{
     if(n<=solved) prime_print(m,n);
     else{
     for(int i=solved+1;i<n;i++)
     {
             bool mark=1;
             for(int j=primes.size()-1;j>=0;j--)
             {
                     if(i%primes[j]==0)
                     {
                                       mark=0;
                                       break;
                     }
             }
             if(mark)
             {
                     primes.push_back(i);
                     solved=i;
             }
     }
     prime_print(m,n);
     }
}
int main()
{
    #ifndef DEBUG
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    #endif
    int T;
    cin>>T;
    primes.push_back(2);
    for(int i=0;i<T;i++)
    {
            int m,n;
            cin>>m>>n;
            solve(m,n);
    }
    
    
    #ifndef DEBUG
    fclose(stdin);
    fclose(stdout);
    #else
    getchar();
    getchar();
    #endif
    return 0;
}
