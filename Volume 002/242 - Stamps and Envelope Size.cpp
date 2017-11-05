#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstdio>
#include<queue>
#include<cmath>
#include<stack>
#include<cctype>
#include<sstream>
using namespace std;



int s, n;
int main(){
	while (cin >> s, s){
		cin >> n;
		int ans = -1, num, v[11], m, p[11];
		for (int i = 0; i < n; i++){
			cin >> m;
			for (int j = 0; j < m; j++)
				cin >> p[j];
			int dp[1001] = {};
			dp[0] = 1;
			for (int i = 0; i < m; i++)
				for (int j = 0; j <= 1000; j++)
					if (dp[j] && dp[j] <= s)
						if (dp[j + p[i]]>dp[j] + 1 || !dp[j + p[i]])
							dp[j + p[i]] = dp[j] + 1;//dp[金額]
			int r = 0;
			while (dp[r])r++;
			r--;
			//比數字
			if (r > ans){
				ans = r; num = m;
				for (r = 0; r < m; r++)
					v[r] = p[r];
			}
			else if (ans == r)
				if (num > m){//比長度 取較短
					num = m;
					for (int i = 0; i < m; i++)
						v[i] = p[i];
				}
				else if (num == m){
					//從後取小的 (字典序最小者)
					bool f = 0;
					for (r = m - 1; r >= 0; r--){
						f = (v[r] < p[r]);		
						if (v[r] != p[r])break;		
					}
					if (!f)
						for (int i = 0; i < m; i++)
							v[i] = p[i];
				}
			
		}
		printf("max coverage =%4d :", ans);
		for (int i = 0; i < num; i++)
			printf("%3d", v[i]);
		puts("");
	}

}
