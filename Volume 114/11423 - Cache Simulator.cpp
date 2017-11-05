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
#include<fstream>
#include<stack>
#include<ctime>
#include<vector>
using namespace std;

int n, now, x;
const int M = (1 << 24) + 5;
int ch[35], bit[M], vis[M], ans[35];
void add(int x, int v){ 
	while (x < M){
		bit[x] += v;
		x += x&(-x);//lowbit
	}
}
int get(int x){
	int ans = 0;
	while (x){
		ans += bit[x];
		x -= x&(-x);//lowbit
	}
	return ans;
}
int get(int l, int r){
	return get(r) - get(l - 1);
}
string s;
void find(int x){
	if (vis[x]){
		int len = get(now) - get(vis[x] - 1);
		for (int i = 0; i < n; i++){
			if (ch[i] >= len)break;
			ans[i]++;
		}
		add(vis[x], -1);
	}
	else
		for (int i = 0; i < n; i++)
			ans[i]++;
	add(vis[x] = ++now, 1);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	while (cin >> n){
		now = 0;
		memset(bit, 0, sizeof(bit));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++)//兩個cache 視為同步操作 分開來看
			cin >> ch[i];
		while (cin >> s, s[0] != 'E'){
			if (s[0] == 'S'){
				for (int i = 0; i < n; i++)
					printf("%d%c", ans[i], i == n - 1 ? '\n': ' ');
				memset(ans, 0, sizeof(ans));
			}
			else if (s[0] == 'A'){
				cin >> x;
				find(x);
			}
			else{
				int b, y, k;
				cin >> b >> y >> k;
				for (int i = 0; i < k; i++)
					find(b + y*i);
			}
		}
	}
}
