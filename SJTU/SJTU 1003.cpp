#include <iostream>
#include <stdio.h>

using namespace std;

int bact[105][105];
int tmp[105][105];
int day=0;
void breed(int);

void breed(int l)
{
    bool flag=true;
    for(int i=0;i<l;++i){
        for(int j=0;j<l;++j){
            if(bact[i][j]==0){
                flag=false;
            }
        }
    }
    for(int i=0;i<l;++i){
        for(int j=0;j<l;++j){
            tmp[i][j]=bact[i][j];
        }
    }
    for(int i=0;i<l;++i){
        for(int j=0;j<l;++j){
            if(tmp[i][j]==1){
                if(i-1>=0&&tmp[i-1][j]==0)bact[i-1][j]=1;
                if(i+1<l&&tmp[i+1][j]==0)bact[i+1][j]=1;
                if(j+1<l&&tmp[i][j+1]==0)bact[i][j+1]=1;
                if(j-1>=0&&tmp[i][j-1]==0)bact[i][j-1]=1;
            }
        }
    }
    if(flag)return;
    else{
        day++;
        breed(l);
    }
}

int main()
{
    int l;scanf("%d",&l);
    for(int i=0;i<l;++i){
        for(int j=0;j<l;++j)scanf("%d",&bact[i][j]);
    }
    breed(l);
    printf("%d",day);
    return 0;
}
