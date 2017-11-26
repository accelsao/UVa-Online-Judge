#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define RE(a,b) memset(a, b, sizeof(a));
#define N 50001
struct edge{ int u, v, w; bool operator<(const edge a)const{ return w < a.w; } };
struct road{ int to, w; };
vector<edge>E;
vector<road>g[N];
int n, m;
int p[N], pre[N], son[N], sz[N], dep[N], W[N], top[N], pos, id[N], chain[N], mx[N<<2];
//p unionset pre父親點 son 最重兒子 sz u點的子樹節點 dep 深度 W u點到父親點的邊長 top u點所屬重鍊的頂端  pos 邊在樹中的位置 id v點和父親u點的邊的pos chain id的u點 
int find(int x){ return x == p[x] ? x : p[x] = find(p[x]); }
void dfs(int u, int p, int d){
	pre[u] = p;
	sz[u] = 1;
	dep[u] = d;
	for (auto i : g[u]){
		if (i.to == p)continue;
		W[i.to] = i.w;
		dfs(i.to, u, d + 1);
		sz[u] += sz[i.to];
		if (son[u] == -1 || sz[i.to]>sz[son[u]])
			son[u] = i.to;
	}
}
void getpos(int u, int sp){
	top[u] = sp;
	id[u] = pos;
	chain[pos++] = u;
	if (son[u] == -1)return;
	getpos(son[u], sp);
	for (auto i : g[u]){
		int v = i.to;
		if (v == pre[u] || v == son[u])continue;
		getpos(v, v);
	}
}
void build(int rt, int l, int r){
	if (l == r){
		mx[rt] = W[chain[l]]; return;
	}
	int m = l + r >> 1;
	build(rt << 1, l,m);
	build(rt << 1 | 1, m + 1, r);
	mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
}
int find(int rt, int l, int r, int L, int R){
	if (l >= L&&r <= R)
		return mx[rt];
	int m = l + r >> 1, ans = 0;
	if (m >= L)
		ans=max(ans,find(rt << 1, l, m, L, R));
	if (m < R)
		ans = max(ans, find(rt << 1 | 1, m + 1, r, L, R));
	return ans;
}
int solve(int s, int t){
	int a = top[s], b = top[t], ans = 0;
	while (a != b){
		if (dep[a] < dep[b])swap(a, b), swap(s, t);
		ans = max(ans, find(1, 1, n, id[a], id[s]));
		s = pre[a]; a = top[s];
	}
	if (s == t)//同重鍊
		return ans;
	if (dep[s] > dep[t])swap(s, t);
	ans = max(ans, find(1, 1, n, id[son[s]], id[t]));
	return ans;
}
int main(){
	int T = 0;
	while (cin >> n >> m){
		pos = 0;
		E.clear();
		int u, v, d, q, s, t;
		while (m--){
			cin >> u >> v >> d;
			E.push_back(edge{ u, v, d });
		}
		sort(E.begin(), E.end());
		for (int i = 0; i <= n; i++)p[i] = i, g[i].clear(), son[i] = -1;
		int tot = 0;
		for (auto i : E){
			int x = find(i.u), y = find(i.v);
			if (x == y)continue;
			p[x] = y;
			tot++;
			g[i.u].push_back(road{ i.v, i.w });
			g[i.v].push_back(road{ i.u, i.w });
			if (tot == n - 1)break;
		}
		dfs(1, -1, 0);
		getpos(1, 1);
		W[1] = -1e9;
		build(1, 1, n);
		cin >> q;
		if (T++)puts("");
		while (q--){
			cin >> s >> t;
			printf("%d\n", solve(s, t));
		}
	}
}
