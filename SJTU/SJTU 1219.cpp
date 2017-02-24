#include <iostream>
#include <stdio.h>
using namespace std;

int num[200005];
int tree[200005];
int sorted[200005];
long long cnt=0;

void Merge(int a[],int p,int q,int r)
{
    int n1=q-p+1,n2=r-q;
    int *L=new int[n1+1];
    int *R=new int[n2+1];
    for(int i=0;i<n1;++i)L[i]=a[p+i-1];
    for(int j=0;j<n2;++j)R[j]=a[q+j];
    L[n1]=R[n2]=2147483647;
    int i=0,j=0;
    for(int k=p-1;k<r;++k){
        if(i<=n1&&L[i]<R[j]){a[k]=L[i];++i;}
        else if(i<=n1&&j<=n2&&L[i]==R[j]){a[k]=L[i];i++;j++;}
        else if(j<=n2){a[k]=R[j];++j;}
        if(i>n1&&j>n2)break;
    }
}

void mergeSort(int a[],int p,int r)
{
    if(p<r){
        int q=(p+r)/2;
        mergeSort(a,p,q);
        mergeSort(a,q+1,r);
        Merge(a,p,q,r);
    }
}

int index(int n,int low,int high)
{
    if(high-low<=1){
        if(n<sorted[low])return low-1;
        else if(n>=sorted[low]&&n<sorted[high])return low;
        else if(n>=sorted[high])return high;
    }
    int mid=(low+high)/2;
    if(n<=sorted[mid])index(n,low,mid);
    else index(n,mid+1,high);
}

int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&num[i]);
        sorted[i]=num[i];
    }
    mergeSort(sorted,2,n+1);
    int len=0;
    for(int i=1;i<=n;++i){
        if(sorted[i]==2147483647)break;
        len++;
    }
    for(int i=n;i>0;--i){
        long long tmpcnt=0;
        int tmp;
        if(num[i]%2)tmp=num[i]/2;
        else tmp=num[i]/2-1;
        int idx=index(tmp,1,len);
        for(int a=idx;a>0;a-=(a&-a))tmpcnt+=tree[a];
        cnt+=tmpcnt;
        for(int j=index(num[i],1,len);j<=len;j+=(j&-j))tree[j]++;
    }
    printf("%lld",cnt);
    return 0;
}
