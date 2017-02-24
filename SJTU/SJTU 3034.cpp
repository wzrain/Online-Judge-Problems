#include <iostream>
#include <cmath>

using namespace std;

bool prime(int);

bool prime(int n)
{
    if(n<=1)return false;
    if(n==2)return true;
    if(n%2==0)return false;
    for(int i=3;i<=sqrt(n)+1;i=i+2)
        if(n%i==0)return false;
    return true;
}
int main()
{
    int n,i,gap=0;
    cin>>n;
    if(prime(n))cout<<0;
    else{
        i=n;
        while(!prime(i)){i--;gap++;}
        while(!prime(n)){n++;gap++;}
        cout<<gap;
    }
    return 0;
}
