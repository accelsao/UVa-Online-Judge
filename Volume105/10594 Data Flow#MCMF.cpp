#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 210
#define RE(a,b) memset(a,b,sizeof(a))
#define LL long long
struct edge{
	int  u, v;
	LL cap,flow,cost;
};
struct link{
	int u, v;
	LL cost;
};
vector<link>L;
vector<edge>E;
vector<int>g[N];
int n, m, u, v;
LL vis[N], a[N], p[N], flow, cost, D, K, d[N];
bool spfa(int s, int t){
	for (int i = 0; i <= n; i++)d[i] = 1e18;
	RE(vis, 0); RE(a, 0); RE(p, 0);
	queue<int>q;
	q.push(s); d[s] = 0; a[s] = 1e18 ;
	while (!q.empty()){
		int u = q.front(); q.pop(); vis[u] = 0;
		for (int v : g[u]){
			edge &e = E[v];
			if (e.cap > e.flow&&d[e.v] > d[u] + e.cost){
				d[e.v] = d[u] + e.cost;
				a[e.v] = min(a[u],e.cap - e.flow);
				p[e.v] = v;
				if (!vis[e.v])
					q.push(e.v), vis[e.v] = 1;
			}
		}
	}
	if (d[t] == 1e18)return 0;
	flow += a[t];
	cost +=d[t] *a[t];
	for (int u = t; u != s; u = E[p[u]].u){
		E[p[u]].flow += a[t];
		E[p[u] ^ 1].flow -= a[t];
	}
	return 1;
}
LL mcmf(int s,int t){
	cost = flow = 0;
	while (spfa(s, t));
	return flow;
}
void add(int u, int v, LL cap, LL cost){
	E.push_back(edge{ u, v, cap, 0, cost });
	E.push_back(edge{ v, u, 0, 0, -cost });
	int m = E.size();
	g[u].push_back(m - 2);
	g[v].push_back(m - 1);
}
int main(){
	while (cin >> n >> m){
		for (int i = 0; i < N; i++)g[i].clear(); E.clear(), L.clear();
		for (int i = 0; i < m; i++){
			cin >> u >> v >> cost;
			L.push_back(link{ u, v, cost });
		}
		cin >> D >> K;
		while(m--){
			add(L[m].u, L[m].v, K, L[m].cost);
			add(L[m].v, L[m].u, K, L[m].cost);
		}
		add(0, 1, D, 0);
		if (mcmf(0, n) < D)puts("Impossible.");
		else printf("%lld\n", cost);
	}
}
