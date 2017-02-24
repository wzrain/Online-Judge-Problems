#include <iostream>

using namespace std;

long long quickmode(int,int,long long);

long long quickmode(int a,int b,long long mode)
{
    long long ans=1,tmp=a;
    tmp=tmp%mode;
    while(b>0){
        if(b%2)ans=(ans*tmp)%mode;
        b/=2;tmp=(tmp*tmp)%mode;
    }
    return ans;
}

int main()
{
    int n,m,k,x;cin>>n>>m>>k>>x;
    long long mode=m*n;
    long long ans=quickmode(10,k,mode);
    for(long long i=0;i<ans;++i)x=(x+m)%n;
    cout<<x;
    return 0;
}
