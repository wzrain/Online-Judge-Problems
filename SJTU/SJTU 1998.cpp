#include <iostream>

using namespace std;

void quicksort(int arr[],int,int);

void quicksort(int arr[],int low,int high)
{
    if(low>=high){return;}
    int first=low;
    int last=high;
    int key=arr[first];
    while(first<last){
        while(first<last&&arr[last]>=key)--last;
        arr[first]=arr[last];
        while(first<last&&arr[first]<= key)++first;
        arr[last]=arr[first];
    }
    arr[first]=key;
    quicksort(arr,low,first-1);
    quicksort(arr,first+1,high);
}

int main()
{
    int n;cin>>n;
    int *spot=new int[n];
    for(int i=0;i<n;++i)cin>>spot[i];
    quicksort(spot,0,n-1);
    int cnt=0;
    for(int k=0;k<n/2;++k)cnt+=(spot[n-1-k]-spot[k]);
    cout<<cnt<<endl;
    return 0;
}
