#include <bits/stdc++.h>
#define LL long long
#define Accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define Re(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, A, B) for (int I = (A); I <= (B); I++)
#define REP(I, N) for (int I = 0; I < (N); I++)
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define SZ(a) ((int)a.size())
//#pragma GCC optimize(2)
using namespace std;
const int N=1e6+1;
const int M=998244353;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//for(int mask=i;mask>0;mask=(mask-1)&i)
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){int t=0;while(x){t+=BIT[x];x-=x&-x;}return t;}
//LL pw(LL a,LL b){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)


int t,n;
struct LW{
	int l,r,c;
}d[N];
bool cmp(LW a,LW b){
	return a.r<b.r||(a.r==b.r&&a.c>b.c);
}
int f[N];
int main(){

	
//	freopen("01.txt","w",stdout);
	int tc=0;
	cin>>t;
	while(t--){
		for(int i=0;i<=200005;i++)
			f[i]=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>d[i].l>>d[i].r>>d[i].c;
			d[i].l++,d[i].r+=d[i].l-1;
		}
		sort(d,d+n,cmp);
		
		int j=0;
		for(int i=1;i<=200005;i++){
			f[i]=f[i-1];
			while(j<n&&d[j].r==i){
				f[i]=max(f[i],f[max(d[j].l-1,0)]+d[j].c);
				j++;
			}
			
			
		}
//		cout<<f[100000]<<endl;
		printf("Case %d: %d\n",++tc,f[200001]);
	}

	
}

/*


12345
 234567890
      xxxxxx  

*/
