#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 210
#define RE(a,b) memset(a,b,sizeof(a))
struct edge{
	int u, v, cap, flow, cost;
};
vector<edge>E;
vector<int>g[N];
int n, m, u, v, cost, flow, t;
int d[N], vis[N], a[N], p[N];
bool spfa(int s, int t){
	for (int i = 0; i < n * 2; i++)d[i] = 1e9;
	RE(vis, 0); RE(a, 0); RE(p, 0);
	queue<int>q;
	q.push(s); d[s] = 0; a[s] = 1e9;
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
	if (d[t] == 1e9)return 0;
	flow += a[t];
	cost += d[t] * a[t];
	for (int u = t; u != s; u = E[p[u]].u){
		E[p[u]].flow += a[t];
		E[p[u] ^ 1].flow -= a[t];
	}
	return 1;
}
int mcmf(int s,int t){
	cost = flow = 0;
	while (spfa(s, t));
	return flow;
}
void add(int u, int v, int cap, int flow, int cost){
	E.push_back(edge{ u, v, cap, 0, cost });
	E.push_back(edge{ v, u, 0, 0, -cost });
	int m = E.size();
	g[u].push_back(m - 2);
	g[v].push_back(m - 1);
}
int main(){
	while (cin >> n, n){
		t = n + 1;
		for (int i = 0; i < n * 2; i++)g[i].clear(); E.clear();
		cin >> m;
		
		while (m--){
			cin >> u >> v >> cost;
			add(u, v, 1, 0, cost);
			add(v, u, 1, 0, cost);
		}
		add(0, 1, 2, 0, 0);
		add(n, t, 2, 0, 0);
		if (mcmf(0, t) < 2)puts("Back to jail");
		else printf("%d\n", cost);
	}
}
