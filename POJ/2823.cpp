#include <iostream>
#include <stdio.h>
using namespace std;

int arr[1000005],maxq[1000005],minq[1000005],maxh=0,maxr=0,minh=0,minr=0,maxres[1000005],minres[1000005],cnt=0;

int main()
{
    int n,k;scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i)scanf("%d",&arr[i]);
    for(int i=0;i<k;++i){
        while(maxh!=maxr&&arr[i]>=arr[maxq[maxr-1]])maxr--;
        maxq[maxr++]=i;
        while(minh!=minr&&arr[i]<=arr[minq[minr-1]])minr--;
        minq[minr++]=i;
    }
    maxres[cnt]=arr[maxq[maxh]];
    minres[cnt]=arr[minq[minh]];
    cnt++;
    for(int i=k;i<n;++i){
        if(maxq[maxh]==i-k)maxh++;
        while(maxh!=maxr&&arr[i]>=arr[maxq[maxr-1]])maxr--;
        maxq[maxr++]=i;
        maxres[cnt]=arr[maxq[maxh]];
        if(minq[minh]==i-k)minh++;
        while(minh!=minr&&arr[i]<=arr[minq[minr-1]])minr--;
        minq[minr++]=i;
        minres[cnt]=arr[minq[minh]];
        cnt++;
    }
    for(int i=0;i<cnt;++i)printf("%d ",minres[i]);
    printf("%c",'\n');
    for(int i=0;i<cnt;++i)printf("%d ",maxres[i]);
    return 0;
}
