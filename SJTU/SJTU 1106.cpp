#include <iostream>
#include <stdio.h>

using namespace std;

int num[10][10];
int cnt=0;
bool num_in_row[10][10],num_in_col[10][10],num_in_square[10][10];

void isSudoku(int);
bool suitable(int,int);

bool suitable(int nu,int idx)
{
    int row=(idx-1)/9+1,col=(idx-1)%9+1;
    return num_in_col[nu][col]&&num_in_row[nu][row]&&num_in_square[nu][(row-1)/3*3+(col-1)/3+1];
}

void isSudoku(int idx)
{
    if(cnt>1)return;
    int row=(idx-1)/9+1,col=(idx-1)%9+1;
    if(!num[row][col]){
        for(int nu=1;nu<=9;++nu){
            if(suitable(nu,idx)){
                num[row][col]=nu;
                num_in_col[nu][col]=num_in_row[nu][row]=num_in_square[nu][(row-1)/3*3+(col-1)/3+1]=false;
                if(idx==81){
                    cnt++;
                }
                else isSudoku(idx+1);
                num[row][col]=0;
                num_in_col[nu][col]=num_in_row[nu][row]=num_in_square[nu][(row-1)/3*3+(col-1)/3+1]=true;
            }
        }
    }
    else{
        if(idx==81)cnt++;
        else isSudoku(idx+1);
    }
}

int main()
{
    int t;scanf("%d",&t);
    for(int idx=0;idx<t;++idx){
        bool flag=true;
        for(int sth=0;sth<=9;++sth){
            for(int ths=0;ths<=9;++ths){
                num_in_col[sth][ths]=num_in_row[sth][ths]=num_in_square[sth][ths]=true;
            }
        }
        for(int r=1;r<=9;++r){
            for(int c=1;c<=9;++c){
                scanf("%d",&num[r][c]);
                if(num[r][c]&&(!(num_in_row[num[r][c]][r]&&num_in_col[num[r][c]][c]&&num_in_square[num[r][c]][(r-1)/3*3+(c-1)/3+1])))flag=false;
                if(num[r][c]){
                    num_in_row[num[r][c]][r]=num_in_col[num[r][c]][c]=num_in_square[num[r][c]][(r-1)/3*3+(c-1)/3+1]=false;
                }
            }
        }
        if(!flag){printf("%s\n","No");continue;}
        isSudoku(1);
        if(cnt==1)printf("%s\n","Yes");
        else printf("%s\n","No");
        cnt=0;
    }
    return 0;
}
