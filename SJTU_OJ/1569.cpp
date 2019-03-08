#include <iostream>
#include <stdio.h>

using namespace std;

struct SegTreeNode
{
  int val;
  int mark;
  int length;
};

SegTreeNode tree[20005];
int arr[10005];

void build(int root, int l, int r)
{
  if(l>=r){
    tree[root].val=arr[l];
    tree[root].mark=0;
    tree[root].length=1;
    return;
  }
  int mid=(l+r)/2;
  build(root*2+1, l,mid);
  build(root*2+2, mid+1,r);
  tree[root].val=tree[root*2+1].val+tree[root*2+2].val;
  tree[root].mark=0;
  tree[root].length=r-l+1;
}

void pushDown(int root)
{
  tree[root*2+1].mark+=tree[root].mark;
  tree[root*2+2].mark+=tree[root].mark;
  tree[root*2+1].val+=(tree[root*2+1].length*tree[root].mark);
  tree[root*2+2].val+=(tree[root*2+2].length*tree[root].mark);
  tree[root].mark=0;
}

int query(int root, int qs, int qe, int l, int r)
{
  if(qs==l&&qe==r)return tree[root].val;
  int mid=(l+r)/2;
  if(tree[root].mark)pushDown(root);
  if(mid<qs)return query(root*2+2,qs,qe,mid+1,r);
  else if(qs<=mid&&mid<qe){
    return query(root*2+1,qs,mid,l,mid)+query(root*2+2,mid+1,qe,mid+1,r);
  }
  else if(mid>=qe)return query(root*2+1,qs,qe,l,mid);
}

void update(int root, int us, int ue, int l, int r, int delta)
{
  if(us==l&&ue==r){
    tree[root].val+=(tree[root].length*delta);
    tree[root].mark+=delta;
    return;
  }
  if(tree[root].mark)pushDown(root);
  int mid=(l+r)/2;
  if(mid<us)
    update(root*2+2,us,ue,mid+1,r,delta);
  else if(us<=mid&&mid<ue){
    update(root*2+1,us,mid,l,mid,delta);
    update(root*2+2,mid+1,ue,mid+1,r,delta);
  }
  else if(ue<=mid)
    update(root*2+1,us,ue,l,mid,delta);
  //if(us<=mid)update(root*2+1,us,ue,l,mid,delta);
  //if(ue>mid)update(root*2+2,us,ue,mid+1,r,delta);
  tree[root].val=(tree[root*2+1].val+tree[root*2+2].val);
}

int main()
{
  int N;
  scanf("%d", &N);
  for(int i=0;i<N;++i)scanf("%d", &arr[i]);
  build(0,0,N-1);
  while(1){
    char instr[10];
    int x,y;
    scanf("%s", instr);
    if(instr[0]=='e'){
      break;
    }
    scanf("%d%d",&x,&y);
    if(instr[0]=='i'){
      update(0,x-1,x-1,0,N-1,y);
    }
    else if(instr[0]=='d'){
      update(0,x-1,x-1,0,N-1,-y);
    }
    else if(instr[0]=='q'){
      printf("%d\n", query(0,x-1,y-1,0,N-1));
    }
  }
  return 0;
}
