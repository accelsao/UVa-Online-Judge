---------------------------------------------
//LPS+字典序
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

struct node{
	int len;
	string str;
	bool operator > (node a){
		if (len != a.len)return len > a.len;
		return str < a.str;//字典序
	}
}dp[1001][1001];

string s,r;
int main(){
	while (cin >> s){
		int l = s.size()-1;
		for (int i = l; i >= 0; i--){
			dp[i][i].len = 1;
			dp[i][i].str = s[i];
			for (int j = i + 1; j <= l; j++)
				if (s[i] == s[j])dp[i][j].len = dp[i + 1][j - 1].len + 2, dp[i][j].str = s[i] + dp[i + 1][j - 1].str + s[i];
				else if (dp[i + 1][j] > dp[i][j - 1])dp[i][j] = dp[i + 1][j];
				else dp[i][j] = dp[i][j - 1];
		}
		cout << dp[0][l].str << endl;
	}
}
---------------------------------------------------
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

struct node{
	int len;
	string str;
	bool operator > (node a){
		if (len != a.len)return len > a.len;
		return str < a.str;//字典序
	}
}dp[1001][1001];

string s;
int main(){
	while (cin >> s){
		int l = s.size()-1;
		for (int i = 0; i <= l; i++){
			dp[i][i].len = 1;
			dp[i][i].str = s[i];
			for (int j = i - 1; j >= 0;j--)
				if (s[i] == s[j])dp[i][j].len = dp[i - 1][j + 1].len + 2, dp[i][j].str = s[i] + dp[i - 1][j + 1].str + s[i];
				else if (dp[i - 1][j] > dp[i][j + 1])dp[i][j] = dp[i - 1][j];
				else dp[i][j] = dp[i][j + 1];
		}
		cout << dp[l][0].str << endl;
	}
}
