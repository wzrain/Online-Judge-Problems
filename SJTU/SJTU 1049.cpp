#include <iostream>
#include <stdio.h>
using namespace std;

int station[1005];
int inqueue[1005];
int outqueue[1005];

int main()
{
    int T;scanf("%d",&T);
    for(int t=0;t<T;++t){
        int N,M;bool flag=true;
        scanf("%d%d",&N,&M);
        for(int nn=0;nn<N;++nn)inqueue[nn]=nn;
        for(int n=0;n<N;++n)scanf("%d",&outqueue[n]);
        int out=0,top=0,in=0;
        while(out<N){
            if(inqueue[in]==outqueue[out]){
                in++;out++;continue;
            }
            else if(top>0&&outqueue[out]==station[top-1]){
                top--;out++;continue;
            }
            else if(top<M){
                station[top]=inqueue[in];
                top++;in++;continue;
            }
            else{flag=false;break;}
        }
        if(flag){
            printf("%s","YES\n");
        }
        else printf("%s","NO\n");
    }
    return 0;
}
