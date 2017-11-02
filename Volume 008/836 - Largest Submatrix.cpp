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

string s[1000];
bool check(int i, int i_end, int j){
	//檢查方格是否都是1
	for (i; i <= i_end; ++i) //x軸長度
		if (s[i][j] != '1')
			return false;
	return true;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		cin >> s[0];
		int N = s[0].size();
		for (int i = 1; i < N; ++i)
			cin >> s[i];
		int sum = 0, ans = 0;
		for (int Len = 1; Len <= N; ++Len) {//垂直的長度 從1到8  
			for (int i = 0; i <= N-Len; ++i) {
				sum = 0;
				for (int j = 0; j < N; ++j) {
					if (check(i, i + Len - 1, j))
						sum += Len;
					else
						sum = 0;

					if (sum > ans) ans = sum;
				}
			}
		}
		cout << ans << endl;
		if (t) cout << endl;
	}
}
