#include <iostream>
#include <stdio.h>
using namespace std;

int result[5000];

int main(){
    result[0]=0;
    result[1]=result[2]=1;
    for(int i=3;i<=2040;++i){
        result[i]=(result[i-1]+result[i-2])%2010;
    }
    long long n;scanf("%lld",&n);
    int tmp=n%2040;
    printf("%d",result[tmp]);
    return 0;
}
