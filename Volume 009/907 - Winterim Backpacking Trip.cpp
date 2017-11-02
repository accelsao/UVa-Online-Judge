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
bool interval(int m){
	int count = 0;
	int sum = 0;
	for (int i = 1; i <= n; i++)
		if (sum + location[i] <= m)sum += location[i];
		else{
			count++;
			sum = location[i];
		}
	if (sum)count++;//有剩下
	return count<= k;
}
int bs(int l, int r){
	for (int m = (l + r) / 2; l <= r; m = (l + r) / 2){
		if (interval(m))r = m - 1;//看有無更佳解
		else
			l = m + 1;//區間寬要更長
	}
	return l;
}
int main(){
	while (cin >> n >> k){
		n++;//n段路
		k++;//k個時段
		int l = 0, r = 0;
		for (int i = 1; i <= n; i++){
			cin >> location[i];
			l = max(l, location[i]);
			r += location[i];
		}
		cout <<bs(l,r)<<endl;
	}
}
//p-Center Problem 二分
