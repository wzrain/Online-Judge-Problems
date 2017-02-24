#include <iostream>

using namespace std;

struct monkeyNode
{
    int num;
    monkeyNode *next;
};

int main()
{
    int total;cin>>total;
    monkeyNode *head,*p,*q;
    head=p=new monkeyNode;
    p->num=1;
    for(int i=2;i<=total;++i){
        q=new monkeyNode;
        q->num=i;
        p->next=q;p=q;
    }
    p->next=head;
    int *kn=new int[total-1];
    for(int i=0;i<total-1;++i){
        cin>>kn[i];
    }
    int cnt,j;
    q=head;
    for(j=0;j<total-1;++j){
        for(cnt=0;cnt<(kn[j]-1)%(total-j);++cnt){
            p=q;q=q->next;
        }
        p->next=q->next;delete q;
        q=p->next;
    }
    cout<<p->num;
    return 0;
}
