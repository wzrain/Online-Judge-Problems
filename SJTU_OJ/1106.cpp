#include <iostream>
#include <stdio.h>

using namespace std;

int sudoku[10][10];
int cnt=0;
int row[10][10], column[10][10], square[10][10];

void dfs(int i, int j)
{
  if(cnt>1)return;
  if(sudoku[i][j]!=0){
    if(i==9&&j==9)cnt++;
    else dfs(i+j/9, j%9+1);
  }
  else{
    for(int num=1;num<=9;++num){
      if(row[i][num]||column[j][num]||square[(i-1)/3*3+(j-1)/3+1][num])
        continue;
      row[i][num]=1;
      column[j][num]=1;
      square[(i-1)/3*3+(j-1)/3+1][num]=1;
      sudoku[i][j]=num;
      if(i==9&&j==9)cnt++;
      else dfs(i+j/9, j%9+1);
      row[i][num]=0;
      column[j][num]=0;
      square[(i-1)/3*3+(j-1)/3+1][num]=0;
      sudoku[i][j]=0;
    }
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  for(int t=0;t<T;++t){
    for(int i=1;i<=9;++i){
      for(int j=1;j<=9;++j){
        row[i][j]=0;
        column[i][j]=0;
        square[i][j]=0;
      }
    }
    cnt=0;
    bool flag=true;
    for(int i=1;i<=9;++i){
      for(int j=1;j<=9;++j){
        scanf("%d",&sudoku[i][j]);
        if(sudoku[i][j]!=0){
          if(row[i][sudoku[i][j]]||
             column[j][sudoku[i][j]]||
             square[(i-1)/3*3+(j-1)/3+1][sudoku[i][j]]){
            flag=false;
          }
          row[i][sudoku[i][j]]=1;
          column[j][sudoku[i][j]]=1;
          square[(i-1)/3*3+(j-1)/3+1][sudoku[i][j]]=1;
        }
      }
    }
    if(!flag){
      printf("%s\n","No");
      continue;
    }
    dfs(1,1);
    if(cnt==1)printf("%s\n","Yes");
    else printf("%s\n","No");
  }
}
