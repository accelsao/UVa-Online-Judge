-------------------------------------------從0到7
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstdio>
#include<queue>
using namespace std;

int a, b;
int y[9];
int lr[16], rr[16];
int sol[9];
int cc;
void bt(int n){

	if (n == 8){
		printf("%2d      ", cc++);
		for (int i = 0; i < 8; i++){
			if (i)printf(" ");
			printf("%d", sol[i]+1);
		}
		printf("\n");
		return;
	}
	if (n == b)bt(n + 1);
	else{
		for (int i = 0; i < 8; i++){
			int d1 = (n - i + 7), d2 = (n + i);
			if (!y[i] && !lr[d1] && !rr[d2]){
				y[i] = lr[d1] = rr[d2] = 1;
				sol[n] = i;
				bt(n + 1); //2,1 3,2
				y[i] = lr[d1] = rr[d2] = 0;
			}
		}
	}
}

int main(){

	int n;
	cin >> n;
	bool bl = 0;
	while (n--){
		cc = 1;
		for (int i = 0; i < 8; i++)
			y[i] =sol[i]= 0;
		for (int i = 0; i < 15; i++)
			lr[i] = rr[i] = 0;

		cin >> a >> b;
		if (bl)cout << "\n";
		else bl = 1;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		a--, b--;
		//相當於 (b,a) 點 左上0,0 右下 7,7
 		sol[b] = a;
		y[a] = lr[b-a+7] = rr[a+b] = 1;

		bt(0);
	}
}
--------------------------------------------------------從1到8
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstdio>
#include<queue>
using namespace std;

int a, b;
int y[9];
int lr[16], rr[16];
int sol[9];
int cc;
void bt(int n){

	if (n == 9){
		printf("%2d      ", cc++);
		for (int i =1; i < 9; i++){
			if (i!=1)printf(" ");
			printf("%d", sol[i]);
		}
		printf("\n");
		return;
	}
	if (n == b)bt(n + 1);
	else{
		for (int i = 1; i < 9; i++){
			int d1 = (n - i + 7), d2 = (n + i-2);
			if (!y[i] && !lr[d1] && !rr[d2]){
				y[i] = lr[d1] = rr[d2] = 1;
				sol[n] = i;
				bt(n + 1); //2,1 3,2
				y[i] = lr[d1] = rr[d2] = 0;
			}
		}
	}
}

int main(){

	int n;
	cin >> n;
	bool bl = 0;
	while (n--){
		cc = 1;
		for (int i = 1; i < 9; i++)
			y[i] =sol[i]= 0;
		for (int i = 0; i < 15; i++)
			lr[i] = rr[i] = 0;

		cin >> a >> b;
		if (bl)cout << "\n";
		else bl = 1;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		
		//相當於 (b,a) 點 左上0,0 右下 7,7
 		sol[b] = a;
		y[a] = lr[b-a+7] = rr[a+b-2] = 1;

		bt(1);
	}
}
8 queen 1.從0~7 2.從1~8 //右斜相加範圍1 1~8 8 陣列0~14 需-2 左斜範圍 1-8~8-1 需 7
