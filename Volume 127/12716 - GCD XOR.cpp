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

int F[30000005] = {};
int main() {
	for (int i = 1; i <= 30000000; i++) {
		for (int j = i*2; i + j <= 30000000; j += i) {//j為i的倍數
			if (((i + j)&(j)) == j)
				F[i + j]++;
		}
	}
	for (int i = 1; i <= 30000000; i++)
		F[i] += F[i - 1];
	int testcase, cases = 0, n;
	cin>>testcase;
	while (testcase--) {
		cin >> n;
		printf("Case %d: %d\n", ++cases, F[n]);
	}
}
/*
gcd(A, B) = C = A xor B
其中滿足 B < A and A mod C = 0，
然後我們又觀察到 A&C == C，
也就是說看 bitmask 的話，C 是 A 的 subset。
*/

/*
http://morris821028.github.io/2014/05/19/oj/uva/uva-12716/
*/
--------------------------------------------------------------------------------------
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

const int N = 30000000 + 10;
int ans[N];
int main(){
	for (int c = 1; c <= (N / 2); c++)
		for (int a = c * 2; a <= N; a += c){
			int b = a - c;
			if ((a^b) == c)ans[a]++;
		}
	//gcd(a,b) = a^b=c  b=a-c  c*2^(c)=c 
	for (int i = 2; i <= N; i++)
		ans[i] += ans[i - 1];

	int T;
	cin >> T;
	int kase = 0;
	while (T--){
		int n;
		cin >> n;
		printf("Case %d: %d\n", ++kase, ans[n]);
	}

}
/*
c是a的因數 a=k*c
b=a-c
a^(a-c) =c


gcd(A, B) = C = A xor B
其中滿足 B < A and A mod C = 0，
然後我們又觀察到 A&C == C，
也就是說看 bitmask 的話，C 是 A 的 subset。
*/
