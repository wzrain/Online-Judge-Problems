#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    char script[101][2001];
    int line=0;
    while(true){
        cin.getline(script[line],2001,'\n');
        if(!strcmp(script[line],"******"))break;
        line++;
    }
    string s;
    while(true){
        cin>>s;
        if(s=="quit")break;
        if(s=="list"){
            int n1,n2;cin>>n1>>n2;
            if(n1<=n2&&n2<=line&&n1>0){
                for(int i=n1;i<=n2;++i){
                    cout<<script[i-1]<<endl;
                }
            }
            else cout<<"Error!"<<endl;
            continue;
        }
        if(s=="ins"){
            int i,j;char str[102];
            cin>>i>>j;cin.getline(str,102,'\n');
            if(i>line||i<=0||j<=0){cout<<"Error!"<<endl;continue;}
            int len=0;
            while(script[i-1][len]!='\0')len++;
            if(j>len+1){cout<<"Error!"<<endl;continue;}
            if(strlen(script[i-1])+strlen(str)-1>2000){cout<<"Error!"<<endl;continue;}
            for(int idx=strlen(script[i-1]);idx>=j-1;--idx)script[i-1][idx+strlen(str)-1]=script[i-1][idx];
            for(int idx1=0;idx1<strlen(str)-1;++idx1)script[i-1][j-1+idx1]=str[idx1+1];
            continue;
        }
        if(s=="del"){
            int i,j,num;
            cin>>i>>j>>num;
            if(i<=0||j<=0||i>line){cout<<"Error!"<<endl;continue;}
            int len=0;
            while(script[i-1][len]!='\0')len++;
            if(j>len||j+num>len+1){cout<<"Error!"<<endl;continue;}
            for(int idx=j-1;idx<=len-num;++idx)script[i-1][idx]=script[i-1][idx+num];
            continue;
        }
        cout<<"Error!"<<endl;
    }
    for(int index=0;index<line;++index){
        cout<<script[index]<<endl;
    }
    return 0;
}
