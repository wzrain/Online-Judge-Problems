#include <iostream>
#include <stdio.h>
using namespace std;

int arr[400005];
int q[400005];
int head=0,rear=1;

int main()
{
    int n,k;scanf("%d%d",&k,&n);
    for(int i=0;i<n;++i){
        scanf("%d",&arr[i]);
        //arr[n+i]=arr[i];
    }
    q[head]=0;
    for(int i=1;i<k;++i){
        while(head!=rear){
            if(arr[i]>=arr[q[rear-1]])rear--;
            else{
                q[rear]=i;
                rear++;
                break;
            }
        }
        if(head==rear){
            q[head]=i;
            rear++;
        }
    }
    int ans=arr[q[head]];
    printf("%d ",ans);
    for(int i=k;i<n;++i){
        if(i-k==q[head])head++;
        if(head==rear){
            q[rear]=i;
            rear++;
            //if(ans<arr[q[head]])ans=arr[q[head]];
            printf("%d ",arr[q[head]]);
            continue;
        }
        else{
            while(head!=rear){
                if(arr[i]>=arr[q[rear-1]])rear--;
                else{
                    q[rear]=i;
                    rear++;
                    break;
                }
            }
            if(head==rear){
                q[rear]=i;
                rear++;
            }
            printf("%d ",arr[q[head]]);
        }
    }
    //printf("%d",ans);
    return 0;
}
