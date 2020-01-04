#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
#define size_num 100200
#define INF 1e8

using namespace std;

int m, n;
int pg[1005];
int ba[105], bb[105], bk[105][1005];

const int maxn = 100055;
const int maxm = 600005;
const int inf = 0x3f3f3f3f;
struct MaxFlow
{
	int net[maxn], gap[maxn], dis[maxn], pre[maxn], cur[maxn];
	int siz, n;
	std::queue <int> Q;
	struct EDGE
	{
		int v, cap, next;
		EDGE(){}
		EDGE(int a, int b, int c): v(a), cap(b), next(c){}
	}E[maxm<<1];
	void init(int _n)//要传入节点数
	{
		n = _n, siz = 0;
		memset(net, -1, sizeof(net));
	}
	void add_edge(int u, int v, int cap)//加边操作
	{
		E[siz] = EDGE(v, cap, net[u]);
		net[u] = siz++;
		E[siz] = EDGE(u, 0, net[v]);
		net[v] = siz++;
	}
	void bfs(int st)//广搜
	{
		int u, v;
		for(int i = 0; i <= n; i++)
			dis[i] = n, gap[i] = 0;
		gap[0] = 1, dis[st] = 0;
		Q.push(st);
		while(!Q.empty())
		{
			u = Q.front();
			Q.pop();
			for(int i = net[u]; i != -1; i = E[i].next)
			{
				v = E[i].v;
				if(!E[i^1].cap || dis[v] < n)
					continue;
				dis[v] = dis[u] + 1;
				gap[dis[v]]++;
				Q.push(v);
			}
		}
	}
	int maxflow(int st, int en)//st 是源点 en 是汇点
	{
		int u = pre[st] = st, ma = 0, aug = inf, v;
		bfs(en);
		for(int i = 0; i <= n; i++)
			cur[i] = net[i];
		while(dis[st] <= n)
		{
loop:		for(int &i = cur[u]; v = E[i].v, i != -1; i = E[i].next)
				if(E[i].cap && dis[u] == dis[v] + 1)
				{
					aug = std::min(aug, E[i].cap);
					pre[v] = u, u = v;
					if(v == en)
					{
						ma += aug;
						for(u = pre[u]; v != st; v = u, u = pre[u])
						{
							E[cur[u]].cap -= aug;
							E[cur[u]^1].cap += aug;
						}
						aug = inf;
					}
					goto loop;
				}
			int mi = n;
			for(int i = net[u]; v = E[i].v, i != -1; i = E[i].next)
				if(E[i].cap && mi > dis[v])
				{
					cur[u] = i;
					mi = dis[v];
				}
			if(--gap[dis[u]] == 0)
				break;
			gap[dis[u]=mi+1]++;
			u = pre[u];
		}
		return ma;
	}
};

// struct Dinic {
// 	struct Edge{int from,to,cap,flow;};
// 	vector<Edge> edges;
// 	//边表。edges[e]和edges[e+1]互为反向弧,
// 	//注意到e必须是偶数即是大的奇数与比他小的偶数互为反向边，即e与e^1互为反向边
// 	vector<int> G[size_num];
// 	//领接表，G[i][j]表示节点i的第j条边在e数组中的序号
// 	void add_edge(int from,int to,int cap)
// 	{
// 		edges.push_back((Edge){from,to,cap,0});//加入正向边
// 		edges.push_back((Edge){to,from,0,0});//加入反向边
// 		int m=edges.size();
// 		G[from].push_back(m-2);//存的是边的位子
// 		G[to].push_back(m-1);//貌似有一种静态链表的感觉
// 	}
// 	int s,t;//源点编号和汇点编号
// 	bool vis[size_num];//bfs时使用
// 	int d[size_num];//从起点到i的距离
// 	int cur[size_num];//当前弧的下标
// 	void init() {
// 		edges.clear();
// 		for(int i=0;i<size_num;i++)
// 		G[i].clear();
// 	}
// 	bool bfs() {
// 		memset(vis,0,sizeof(vis));
// 		queue<int > q;
// 		q.push(s);
// 		d[s]=0;
// 		vis[s]=1;
// 		while(!q.empty())
// 		{
// 			int x=q.front();q.pop();
// 			for(int i=0;i<G[x].size();i++)
// 			{
// 				Edge&e=edges[G[x][i]];
// 				if(!vis[e.to]&&e.cap>e.flow)
// 				{
// 					vis[e.to]=1;
// 					d[e.to]=d[x]+1;
// 					q.push(e.to);
// 				}
 
// 			}
// 		}
// 		return vis[t];
// 	}
 
// 	//dfs
// 	int dfs(int x,int a) {
// 		if (x==t||a==0) return a;
// 			int flow=0,f;
// 		for(int &i=cur[x];i<G[x].size();i++)//从上次考虑的弧
// 		{
// 			Edge &e=edges[G[x][i]];
// 			if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0)
// 			{
// 				e.flow+=f;//增加正向的流量
// 				edges[G[x][i]^1].flow-=f;//减少反向的流量
// 				flow+=f;
// 				a-=f;
// 				if(a==0) break;
// 			}
// 		}
 
// 		return flow;
// 	}
// 	//
// 	int maxflow(int s,int t) {
// 		this->s=s;this->t=t;
// 		int flow=0;
// 		while(bfs()) {
// 			memset(cur,0,sizeof(cur));
// 			flow+=dfs(s,INF);
// 		}
// 		return flow;
// 	}
// }solve;

MaxFlow solve;

void init() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &pg[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ba[i]);
        for (int j = 0; j < ba[i]; ++j) {
            scanf("%d", &bk[i][j]);
        }
        scanf("%d", &bb[i]);
    }
}

void sol() {
    vector<int> last(m, -1);
	solve.init(n + 2);
	int src = n, tgt = n + 1;
	for (int i = 0; i < n; ++i) {
		int nw = 0;
		for (int j = 0; j < ba[i]; ++j) {
			if (last[bk[i][j] - 1] == -1) {
				nw += pg[bk[i][j] - 1];
			}
			else {
				solve.add_edge(last[bk[i][j] - 1], i, inf);
			}
			last[bk[i][j] - 1] = i;
		}
		if (nw) {
			solve.add_edge(src, i, nw);
		}
		solve.add_edge(i, tgt, bb[i]);
	}
	int flow = solve.maxflow(src, tgt);
	printf("%d\n", flow);
}

int main() {
	init();
	sol();
	return 0;
}
