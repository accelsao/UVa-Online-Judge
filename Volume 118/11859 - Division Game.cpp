#include<iostream>
#include<cstring>
using namespace std;


int n, m, ans;
int df(int n) {
	int ans = 0;
	for (int i = 2; i*i <= n; i++)
		while (n%i == 0)
			ans++, n /= i;
	if (n > 1)
		ans++;
	return ans;
}
int main() {
	int t, x;
	cin >> t;
	for (int k = 1; k <= t;k++) {
		ans = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			int s = 0;
			for (int j = 1; j <= m; j++) {
				cin >> x;
				s += df(x);
			}
			ans ^= s;
		}
		printf("Case #%d: %s\n", k, ans ? "YES" : "NO");
	}
}
