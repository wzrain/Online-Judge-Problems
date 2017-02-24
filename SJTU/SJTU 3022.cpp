#include <iostream>
#include <stdio.h>

using namespace std;

int a[3][2][10005];
int len;

void add(int l1,int l2,int r1,int r2,int r3,int r4)
{
    len=(a[r1][r2][0]>a[r3][r4][0])?a[r1][r2][0]:a[r3][r4][0];
    int addtmp=0;
    for(int i=10000;i>10000-len;--i){
        a[l1][l2][i]=(a[r1][r2][i]+a[r3][r4][i]+addtmp)%10;
        addtmp=(a[r1][r2][i]+a[r3][r4][i]+addtmp)/10;
    }
    if(addtmp){
        a[l1][l2][10000-len]=1;
        len++;
    }
    a[l1][l2][0]=len;
}

int main()
{
    int n;scanf("%d",&n);
    a[0][0][10000]=a[0][1][10000]=1;
    a[1][0][10000]=a[1][1][10000]=2;
    a[0][0][0]=a[1][0][0]=a[0][1][0]=a[1][1][0]=1;
    for(int i=2;i<n;++i){
        add(i%3,0,(i%3+2)%3,1,(i%3+2)%3,0);
        add(i%3,1,(i%3+2)%3,0,(i%3+1)%3,0);
        //cout<<len<<endl;
    }
    add(((n-1)%3+1)%3,0,(n-1)%3,0,(n-1)%3,1);
    //cout<<len;
    for(int l=10000-len+1;l<=10000;++l)printf("%d",a[((n-1)%3+1)%3][0][l]);
    return 0;
}
