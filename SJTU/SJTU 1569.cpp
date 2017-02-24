#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;cin>>n;
    int *num=new int[n+1];
    num[0]=0;
    for(int i=1;i<=n;++i)cin>>num[i];
    int *tree=new int[n+1];
    for(int i=0;i<=n;++i)tree[i]=0;
    for(int i=1;i<=n;++i){
        tree[i]+=num[i];
        if((i+(i&-i))<=n)tree[i+(i&-i)]+=tree[i];
    }
    string s;int x,y;
    while(true){
        cin>>s>>x>>y;
        if(s=="end")break;
        if(s=="inc"){
            for(int i=x;i<=n;i+=(i&-i))tree[i]+=y;
            continue;
        }
        if(s=="dec"){
            for(int i=x;i<=n;i+=(i&-i))tree[i]-=y;
            continue;
        }
        if(s=="query"){
            int res1=0,res2=0;
            for(int j=x-1;j>0;j-=(j&-j))res1+=tree[j];
            for(int k=y;k>0;k-=(k&-k))res2+=tree[k];
            cout<<res2-res1<<endl;continue;
        }
    }
    return 0;
}
