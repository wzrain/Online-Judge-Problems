#include <iostream>
#include <string>

using namespace std;

struct bigIntNode
{
    int byte;
    bigIntNode *next;
};

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int len1=s1.length(),len2=s2.length();
    bigIntNode *head1,*head2,*p,*rear1,*rear2;
    head1=rear1=new bigIntNode;
    for(int i=0;i<len1;++i){
        p=new bigIntNode;
        p->byte=s1[len1-1-i]-'0';
        rear1->next=p;rear1=p;
    }
    head2=rear2=new bigIntNode;
    for(int j=0;j<len2;++j){
        p=new bigIntNode;
        p->byte=s2[len2-1-j]-'0';
        rear2->next=p;rear2=p;
    }
    bigIntNode *head,*rear,*q1,*q2,*q;
    head=rear=new bigIntNode;
    q1=head1->next;q2=head2->next;
    int addnum=0;
    while(q1!=NULL&&q2!=NULL){
        int x=0;
        x=q1->byte+q2->byte+addnum;
        addnum=x/10;
        q=new bigIntNode;
        q->byte=x%10;
        rear->next=q;
        rear=q;
        q1=q1->next;q2=q2->next;
    }
    if(q1==NULL)q1=q2;
    while(q1!=NULL){
        q=new bigIntNode;
        int x=0;
        x=q1->byte+addnum;
        addnum=x/10;
        q->byte=x%10;
        rear->next=q;
        rear=q;
        q1=q1->next;
    }
    if(addnum!=0){
        q=new bigIntNode;
        q->byte=1;
        rear->next=q;
        rear=q;
    }
    string s;
    bigIntNode *r;
    r=head->next;
    while(r!=NULL){
        s=char(r->byte+'0')+s;
        r=r->next;
    }
    for(int l=0;l<s.length();++l)cout<<s[l];
    return 0;
}
