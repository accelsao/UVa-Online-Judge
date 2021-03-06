#include<string>
#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<stack>
#include<cctype>
#include<cstring>
#include<sstream>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include <regex>
using namespace std;

#define M 100001

int sum[M],q[M];
int n, L;
int cmp(double x){
	if (fabs(x) < 1e-6)return 0;//誤差
	else if (x > 0)return 1;
	return -1;
}
double func(int i, int j){//斜率
	return (sum[j] - sum[i])*1.0 / (j - i);
}

int main(){
	int t;
	string s;
	cin >> t;
	while (t--){
		cin >> n >> L;
		cin >> s;
		sum[0] = 0;
		for (int i = 1; i <= s.size(); i++)
			sum[i] = sum[i - 1] + s[i - 1] - '0';
		int head = 0, tail = -1;
		double ans = -1;
		int ansl, ansr;
		for (int i = L; i <= n; i++){
			int j = i - L;
			while (head < tail&&cmp(func(q[tail - 1],j) - func(q[tail],j)) >= 0)//刪除上凸點 點j右邊 點q[tail]左 若是上凸點 q[tail],j <q[tail-1],j 應刪除 
				tail--;
			q[++tail] = j;
			while (head < tail && cmp(func(q[head + 1], i) - func(q[head], i)) >= 0)//找到斜率更大的切點
				head++;
			double tmp = func(q[head], i);
			if (cmp(tmp - ans) > 0 || cmp(tmp - ans) == 0 && i - q[head] < ansr - ansl){//找平均最大 若一樣取長度小 起點編號從小開始
				ans = tmp;
				ansl = q[head];
				ansr = i; 
			}
		}
		printf("%d %d\n", ansl + 1, ansr);
	}
}
