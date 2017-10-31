#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<vector>
#include<functional>
#include<fstream>
#include<stack>
#include<vector>
#include <ctime>
#include<cmath>
using namespace std;



/*void buildSG() { // observe rule
	int mex[1024] = {}, SG[50];
	SG[0] = 0;
	for (int i = 1; i < 50; i++) {
		memset(mex, 0, sizeof(mex));
		for (int j = 1; j <= i / 2; j++)
			mex[SG[i - j]] = 1;
		int sg = 0;
		for (sg = 0; mex[sg]; sg++);
		SG[i] = sg;
		printf("%d : %d\n", i, SG[i]);
	}
}*/

long long sg(long long x) {//上表觀察所得到的規律
	return x & 1 ? sg(x / 2) : x / 2;
}
int main() {
	int t;
	cin >> t;
	long long n, ans, m;
	while (t--) {
		ans = 0;
		cin >> n;
		while (n--) {
			cin >> m;
			ans ^= sg(m);
		}
		puts(ans ? "YES" : "NO");
	}
}
