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


int main(){
	int a,b;
	double fh[101] = {};//height
	double fl[101] = {};//length
	double gh[101] = {};
	double gl[101] = {};
	while (cin >> a){
		for (int i = 0; i < a; i++){
			cin >> fh[i] >> fl[i];
			if (i)fl[i] += fl[i - 1];
		}
		cin >> b;
		for (int i = 0; i < b; i++){
			cin >> gh[i] >> gl[i];
			if (i)gl[i] += gl[i - 1];
		}
		double ans = 1e11;
		int fn = 0;
		int gn = 0;
		while (fn < a&&gn < b){
			ans = min(ans, max(fh[fn], gh[gn]));
			if(fl[fn]>=gl[gn])gn++;
			if(fl[fn] <= gl[gn])fn++;
		}
		while (fn < a){
			ans = min(ans, max(fh[fn], gh[gn-1]));
			fn++;
		}
		while (gn < b){
			ans = min(ans, max(fh[fn-1], gh[gn]));
			gn++;
		}
		printf("%.3lf\n", ans);
	}
}
