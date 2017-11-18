
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstdio>
#include<queue>
#include<cmath>
#include<stack>
#include<sstream>
using namespace std;

int dp[35][35];
int w[35][35];

int main(){
	int t;
	while (cin >> t){
		getchar();
		for (int k = 1; k <= t;k++){
			string s1, s2;
			getline(cin, s1);
			getline(cin, s2);
			int l1 = s1.size();
			int l2 = s2.size();

			for (int i = 0; i <= l1; i++)
				for (int j = 0; j <= l2; j++)
					dp[i][j] = w[i][j] = 0;

			for (int i = 0; i <= l1; i++)
				w[i][0] = 1;
			for (int i = 0; i <= l2; i++)
				w[0][i] = 1;

			for (int i = 1; i <= l1; i++)
				for (int j = 1; j <= l2; j++)
					if (s1[i-1] == s2[j-1]){
						dp[i][j] = dp[i - 1][j - 1] + 1;
						w[i][j] = w[i - 1][j - 1];
					}
					else{
						if (dp[i - 1][j] > dp[i][j - 1]){
							dp[i][j] = dp[i - 1][j];
							w[i][j] = w[i - 1][j];
						}
						else if (dp[i - 1][j] < dp[i][j - 1]){
							dp[i][j] = dp[i][j - 1];
							w[i][j] = w[i][j - 1];
						}
						else{
							dp[i][j] = dp[i - 1][j];
							w[i][j] = w[i][j - 1] + w[i - 1][j];
						}
					}
					printf("Case #%d: %u %u\n", k, l1 + l2 - dp[l1][l2], w[l1][l2]);
		}
	}
}
