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

struct segment{
	int start, end;
}p;

bool cmp(segment a, segment b){
	return a.start < b.start;
}
int main(){
	int n;
	while (cin >> n){

		int m;
		for (int i = 0; i < n; i++){
			if (i)puts("\n");
			cin >> m;
			vector<segment>v,ans;
			v.clear();
			ans.clear();
			while (cin >> p.start >> p.end, p.start||p.end){
				
				v.push_back(p);
			}
			sort(v.begin(), v.end(),cmp);
			int ts=0,te = 0;
			
			for (int i = 0; i != v.size(); i++){
				int temp = -1;
				for (; i != v.size() && v[i].start <= ts; i++)
					if (v[i].end > te){
						te = v[i].end;
						temp = i;
					}
				
				if (temp==-1)break;
				ans.push_back(v[temp]);
				if (te >= m)break;
				ts = te;
				i--;
			}
			if (te < m){
				printf("0\n"); continue;
			
			}
			printf("%d\n", ans.size());
			for (int i = 0; i < ans.size();i++)
				printf("%d %d\n", ans[i].start, ans[i].end);
		}
	}
}
