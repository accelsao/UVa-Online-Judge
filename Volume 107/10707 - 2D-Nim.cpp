#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;


int h, w, n;
int g[105][105] = {};
int a[2][3005];
void cal(int S) {
	int L[105][105], R[105][105], U[105][105], D[105][105];
	int c;
	for (int i = 0; i < w; i++)
		for (int j = 0, c = 0; j < h; j++)
			c = g[i][j] ? c + g[i][j] : 0, L[i][j] = c;
	for (int i = 0; i < w; i++)
		for (int j = h-1, c = 0; j >=0; j--)
			c = g[i][j] ? c + g[i][j] : 0, R[i][j] = c;
	for (int j = 0; j < h; j++)
		for (int i = 0, c = 0; i < w; i++)
			c = g[i][j] ? c + g[i][j] : 0, U[i][j] = c;
	for (int j = 0; j < h; j++)
		for (int i = w-1, c = 0; i >=0; i--)
			c = g[i][j] ? c + g[i][j] : 0, D[i][j] = c;
	int k = 0;
	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++)
			if (g[i][j])
				a[S][k++] = L[i][j] + R[i][j] + U[i][j] + D[i][j];
	sort(a[S], a[S] + k);
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> w >> h >> n;

		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 101; j++)
				g[i][j] = 0;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			g[x][y] = 1;
		}
		cal(0);
		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 101; j++)
				g[i][j] = 0;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			g[x][y] = 1;
		}
		cal(1);
		bool f = 0;
		for (int i = 0; i < n; i++)
			if (a[0][i] != a[1][i]) {
				f = 1;
				break;
			}
		puts(f ? "NO" : "YES");
	}
}
