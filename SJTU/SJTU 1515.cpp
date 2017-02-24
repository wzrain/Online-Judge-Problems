#include <iostream>
#include <stdio.h>

using namespace std;

struct node
{
    int x;
    int y;
    int step;
    node(int x1=0,int y1=0,int stp=0):x(x1),y(y1),step(stp){}
};

int udf[1002][1002];
int steparr[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
node mapqueue[1000002];
node storequeue[1000002];
int visit4[1002][1002]={0};
int visit3[1002][1002]={0};
int storetohome[1002][1002]={0};

int main()
{
    int m,n;scanf("%d%d",&m,&n);
    int maphead=0,maprear=0;
    int head=0,rear=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&udf[i][j]);
            if(udf[i][j]==2){
                node start(i,j,0);
                mapqueue[maphead]=start;
                visit3[i][j]=1;
                maprear++;
            }
            if(udf[i][j]==3){
                node last(i,j,0);
                storequeue[head]=last;
                visit4[i][j]=1;
                rear++;
            }
        }
    }
    while(head!=rear){
        node tmpnode=storequeue[head];
        head++;
        if(udf[tmpnode.x][tmpnode.y]==4){
            if(storetohome[tmpnode.x][tmpnode.y]==0)storetohome[tmpnode.x][tmpnode.y]=tmpnode.step;
            //cout<<tmpnode.step<<endl;
        }
        for(int k=0;k<4;++k){
            int x=tmpnode.x+steparr[k][0];
            int y=tmpnode.y+steparr[k][1];
            if(x>=0&&y>=0&&x<n&&y<m&&visit4[x][y]==0&&udf[x][y]!=1){
                visit4[x][y]=1;
                node next(x,y,tmpnode.step+1);
                storequeue[rear]=next;
                //cout<<x<<" "<<y<<" "<<next.step<<endl;
                rear++;
            }
        }
    }
    int totalstep=100000000,tmpstp;
    while(maphead!=maprear){
        node tmpnode=mapqueue[maphead];
        maphead++;
        if(udf[tmpnode.x][tmpnode.y]==4){
            //cout<<tmpnode.step<<endl;
            tmpstp=tmpnode.step+storetohome[tmpnode.x][tmpnode.y];
            totalstep=(totalstep>tmpstp)?tmpstp:totalstep;
            //cout<<totalstep<<endl;
        }
        visit3[tmpnode.x][tmpnode.y]=1;
        for(int i=0;i<4;++i){
            int x=tmpnode.x+steparr[i][0];
            int y=tmpnode.y+steparr[i][1];
            if(x>=0&&y>=0&&x<n&&y<m&&visit3[x][y]==0&&udf[x][y]!=1){
                visit3[x][y]=1;
                node next(x,y,tmpnode.step+1);
                mapqueue[maprear]=next;
                //cout<<x<<" "<<y<<" "<<next.step<<endl;
                maprear++;
            }
        }
    }
    printf("%d",totalstep);
    return 0;
}
