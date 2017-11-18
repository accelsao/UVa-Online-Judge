#include<iostream>
#include<cstring>
using namespace std;
#define N 5005
#define Re(a,b) memset(a,b,sizeof(a))
int n, x[N][2], y[N][2],ans[2][N];
bool solve(int a[][2], int k){
	Re(ans[k], -1);
	for (int i = 1; i <= n; i++){
		int rk = -1, r = n + 1;
		for (int j = 1; j <= n; j++)
			if (ans[k][j] < 0 && a[j][1] < r&&i >= a[j][0])
				rk = j, r = a[j][1];
		if (rk<0 || i>r)return 0;
		ans[k][rk] = i;
	}
	return 1;
}
int main(){
	while (cin >> n){
		for (int i = 1; i <= n; i++)
			cin >> x[i][0] >> y[i][0] >> x[i][1] >> y[i][1];
		if (solve(x, 0) && solve(y, 1))
			for (int i = 1; i <= n; i++)
				printf("%d %d\n", ans[0][i], ans[1][i]);
		else
			puts("IMPOSSIBLE");
	}
}
