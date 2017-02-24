#include <iostream>
#include <stdio.h>

using namespace std;

int row(int idx)
{
    return idx/5;
}

int col(int idx)
{
    return idx%5;
}

bool isnextto(int i1,int i2)
{
    if(row(i1)==row(i2)&&(col(i1)-col(i2)==1||col(i2)-col(i1)==1))return true;
    if(col(i1)==col(i2)&&(row(i1)-row(i2)==1||row(i2)-row(i1)==1))return true;
    return false;
}

bool inarr(int arr[],int siz,int elem)
{
    for(int i=0;i<siz;++i){
        if(arr[i]==elem)return true;
    }
    return false;
}

int main()
{
    int cnt=0;
    int path[7];
    char tmpchart[5][5];int chart[5][5];
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            scanf("%c",&tmpchart[i][j]);
            if(tmpchart[i][j]=='\n'){j--;continue;}
            if(tmpchart[i][j]=='J')chart[i][j]=1;
            else chart[i][j]=0;
        }
    }
    int num;
    for(path[0]=0;path[0]<=18;++path[0]){
        for(path[1]=path[0]+1;path[1]<=19;++path[1]){
            for(path[2]=path[1]+1;path[2]<=20;++path[2]){
                for(path[3]=path[2]+1;path[3]<=21;++path[3]){
                    num=chart[row(path[0])][col(path[0])]+chart[row(path[1])][col(path[1])]+chart[row(path[2])][col(path[2])]+chart[row(path[3])][col(path[3])];
                    if(!num)continue;
                    for(path[4]=path[3]+1;path[4]<=22;++path[4]){
                        num=chart[row(path[0])][col(path[0])]+chart[row(path[1])][col(path[1])]+chart[row(path[2])][col(path[2])]+chart[row(path[3])][col(path[3])]+chart[row(path[4])][col(path[4])];
                        if(num<=1)continue;
                        for(path[5]=path[4]+1;path[5]<=23;++path[5]){
                            num=chart[row(path[5])][col(path[5])]+chart[row(path[0])][col(path[0])]+chart[row(path[1])][col(path[1])]+chart[row(path[2])][col(path[2])]+chart[row(path[3])][col(path[3])]+chart[row(path[4])][col(path[4])];
                            if(num<=2)continue;
                            for(path[6]=path[5]+1;path[6]<=24;++path[6]){
                                num=chart[row(path[6])][col(path[6])]+chart[row(path[5])][col(path[5])]+chart[row(path[0])][col(path[0])]+chart[row(path[1])][col(path[1])]+chart[row(path[2])][col(path[2])]+chart[row(path[3])][col(path[3])]+chart[row(path[4])][col(path[4])];
                                if(num<=3)continue;
                                else{
                                    bool flag=true;
                                    //int con=0;
                                    //for(int i=0;i<7;++i){
                                      //  int c=0;
                                        //for(int j=0;j<7;++j){
                                          //  if(i==j)continue;
                                            //if(!isnextto(path[i],path[j]))c++;
                                            //else con++;
                                        //}
                                        //if(c==6){
                                          //  flag=false;
                                            //break;
                                        //}
                                    //}
                                    //if(flag)cnt++;
                                    int tmppath[7]={-1,-1,-1,-1,-1,-1,-1};int top=0;
                                    //for(int i=0;i<7;++i){
                                      //  if(!inarr(tmppath,7,path[i])){
                                        //    tmppath[top]=path[i];
                                          //  top++;
                                        //}
                                        //int tmp=top;
                                        //if(top==7)break;
                                        //for(int j=0;j<7;++j){
                                          //  if(j==i)continue;
                                            //if(isnextto(path[i],path[j])&&!inarr(tmppath,7,path[j])){
                                              //  tmppath[top]=path[j];top++;
                                            //}
                                        //}
                                        //if(top==tmp&&top<7&&top==i+1){
                                          //  flag=false;
                                            //break;
                                        //}
                                    //}
                                    tmppath[0]=path[0];
                                    int tmp=top+1;
                                    while(top<7){
                                        //if(!inarr(tmppath,7,path[idx])){
                                          //  tmppath[top]=path[idx];
                                        //}

                                        for(int i=0;i<7;++i){
                                            if(isnextto(tmppath[top],path[i])&&!inarr(tmppath,7,path[i])){
                                                tmppath[tmp]=path[i];tmp++;//???
                                            }
                                        }
                                        top++;
                                        if(top<7&&tmppath[top]==-1){
                                            flag=false;break;
                                        }

                                    }
                                    if(flag)cnt++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
