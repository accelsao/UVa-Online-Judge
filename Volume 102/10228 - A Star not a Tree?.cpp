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




const int d[4][2] = { { 1, 0 },{ 0, 1 },{ -1, 0 },{ 0, -1 } };

const int N = 105;
const double eps = 1e-3;

int t, n;

struct Point {
	double x, y, d;
	Point() {}
	Point(double a, double b) {
		x = a; y = b;
	}
} p[N];

double getdis(Point P) {
	double ans = 0;
	for (int i = 0; i < n; i++) {
		double dx = p[i].x - P.x;
		double dy = p[i].y - P.y;
		ans += sqrt(dx * dx + dy * dy);
	}
	return ans;
}

double gao() {
	int cnt = 10;
	double ans = 1e20, r = 0.83;
	srand(time(NULL));
	while (cnt--) {
		double step = 1e4;
		Point now = Point(rand() % 10001, rand() % 10001);
		now.d = getdis(now);
		while (step > eps) {
			Point next;
			for (int i = 0; i < 4; i++) {
				next = Point(now.x + step * d[i][0], now.y + step * d[i][1]);
				next.d = getdis(next);
				if (next.d < now.d)
					now = next;
			}
			step *= r;
			ans = min(ans, now.d);
		}
	}
	return ans;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", &p[i].x, &p[i].y);
		printf("%.0lf\n", gao());
		if (t) printf("\n");
	}
	return 0;
}
