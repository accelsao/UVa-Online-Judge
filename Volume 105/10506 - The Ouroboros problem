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


int n, m;
int s[65536];
int v[65536];
int f,ed;
void dfs(int d){
	int t;
	if (ed)return;
	if (d == f){
		queue<int>q;
		for (int i = 0; i < m-1; i++){//i=m-1時 等於0 已經檢查過
			t = 0;
			for (int j = m - 1; j >= 0; j--)
				t = t*n + s[(i - j + f) % f];
			if (v[t]){
				while (!q.empty()){
					int a = q.front(); q.pop();
					v[a] = 0;
				}
				return;
			}
			v[t] = 1;
			q.push(t);
		}
		for (int i = 0; i < f; i++)
			printf("%d", s[i]);
		puts("");
		ed = 1;
		return;
	}
	for (int i = 0; i < n; i++){
		t = 0;
		s[d] = i;
		for (int j = m - 1; j >= 0; j--)
			t = t*n + s[d - j];
		if (v[t])continue;
		v[t] = 1;
		dfs(d + 1);
		v[t] = 0;
	}
}
int main(){	
	while (cin >> m >> n){
		f = pow(n, m);
		for (int i = 0; i < f; i++)
			s[i] = v[i] = 0;
		ed = 0;
		v[0] = 1;
		dfs(m);	
	}
}
