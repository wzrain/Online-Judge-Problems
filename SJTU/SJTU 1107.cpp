#include <iostream>

using namespace std;

int main()
{
    int n;cin>>n;
    int *game=new int[n];
    for(int i=0;i<n;++i)cin>>game[i];
    for(int j=0;j<n;++j){
        if(game[j]==0)cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}
