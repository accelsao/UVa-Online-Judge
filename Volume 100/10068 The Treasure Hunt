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
#include<stack>
using namespace std;

struct state{
	int d, step;
	state* pre;
	void init(){
		d = 1e9, step = 0, pre = 0;
	}
};
char m[25][25];
string dstr[4] = { "E", "W", "S", "N" };
int p[25][2];
int r, c, walk, t;
int sx, sy, ex, ey;
state dis[20][20][1 << 11];
int v[20][20][1 << 11];
int w[1 << 11];
const int dw[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
void spfa(){
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			for (int k = 0; k < (1 << t); k++)
				dis[i][j][k].init(), v[i][j][k] = 0;
	w[0] = 0;
	for (int i = 1; i < (1 << t); i++){
		int sum = 0, k = i, j = 0;
		while (k){
			if (k & 1)
				sum += p[j][1];
			k >>= 1; j++;
		}
		w[i] = sum;//各種集合 攜帶時所消耗的能量
	}
	int tx, ty, ts, ss;
	queue<int>X, Y, S;
	dis[sx][sy][0].d = 0;
	X.push(sx), Y.push(sy), S.push(0);
	while (!X.empty()){
		sx = X.front(), X.pop();
		sy = Y.front(), Y.pop();
		ss = S.front(), S.pop();
		v[sx][sy][ss] = 0;
		for (int k = 0; k < 4; k++){
			tx = sx + dw[k][0]; ty = sy + dw[k][1]; ts = ss;
			if (tx < 0 || ty < 0 || tx >= r || ty >= c || m[tx][ty] == '#')continue;
			if (dis[tx][ty][ts].d > dis[sx][sy][ss].d + w[ss] + walk) {
				dis[tx][ty][ts].d = dis[sx][sy][ss].d + w[ss] + walk;
				dis[tx][ty][ts].pre = &dis[sx][sy][ss];
				dis[tx][ty][ts].step = 1 << k;
				if (!v[tx][ty][ts]){
					v[tx][ty][ts] = 1;
					X.push(tx), Y.push(ty), S.push(ts);
				}
			}
			if (m[tx][ty] >= '0'&&m[tx][ty] <= '9'){
				ts = ss | (1 << (m[tx][ty] - '0'));
				if (dis[tx][ty][ts].d > dis[sx][sy][ss].d + w[ss] + walk+p[m[tx][ty]-'0'][0]) {
					dis[tx][ty][ts].d = dis[sx][sy][ss].d + w[ss] + walk + p[m[tx][ty] - '0'][0];
					dis[tx][ty][ts].pre = &dis[sx][sy][ss];
					dis[tx][ty][ts].step = (1 << k) | (1 << 4);
					if (!v[tx][ty][ts]){
						v[tx][ty][ts] = 1;
						X.push(tx), Y.push(ty), S.push(ts);
					}
				}
			}
		}
	}
	if (dis[ex][ey][(1<<t)-1].d==1e9)
		puts("The hunt is impossible.");
	else{
		printf("Minimum energy required = %d cal\n", dis[ex][ey][(1 << t) - 1].d);
		state *p = &dis[ex][ey][(1 << t) - 1];
		string ans = "";
		while (p){
			if ((p->step >> 4) & 1)
				ans = "P" + ans;
			for (int k = 0; k < 4; k++)
				if (((p->step) >> k) & 1)
					ans = dstr[k] + ans;
			p = p->pre;
		}
		puts(ans.c_str());
	}		
}
int main(){
	int T = 1;
	while (cin >> r >> c, r + c){
		t = 0;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> m[i][j];
		cin >> walk;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++){
				if (m[i][j] == '*'){
					m[i][j] = t + '0';
					cin >> p[t][0] >> p[t][1];
					t++;
				}
				if (m[i][j] == 'S')sx = i, sy = j;
				if (m[i][j] == 'T')ex = i, ey = j;
			}
		
		printf("Hunt #%d\n", T++);
		spfa();
		puts("");
	}
}
