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

int n;
int a[101][101];
int main(){
	while (cin >> n){
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		int ans = -1e9;

		for (int i = 0; i < n; i++){
			int s[101] = {};
			for (int j = i; j < n; j++){
				for (int k = 0; k < n; k++)
					s[k] += a[j][k];
				int ans1 = -1e9;
				int s1 = 0;
				for (int i = 0; i < n; i++){
					if (s1 >= 0)s1 += s[i];
					else s1 = s[i];
					ans1 = max(ans1, s1);
				}
				ans = max(ans, ans1);
			}
		}
		if (!ans){
			int t=-128;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++){
					if (a[i][j] <= 0)
						t = max(t, a[i][j]);
				}
			ans = t;
		}
		cout << ans<< endl;
	}
}
