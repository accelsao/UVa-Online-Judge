#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cmath>
#include<string>
using namespace std;

int main() {
	int t, n, L;
	int p[56];
	cin >> t;
	for (int i = 1; i <= t;i++) {
		cin >> n >> L;
		for (int i = 0; i < n; i++)
			cin >> p[i];
		p[n] = L;
		int ans = 0;
		for (int i = 0; i < n; i += 2)
			ans ^= p[i+1] - p[i];
		printf("Case %d: %s\n", i, ans ? "First Player" : "Second Player");
	}
}
