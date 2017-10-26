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

/* n為長度  
S[i, i+n-1] 的最小值 要大於等於 S[i]
*/


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
			while (!q.empty() && s[q.back()] >= s[i])//放入區間最小 維護小到大
				q.pop_back();
			q.push_back(i);
			if (i >= n&&s[q.front()] - s[i - n] >= 0)ans++;//區間最小 >=s[i] 合法
			while (!q.empty() && i - q.front() + 1 > n)q.pop_front();//超過長度 
		}
		printf("%d\n", ans);
	}
}
/*
3
-1 1 1
-1 1 1 -1 1 1
s[] 
-1 0 1 0 1 2

*/
