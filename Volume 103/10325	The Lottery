#include <iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;

long long gcd(long long a, long long b){
	return b ? gcd(b, a%b) : a;
}
long long lcm(long long a,long long b){
	return a / gcd(a, b)*b;
}
int a[16] = {};
int n, m;
long long bt(int s, long long d){
	if (s == m)return n / d;
	return bt(s + 1, d) - bt(s + 1, lcm(d, a[s]));
}

int main(){
	
	while (cin >> n >> m){
		for (int i = 0; i < m; i++)
			cin >> a[i];
		cout << bt(0, 1) << endl;
	}
	
}
排容原理
