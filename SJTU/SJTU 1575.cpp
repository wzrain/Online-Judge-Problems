#include <iostream>
#include <stdio.h>

using namespace std;

bool check(int pos[],int,int,int);

bool check(int pos[],int x,int n,int m)
{
    int step=0,ans=0;
    for(int i=1;i<=n;++i){
        if(pos[i]-step<x)ans++;
        else step=pos[i];
    }
    return ans<=m;
}

int main()
{
    int l,n,m;
    scanf("%d%d%d",&l,&n,&m);
    int *pos=new int[n+2];
    pos[0]=0;pos[n+1]=l;
    for(int i=1;i<=n;++i)scanf("%d",&pos[i]);
    int low=0,high=l;
    while(low<=high){
        int mid=(low+high)/2;
        if(check(pos,mid,n+1,m))low=mid+1;
        else high=mid-1;
    }
    printf("%d",low-1);
    delete [] pos;
    return 0;
}
