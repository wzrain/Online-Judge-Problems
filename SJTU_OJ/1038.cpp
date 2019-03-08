#include <iostream>
#include <stdio.h>

using namespace std;

int nums[10005];

struct monkey
{
  int num;
  monkey* next;
};

void reverse_inference(int m)
{
  int l=0;
  for(int i=2;i<=m;++i)l=(l+nums[m-i+1])%i;
  printf("%d", l+1);
}

void link_simulation(int m)
{
  monkey* head=new monkey;
  monkey* rear=head;
  for(int i=1;i<m;++i){
    rear->num=i;
    rear->next=new monkey;
    rear=rear->next;
  }
  rear->num=m;
  rear->next=head;
  monkey* p=head;
  monkey* q=rear;
  for (int i=1;i<m;++i){
    int cnt=(nums[i]+m-i)%(m-i+1);
    for(int step=0;step<cnt;++step){
      q=p;
      p=p->next;
    }
    q->next=p->next;
    monkey* del=p;
    p=p->next;
    delete del;
  }
  printf("%d", p->num);
}

int main()
{
    int m;
    scanf("%d",&m);
    for(int i=1;i<m;++i)scanf("%d",&nums[i]);
    //reverse_inference(m);
    link_simulation(m);
    return 0;
}
