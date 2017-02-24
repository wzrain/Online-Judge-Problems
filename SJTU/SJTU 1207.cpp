#include <iostream>
#include <stdio.h>
using namespace std;

int carqueue[20005];
int lorryqueue[20005];
//int shipqueue[11];
int chead=0,crear=0;
int lhead=0,lrear=0;
//int head=0,rear=0;
int cartime=0,lorrytime=0;

int main()
{
    int n;scanf("%d",&n);
    int data[2];
    int shipnum=0;
    int carcnt=0,lorrycnt=0;
    int time=0;
    for(int i=0;i<n;++i){
        scanf("%d%d",&data[0],&data[1]);
        if(data[0]){lorryqueue[lrear]=data[1];lrear++;lorrycnt++;}
        else{carqueue[crear]=data[1];crear++;carcnt++;}
    }
    while(true){
        if(chead==crear&&lhead==lrear)break;
        int caron=0,lorryon=0;
        for(int i=0;i<8;++i){
            if(chead==crear)break;
            if(carqueue[chead]<=time){
                caron++;
                cartime+=(shipnum*10-carqueue[chead]);
                chead++;
            }
            else break;
        }
        int emp=10-caron;
        for(int i=0;i<emp;++i){
            if(lhead==lrear)break;
            if(lorryqueue[lhead]<=time){
                lorryon++;
                lorrytime+=(shipnum*10-lorryqueue[lhead]);
                lhead++;
            }
            else break;
        }
        int emp2=10-caron-lorryon;
        if(emp2){
            for(int i=0;i<emp2;++emp){
                if(chead==crear)break;
                if(carqueue[chead]<=time){
                    cartime+=(shipnum*10-carqueue[chead]);
                    chead++;
                }
                else break;
            }
        }
        time+=10;
        shipnum++;
    }
    double carave=cartime*1.0/carcnt;
    double lorryave=lorrytime*1.0/lorrycnt;
    printf("%.3f %.3f",carave,lorryave);
    return 0;
}
