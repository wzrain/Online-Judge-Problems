#include <iostream>
#include <stdio.h>
using namespace std;

int budget[15],rest=0,mom=0;

int main()
{
    for(int i=1;i<=12;++i){
        scanf("%d",&budget[i]);
    }
    bool flag=true;
    for(int i=1;i<=12;++i){
        int benefit=rest+300-budget[i];
        if(benefit<0){
            printf("-%d",i);
            flag=false;
            break;
        }
        rest=benefit%100;
        mom+=(benefit-rest);
        //cout<<rest<<" "<<mom<<endl;
    }
    int res=(mom+mom/5+rest);
    if(flag)printf("%d",res);
    return 0;
}
