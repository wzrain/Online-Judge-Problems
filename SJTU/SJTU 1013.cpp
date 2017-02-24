    	#include <iostream>
        #include <stdio.h>
        using namespace std;
         
        int vol[30005];
        int val[1005];
        int f[30005];
        //thing tarr[1005];
         
        int Max(int a,int b)
        {
            int res;
            res=(a>b)?a:b;
            return res;
        }
         
        int Min(int a,int b)
        {
            if(a<b)return a;
            return b;
        }
         
        int main()
        {
            int v,n;scanf("%d%d",&v,&n);
            for(int i=0;i<n;++i){
                scanf("%d",&vol[i]);
                scanf("%d",&val[i]);
            }
            for(int i=0;i<n;++i){
                for(int j=vol[i];j<=v;++j){
                    f[j]=Max(f[j],f[j-vol[i]]+val[i]);
                }
            }
            printf("%d",f[v]);
            return 0;
        }