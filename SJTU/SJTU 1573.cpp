#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n,m,score=0;scanf("%d%d",&n,&m);
    int color[100005],num[100005];color[0]=num[0]=0;
    for(int i=1;i<=n;++i)scanf("%d",&num[i]);
    for(int j=1;j<=n;++j)scanf("%d",&color[j]);
    int colorsum[2][100005];colorsum[0][0]=colorsum[1][0]=0;
    int index[2][100005];index[0][0]=index[1][0]=0;
    for(int i=1;i<=n;++i){
        colorsum[i%2][color[i]]+=num[i];
        colorsum[i%2][color[i]]%=10007;
        index[i%2][color[i]]++;
    }
    for(int i=1;i<=n;++i){
        score+=(colorsum[i%2][color[i]]*i%10007+(index[i%2][color[i]]-2)%10007*num[i]%10007*i%10007);
        score%=10007;
    }
    printf("%d",score);
    return 0;
}
