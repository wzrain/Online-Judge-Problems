#include <iostream>
#include <stdio.h>
using namespace std;

int tree[1005][1005];

int main()
{
    int n;scanf("%d",&n);
    int high=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){
            scanf("%d",&tree[i][j]);
            if(i>=2){
                if(j==1)tree[i][j]+=tree[i-1][j];
                else if(j==i)tree[i][j]+=tree[i-1][j-1];
                else{
                    int tmp=(tree[i-1][j]>tree[i-1][j-1])?tree[i-1][j]:tree[i-1][j-1];
                    tree[i][j]+=tmp;
                }
                //(i==n)high=(tree[i][j]>high)?tree[i][j]:high;
            }
            if(i==n)high=(tree[i][j]>high)?tree[i][j]:high;
        }
    }
    printf("%d",high);
    return 0;
}
