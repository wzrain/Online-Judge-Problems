#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
  if (n==2)return true;
  bool flag=true;
  for(int i=2;i<sqrt(n);++i){
    if(n%i==0){
      flag=false;
      break;
    }
  }
  return flag;
}

int main()
{
  int n, gap=0;
  scanf("%d", &n);
  int p=n;
  while(!isPrime(p)){
    p--;
    gap++;
  }
  p=n;
  while(!isPrime(p)){
    p++;
    gap++;
  }
  printf("%d",gap);
  return 0;
}
