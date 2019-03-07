#include <iostream>
#include <stdio.h>

using namespace std;

int spot[100005];

void quicksort(int arr[], int low, int high)
{
  if(low>=high)return;
  int first=low, last=high;
  int key=arr[first];
  while(first<last){
    while(first<last&&arr[last]>=key)--last;
    arr[first]=arr[last];
    while(first<last&&arr[first]<=key)++first;
    arr[last]=arr[first];
  }
  arr[first]=key;
  quicksort(arr,low,first-1);
  quicksort(arr,first+1,high);
}

int main()
{
  int n;
  scanf("%d", &n);
  for(int i=0;i<n;++i)scanf("%d",&spot[i]);
  quicksort(spot,0,n-1);
  int dist=0, p=0;
  while(p<(n/2)){
    dist+=(spot[n-p-1]-spot[p]);
    p++;
  }
  printf("%d", dist);
  return 0;
}
