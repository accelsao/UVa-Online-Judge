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

int n, k;
int location[1000001] = {};

int main(){
	while (cin >> n >> k){
		int l = 0, r = 0;
		for (int i = 1; i <= n; i++){
			cin >> location[i];
			r += location[i];
			l = max(l, location[i]);
		}
		for (int m = (l + r) / 2; l <= r; m = (l + r) / 2){
			int count = 0;
			int sum = 0;
			for (int i = 1; i <= n; i++){
				sum += location[i];
				if (sum > m){
					sum = location[i];
					count++;
				}
				else if (sum == m){
					count++;
					sum = 0;
				}
			}
			count += sum ? 1 : 0;
			if (count > k)l = m + 1;
			else
				r = m - 1;
		}
		cout <<l<<endl;
	}
}
----------------------------------------------------------------------
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

int n, k;
int location[1000001] = {};
int interval(int m){
	int count = 0;
	int sum = 0;
	for (int i = 1; i <= n; i++){
		sum += location[i];
		if (sum > m){
			sum = location[i];
			count++;
		}
		else if (sum == m){
			count++;
			sum = 0;
		}
		if (count > k)break;
	}
	count += sum ? 1 : 0;
	return count;
}
int bs(int l, int r){
	for (int m = (l + r) / 2; l <= r; m = (l + r) / 2){
		if (interval(m) > k)l = m + 1;
		else
			r = m - 1;
	}
	return l;
}
int main(){
	while (cin >> n >> k){
		int l = 0, r = 0;
		for (int i = 1; i <= n; i++){
			cin >> location[i];
			l = max(l, location[i]);
			r += location[i];
		}
		cout <<bs(l,r)<<endl;
	}
}
// p-Center Problem 二分
