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
#include<unordered_map>
using namespace std;

struct point{
	int x, y;
}p[501];
int m[125000];
struct edge{
	int a, b;
	double d;
};
double dis(int i, int j){
	return sqrt((p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y));
}
bool cmp(edge a, edge b){
	return a.d < b.d;
}
int find(int x){
	return m[x] == x ? x : m[x] = find(m[x]);
}
int main(){
	int t;
	cin >> t;
	while (t--){
		int s, n;
		cin >> s >> n;
		for (int i = 0; i < n; i++){
			cin >> p[i].x >> p[i].y;
			m[i] = i;
		}
		vector<edge>v;
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				v.push_back(edge{ i, j, dis(i, j) });
		sort(v.begin(), v.end(), cmp);
		vector < double > ans;
		for (int i = 0, j = 0; j < n - 1; i++){
			int x = find(v[i].a);
			int y = find(v[i].b);
			if (x != y){
				m[x] = y;
				ans.push_back(v[i].d);
				j++;
			}
		}
		printf("%.2f\n", ans[n - 1 - s]);	
	}
}
