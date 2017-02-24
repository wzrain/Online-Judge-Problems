#include <iostream>
#include <stdio.h>

using namespace std;

void step(int,int,int);

int stp=0;

void step(int n,int x,int y)
{
    if(x==n||y==n||x==1||y==1){
        if(x<=y)stp+=(x+y-2);
        else stp+=(2*(n-1)+n-x+n-y);
    }
    else{
        stp+=(4*(n-1));
        step(n-2,x-1,y-1);
    }
}

int main()
{
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    step(n,x,y);
    printf("%d",stp);
    return 0;
}
