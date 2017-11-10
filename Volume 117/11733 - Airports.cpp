#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#define accel ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define LL long long
#define N 100001
using namespace std;


struct edge {
	int u, v, w;
}e[N];
int n, m, p[N], cost;
bool cmp(edge a, edge b) {
	return a.w < b.w;
}
int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}
void kruskal() {
	sort(e, e + m, cmp);
	int s = 0;
	for (int i = 0; i < m; i++) {
		if (e[i].w >= cost)break;
		int x = find(e[i].u), y = find(e[i].v);
		if (x == y)continue;
		p[x] = y;
		s += e[i].w;
	}
	int c = 0;
	for (int i = 1; i <= n; i++)
		if (p[i] == i)
			c++;
	printf("%d %d\n", s + c*cost, c);
}

int main() {
	accel;
	int t, x, y, c;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		cin >> n >> m >> cost;
		for (int i = 1; i <= n; i++)
			p[i] = i;
		for (int i = 0; i < m; i++) {
			cin >> x >> y >> c;
			e[i]=edge{ x,y,c };
		}
		printf("Case #%d: ", k);
		kruskal();
	}	
}
