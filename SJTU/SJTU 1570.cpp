#include <iostream>
#include <stdio.h>

using namespace std;

/*int bincnt(int hand[],int,int,int);

int bincnt(int hand[],int like,int low,int high)
{
    if(high-low<=1){
        if(like<hand[low])return low-1;
        if(like>=hand[low]&&like<hand[high])return low;
        if(like>=hand[high])return high;
    }
    int mid=(low+high)/2;
    if(like<hand[mid+1])bincnt(hand,like,low,mid);
    else bincnt(hand,like,mid+1,high);
}

int main()
{
    int n,t;scanf("%d%d",&n,&t);
    int *hand=new int[n];
    int *like=new int[t];
    for(int i=0;i<n;++i)scanf("%d",&hand[i]);
    for(int j=0;j<t;++j)scanf("%d",&like[j]);
    for(int k=0;k<t;++k)printf("%d\n",n-1-bincnt(hand,like[k],0,n-1));
    return 0;
}*/

int hand[100005],like[100005],n,t;

int bisearch(int goal,int low,int high)
{
    if(high-low<=1){
        if(goal<hand[low])return low-1;
        else if(goal>=hand[low]&&goal<hand[high])return low;
        else return high;
    }
    int mid=(low+high)/2;
    //if(goal==hand[mid])return mid-1;
    if(goal<hand[mid])return bisearch(goal,low,mid-1);
    else return bisearch(goal,mid+1,high);
}

int main(){
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;++i)scanf("%d",&hand[i]);
    for(int j=0;j<t;++j)scanf("%d",&like[j]);
    for(int k=0;k<t;++k)printf("%d\n",n-1-bisearch(like[k],0,n-1));
    return 0;
}
