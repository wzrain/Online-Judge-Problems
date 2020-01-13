#include <iostream>
#include <stdio.h>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
#include <queue>
#include <memory.h>

using namespace std;

int n, mat[105][105];
int s, t;

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

MaxFlow solve;

bool init() {
    if (scanf("%d", &n) == EOF) return false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &mat[i][j]);
            if (i == j) mat[i][j] = 0;
        }
    }
    scanf("%d%d", &s, &t);
    return true;
}

void sol() {
    if (s == t) {
        printf("%s\n", "inf");
        return;
    }
    map<int, unordered_set<int>> dijk;
    unordered_map<int, vector<int>> pre;
    vector<int> dis(n, INT_MAX);
    for (int i = 0; i < n; ++i) {
        if (i == s) {
            dis[i] = 0;
        }
        else {
            dijk[INT_MAX].insert(i);
        }
    }
    int cur = s;
    while (!dijk.empty() && dis[cur] != INT_MAX) {
        for (int i = 0; i < n; ++i) {
            if (i == cur) continue;
            if (mat[cur][i] == -1) continue;
            int tmp = dis[cur] + mat[cur][i];
            if (tmp < dis[i]) {
                pre[i].clear();
                pre[i].push_back(cur);
                dijk[dis[i]].erase(i);
                if (dijk[dis[i]].empty()) dijk.erase(dis[i]);
                dis[i] = tmp;
                dijk[dis[i]].insert(i);
            }
            else if (tmp == dis[i]) {
                pre[i].push_back(cur);
            }
        }
        int mindis = dijk.begin()->first;
        cur = *(dijk[mindis].begin());
        dijk[mindis].erase(cur);
        if (dijk[mindis].empty()) dijk.erase(mindis);
    }

    for (int i = 0; i < n; ++i) {
        if (i == cur) continue;
        if (mat[cur][i] == -1) continue;
        int tmp = dis[cur] + mat[cur][i];
        if (tmp == dis[i]) {
            pre[i].push_back(cur);
        }
    }

    if (dis[t] == INT_MAX) {
        printf("%d\n", 0);
        return;
    }

    solve.init(n);
    queue<int> q;
    unordered_set<int> visited;
    visited.insert(t);
    q.push(t);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < pre[cur].size(); ++i) {
            int pr = pre[cur][i];
            if (visited.find(pr) == visited.end()) {
                q.push(pr);
                visited.insert(pr);
            }
            solve.add_edge(pr, cur, 1);
        }
    }
    int flow = solve.maxflow(s, t);
    printf("%d\n", flow);
}

void sol2() {
    if (s == t) {
        printf("%s\n", "inf");
        return;
    }
    map<int, unordered_set<int>> dijk;
    vector<int> dis(n, INT_MAX), dit(n, INT_MAX);
    for (int i = 0; i < n; ++i) {
        if (i == s) {
            dis[i] = 0;
        }
        else {
            dijk[INT_MAX].insert(i);
        }
    }
    int cur = s;
    while (!dijk.empty() && dis[cur] != INT_MAX) {
        for (int i = 0; i < n; ++i) {
            if (i == cur) continue;
            if (mat[cur][i] == -1) continue;
            int tmp = dis[cur] + mat[cur][i];
            if (tmp < dis[i]) {
                dijk[dis[i]].erase(i);
                if (dijk[dis[i]].empty()) dijk.erase(dis[i]);
                dis[i] = tmp;
                dijk[dis[i]].insert(i);
                if (tmp < 0) while(1);
            }
        }
        int mindis = dijk.begin()->first;
        cur = *(dijk[mindis].begin());
        dijk[mindis].erase(cur);
        if (dijk[mindis].empty()) dijk.erase(mindis);
    }

    dijk.clear();
    for (int i = 0; i < n; ++i) {
        if (i == t) {
            dit[i] = 0;
        }
        else {
            dijk[INT_MAX].insert(i);
        }
    }
    cur = t;
    while (!dijk.empty() && dit[cur] != INT_MAX) {
        for (int i = 0; i < n; ++i) {
            if (i == cur) continue;
            if (mat[i][cur] == -1) continue;
            int tmp = dit[cur] + mat[i][cur];
            if (tmp < dit[i]) {
                dijk[dit[i]].erase(i);
                if (dijk[dit[i]].empty()) dijk.erase(dit[i]);
                dit[i] = tmp;
                dijk[dit[i]].insert(i);
            }
        }
        int mindit = dijk.begin()->first;
        cur = *(dijk[mindit].begin());
        dijk[mindit].erase(cur);
        if (dijk[mindit].empty()) dijk.erase(mindit);
    }


    if (dis[t] == INT_MAX) {
        printf("%d\n", 0);
        return;
    }

    solve.init(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (mat[i][j] != -1 && dis[i] != INT_MAX && dit[j] != INT_MAX && dis[i] + dit[j] + mat[i][j] == dis[t]) {
                solve.add_edge(i, j, 1);
            }
        }
    }
    int flow = solve.maxflow(s, t);
    printf("%d\n", flow);
}

int main() {
    while (init()) sol();
    return 0;
}