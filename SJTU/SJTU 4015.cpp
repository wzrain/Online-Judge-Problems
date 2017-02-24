#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int f[55];f[1]=f[2]=1;
    int reg;
    int a,b,n;scanf("%d%d%d",&a,&b,&n);
    for(int i=3;i<55;++i){
        f[i]=(a*f[i-1]+b*f[i-2])%7;
        if(f[i]==1&&f[i-1]==1){
            reg=i-2;
            break;
        }
    }
    int num=n%reg;
    if(!num)printf("%d",f[num+reg]);
    else printf("%d",f[num]);
    return 0;
}
