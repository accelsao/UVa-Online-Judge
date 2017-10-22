#include <iostream>   
#include <algorithm>  
using namespace std;


int dp[2001][10001], w[2001], sum[2001];
int pre[2001][10001], ans[2001];

int main(){
	int t, i, j, k, V, n, vj;
	cin >> t;
	while (t--){
		cin >> V;
		V *= 100;
		n = 1;
		sum[0] = 0;
		while (cin >> k, k)
		{
			
			w[n] = k;
			sum[n] = sum[n - 1] + k;
			n++;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < V; j++)
				dp[i][j] = 0;
		dp[0][0] = 1;
		vj = -1;
		for (i = 1; i < n; i++){
			for (j = 0; j <= V; j++){
				if (j >= w[i] && dp[i - 1][j - w[i]]) {

					k = i;
					vj = j;

					dp[i][j] = 1;
					pre[i][j] = j - w[i];
				}
				else if (sum[i] - j <= V && dp[i - 1][j]) {

					 k = i;
					 vj = j;
					dp[i][j] = 1;
					pre[i][j] = j;  //记录路径  
				}
			}
		}
		i = k;
		while (i--){
			j = pre[i + 1][vj];
			if (j == vj) ans[i] = 1;
			else ans[i] = 0;
			vj = j;
		}
		cout << k << endl;
		for (i = 0; i < k; i++){
			if (ans[i]) puts("starboard");
			else puts("port");
		}
		if (t) puts("");
	}
}
