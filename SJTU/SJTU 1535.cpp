#include <iostream>
#include <stdio.h>

using namespace std;

int digitnum(int);
int possible_value(int,int,int,int);
int digit(int);

int digit(int x)
{
    int cnt=0;
    while(x){
        cnt++;
        x/=10;
    }
    return cnt;
}

int digitnum(int x)
{
    int cnt=0;
    while(x){
        cnt+=(x%10);
        x/=10;
    }
    return cnt;
}

int possible_value(int n,int k,int p,int q)
{
    int tmp=1;
    for(int i=0;i<k;++i)tmp*=n;
    return tmp*p+q;
}

int main()
{
    int k,p,q,l,r;
    scanf("%d%d%d",&k,&p,&q);
    scanf("%d%d",&l,&r);
    int cnt=0;int result[10000];int idx=0;
    int low,high,posval,n;
    if(digit(l)==digit(r)){
        low=digitnum(l/10+1);
        high=digitnum((r+1)/10*10-1);
    }
    else{
        low=1;
        int tmphigh1=(digit(l)-1)*9;
        int tmphigh2=digitnum((r+1)/10*10-1);
        high=(tmphigh1>tmphigh2)?tmphigh1:tmphigh2;
    }
    for(n=low;n<=high;++n){
        posval=possible_value(n,k,p,q);
        if(posval>=l&&posval<=r&&digitnum(posval)==n){
            cnt++;
            result[idx]=posval;
            idx++;
        }
    }
    printf("%d\n",cnt);
    if(cnt){
        for(int j=0;j<cnt;++j)printf("%d ",result[j]);
    }
    else printf("%d",-1);
    return 0;
}
