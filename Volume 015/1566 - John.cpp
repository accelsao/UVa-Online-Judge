#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;



int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		bool f = 0;
		int ans = 0, x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			ans ^= x;
			f |= x > 1;
		}
		if (!f)
			puts(n & 1 ? "Brother" : "John");
		else
			puts(ans ? "John" : "Brother");
	}
}
