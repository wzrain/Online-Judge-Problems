#include <iostream>
#include <stdio.h>
#define INF 200000000
#define Min(a,b) (a<b)?a:b
using namespace std;

int n,m,res=INF;

void dfs(int v,int s,int r,int h,int mm)
{
    if(mm==0){
        if(res>s&&v==n)res=s;
        return;
    }
    if(s>=res||v>n||2*(n-v)/r+s>=res)return;
    for(int i=r-1;i>=mm;--i){
        int mh=Min((n-v)/(i*i),h-1);
        for(int j=mh;j>=mm;--j){
            if(mm==m)s=i*i;
            dfs(v+i*i*j,s+2*i*j,i,j,mm-1);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    dfs(0,0,n+1,n+1,m);
    if(res==INF)printf("%d\n",0);
    else printf("%d\n",res);
    return 0;
}
