#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<string>
#include<vector>
using namespace std;


vector<char>q[9];
double d[5][5][5][5][5][5][5][5][5];
int v[5][5][5][5][5][5][5][5][5];
double dp(int t0, int t1, int t2, int t3, int t4, int t5, int t6, int t7, int t8){
	double &ans = d[t0][t1][t2][t3][t4][t5][t6][t7][t8];
	if (v[t0][t1][t2][t3][t4][t5][t6][t7][t8])return ans;
	v[t0][t1][t2][t3][t4][t5][t6][t7][t8] = 1;
	int left[9] = { t0, t1, t2, t3, t4, t5, t6, t7, t8 };
	int ok = 1;
	for (int i = 0; i < 9; i++)if (left[i]){ ok = 0; break; }
	if (ok)return ans = 1;
	ans = 0;
	int num = 0; double p = 0;
	for (int i = 0; i < 9; i++)
		if (left[i])
			for (int j = i + 1; j < 9;j++)
				if (left[j] && q[i][left[i] - 1] == q[j][left[j] - 1]){
					num++;
					left[i]--, left[j]--;
					p += dp(left[0], left[1], left[2], left[3], left[4], left[5], left[6], left[7], left[8]);
					left[i]++, left[j]++;
				
				}
	if (!num)return ans = 0;
	return ans = p / (num*1.0);

}
int main(){
	string s;
	while (cin >> s){

		memset(d, 0, sizeof(d));
		memset(v, 0, sizeof(v));

		for (int i = 0; i < 9; i++)q[i].clear();
		q[0].push_back(s[0]);
		for (int i = 0; i < 3; i++)
			cin >> s, q[0].push_back(s[0]);
		for (int i = 1; i < 9; i++)
			for (int j = 0; j < 4; j++){
				cin >> s;
				q[i].push_back(s[0]);
			}
		printf("%lf\n", dp(4, 4, 4, 4, 4, 4, 4, 4, 4));
	
	}
}
----------------------------------------------------------------------------------
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<functional>
#include<unordered_map>
using namespace std;



map<vector<int>, double> d;
vector<char>q[9];
double dp(vector<int> cnt, int c) {
	if (c == 0) return 1;
	if (d.count(cnt)) return d[cnt];
	double sum = 0;
	int tot = 0;
	for (int i = 0; i<9; i++) 
		if (cnt[i])
		for (int j = i + 1; j<9; j++) 
			if (cnt[j]&& q[i][cnt[i] - 1] == q[j][cnt[j] - 1]){
				tot++;
				cnt[i]--; cnt[j]--;
				sum += dp(cnt, c - 2);
				cnt[i]++; cnt[j]++;
			}
	if (!tot) return d[cnt] = 0;
	return d[cnt] = sum / tot;
}
int main() {
	string s;
	while (cin>>s) {
		for (int i = 0; i < 9; i++)q[i].clear();
		q[0].push_back(s[0]);
		for (int i = 0; i < 3; i++)
			cin >> s, q[0].push_back(s[0]);
		for (int i = 1; i < 9; i++)
			for (int j = 0; j < 4; j++) {
				cin >> s;
				q[i].push_back(s[0]);
			}
		vector<int> cnt(9, 4);
		d.clear();
		printf("%lf\n", dp(cnt, 36));
	}
}
