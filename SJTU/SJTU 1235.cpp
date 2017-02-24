#include <iostream>
#include <stdio.h>
#define INF 2147483647
using namespace std;

struct edge
{
    int last;
    int value;
    edge* next;
    edge(int l=0,int v=0):last(l),value(v),next(NULL){}
};

int dis[10005],currsize,pre[10005],Rank[10005],solution[10005],cnt=0,num[10005];
edge* chart[10005];
int q[400005];

int main()
{
    for(int i=0;i<10005;++i)chart[i]=new edge(i,0);
    int n,m,start,finish;scanf("%d%d%d%d",&n,&m,&start,&finish);
    currsize=n;
    q[1]=start;
    Rank[start]=1;
    for(int i=2;i<=start;++i){
        q[i]=i-1;
        Rank[q[i]]=i;
    }
    for(int i=start+1;i<=n;++i){
        q[i]=i;
        Rank[q[i]]=i;
    }
    for(int i=1;i<=n;++i){
        if(i==start){
            dis[i]=0;
            num[i]=0;
            continue;
        }
        dis[i]=INF;
        num[i]=INF;
    }
    int a,b,p;
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&a,&b,&p);
        if(a!=b){
            bool flag=true;
            edge* ptr=chart[a];
            while(ptr->next!=NULL){
                ptr=ptr->next;
                if(ptr->last==b){
                    if(ptr->value>p)ptr->value=p;
                    flag=false;
                    break;
                }
            }
            if(flag){
                edge* q=new edge(b,p);
                ptr->next=q;
            }
        }
    }
    while(currsize!=0){
        int idx=q[1];
        if(idx==finish)break;
        int tmp=q[currsize];
        currsize--;
        q[1]=tmp;
        int j=1;
        while(j*2<=currsize){
            if(dis[tmp]>dis[q[j*2]]&&dis[tmp]>dis[q[j*2+1]]){
                if(dis[q[j*2]]>dis[q[j*2+1]]){
                    q[j]=q[j*2+1];
                    Rank[q[j*2+1]]=j;
                    j=j*2+1;
                }
                else{
                    q[j]=q[j*2];
                    Rank[q[j*2]]=j;
                    j=j*2;
                }
            }
            else if(dis[tmp]<=dis[q[j*2]]&&dis[tmp]>dis[q[j*2+1]]){
                q[j]=q[j*2+1];
                Rank[q[j*2+1]]=j;
                j=j*2+1;
            }
            else if(dis[tmp]>dis[q[j*2]]&&dis[tmp]<=dis[q[j*2+1]]){
                q[j]=q[j*2];
                Rank[q[j*2]]=j;
                j=j*2;
            }
            else break;
        }
        q[j]=tmp;
        Rank[tmp]=j;
        edge* p=chart[idx]->next;
        while(p!=NULL){
            if(dis[p->last]>dis[idx]+p->value){
                dis[p->last]=dis[idx]+p->value;
                pre[p->last]=idx;
                num[p->last]=num[idx]+1;
                int i;
                for(i=Rank[p->last];i>1;i/=2){
                    if(dis[q[i/2]]>=dis[p->last]){
                        q[i]=q[i/2];
                        Rank[q[i/2]]=i;
                    }
                    else break;
                }
                q[i]=p->last;
                Rank[p->last]=i;
            }
            else if(dis[p->last]==dis[idx]+p->value&&num[p->last]>num[idx]+1){
                num[p->last]=num[idx]+1;
                pre[p->last]=idx;
            }
            p=p->next;
        }
    }
    int idx=finish;
    while(idx!=0){
        solution[cnt++]=idx;
        idx=pre[idx];
    }
    printf("%d\n",dis[finish]);
    for(int i=cnt-1;i>=0;--i){
        printf("%d ",solution[i]);
    }
    return 0;
}
