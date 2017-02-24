#include <iostream>

using namespace std;

static long cnt=0;

struct index
{
    int data;
    int idx;
};

void quicksort(index arr[],int,int);
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
void quicksort(index arr[],int low,int high)
{
    if(low>=high){return;}
    int first=low;
    int last=high;
    index key=arr[first];
    while(first<last){
        while(first<last&&arr[last].data>=key.data)--last;
        arr[first]=arr[last];
        while(first<last&&arr[first].data<=key.data)++first;
        arr[last]=arr[first];
    }
    arr[first]=key;
    quicksort(arr,low,first-1);
    quicksort(arr,first+1,high);
}

int main()
{
    int n;cin>>n;
    index *stone1=new index[n];
    index *stone2=new index[n];
    for(int i=0;i<n;++i){
        cin>>stone1[i].data;
        stone1[i].idx=i+1;
    }
    for(int j=0;j<n;++j){
        cin>>stone2[j].data;
        stone2[j].idx=j+1;
    }
    quicksort(stone1,0,n-1);
    quicksort(stone2,0,n-1);
    int *sorder1=new int[n];int *sorder2=new int[n];
    for(int i=0;i<n;++i)sorder1[stone1[i].idx-1]=stone2[i].idx;
    for(int j=0;j<n;++j)sorder2[stone2[j].idx-1]=stone1[j].idx;
    mergeSort(sorder1,1,n);long cnt1=cnt;
    mergeSort(sorder2,1,n);long cnt2=cnt-cnt1;
    long result=(cnt1>cnt2)?cnt2:cnt1;
    cout<<result%99999997;
    return 0;
}
