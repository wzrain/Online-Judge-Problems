#include <iostream>
#include <stdio.h>

using namespace std;

static long cnt=0;

void Merge(int a[],int,int,int);
void mergeSort(int a[],int,int);

void Merge(int a[],int p,int q,int r)
{
    int n1=q-p+1,n2=r-q;
    int *L=new int[n1+1];
    int *R=new int[n2+1];
    for(int i=0;i<n1;++i)L[i]=a[p+i-1];
    for(int j=0;j<n2;++j)R[j]=a[q+j];
    L[n1]=R[n2]=100001;
    int i=0,j=0;
    for(int k=p-1;k<r;++k){
        if(L[i]<=R[j]){a[k]=L[i];++i;}
        else{a[k]=R[j];++j;cnt+=q-p+1-i;}
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

int main()
{
    int n;scanf("%d",&n);
    int *height=new int[n];
    for(int i=0;i<n;++i)scanf("%d",&height[i]);
    mergeSort(height,1,n);
    cout<<cnt;
    return 0;
}
