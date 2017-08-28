#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<vector>
#include<functional>
#include<unordered_map>
using namespace std;

#define M 100001
vector<int>g[M];
bool vis[M], is[M], it;
int in[M];
void dfs(int r){
	vis[r] = 1;
	for (int i = 0; i < g[r].size(); i++){
		int v = g[r][i];
		if (vis[v]){
			it = 0;
			return;
		}
		dfs(v);
		if (!it)return;
	}
}
int main(){
	int t = 1;
	int a, b;
	while (cin >> a >> b){
		if (a < 0 && b < 0)break;
		for (int i = 1; i < M; i++){
			g[i].clear();
			vis[i] = is[i] = in[i] = 0;
		}
		while (a&&b){
			g[a].push_back(b);
			is[a] = is[b] = 1;
			in[b]++;
			cin >> a >> b;
		}
		it = 1;
		for (int i = 1; i < M; i++)
			if (is[i] && !in[i]){
				dfs(i);
				break;
			}
		for (int i = 1;i < M; i++)
			if (is[i] && !vis[i]){
				it = 0;
				break;
			}
		printf("Case %d is ", t++);
		if (it)
			puts("a tree.");
		else
			puts("not a tree.");
	}
}

