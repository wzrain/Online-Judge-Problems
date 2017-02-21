#include <iostream>

using namespace std;

int main()
{
    int n;cin>>n;
    int *time=new int[n];
    for(int i=0;i<n;++i)cin>>time[i];
    long long waiting_time_before,waiting_time_after;
    int ending_moment_before,ending_moment_after;
    long long wtb1=0,wtb2=0,wtb3=0,wta1=0,wta2=0,wta3=0;
    int emb1=0,emb2=0,emb3=0,ema1=0,ema2=0,ema3=0;
    int num,num1,num2,num3;
    num=n/3;
    switch(n%3)
    {
        case 0:num1=num2=num3=num;break;
        case 1:num2=num3=num;num1=num+1;break;
        default:num1=num2=num+1;num3=num;break;
    }
    for(int j=0;j<n;j=j+3){
        emb1+=time[j];
        wtb1+=(time[j]*(num1-j/3-1));
    }
    for(int k=1;k<n;k+=3){
        emb2+=time[k];
        wtb2+=(time[k]*(num2-k/3-1));
    }
    for(int l=2;l<n;l+=3){
        emb3+=time[l];
        wtb3+=(time[l]*(num3-l/3-1));
    }
    waiting_time_before=wtb1+wtb2+wtb3;
    int maxemb,maxema;
    maxemb=emb1>emb2?emb1:emb2;
    ending_moment_before=maxemb>emb3?maxemb:emb3;
    cout<<waiting_time_before<<" "<<ending_moment_before<<endl;
    ema1=time[0];ema2=time[1];ema3=time[2];
    for(int h=3;h<n;++h){
        if(ema1<=ema2&&ema1<=ema3){wta1+=ema1;ema1+=time[h];continue;}
        if(ema2<ema1&&ema2<=ema3){wta2+=ema2;ema2+=time[h];continue;}
        if(ema3<ema1&&ema3<ema2){wta3+=ema3;ema3+=time[h];continue;}
    }
    waiting_time_after=wta1+wta2+wta3;
    maxema=ema1>ema2?ema1:ema2;
    ending_moment_after=maxema>ema3?maxema:ema3;
    cout<<waiting_time_after<<" "<<ending_moment_after<<endl;
    return 0;
}
