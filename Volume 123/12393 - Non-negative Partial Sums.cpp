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
using namespace std;




const int N = 2000005;
int s[N];
int main() {
	int n;
	while (cin >> n, n) {
		for (int i = 0; i < n; i++)
			cin >> s[i], s[i + n] = s[i];
		for (int i = 1; i < n * 2; i++)
			s[i] += s[i - 1];
		deque<int>q;
		int ans = 0;
		for (int i = 0; i < n * 2; i++) {
			while (!q.empty() && s[q.back()] >= s[i])
				q.pop_back();
			q.push_back(i);
			if (i >= n&&s[q.front()] - s[i - n] >= 0)ans++;
			while (!q.empty() && i - q.front() + 1 > n)q.pop_front();
		}
		printf("%d\n", ans);
	}
}
