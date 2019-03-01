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




int t;
string s;
int main(){
	
	//freopen("01.txt","w",stdout);
	
	cin>>t;
	while(t--){
		int k;
		cin>>k;
		int g[5][26]={};
		int h[5][26]={};
		
		for(int i=0;i<6;i++){
			cin>>s;
			for(int j=0;j<5;j++){
				g[j][s[j]-'A']=1;
			}
		}
		for(int i=0;i<6;i++){
			cin>>s;
			for(int j=0;j<5;j++){
				h[j][s[j]-'A']=1;
			}
		}
		vector<int>d[5];
		int z=1;
		for(int j=0;j<5;j++){
			for(int i=0;i<26;i++){
				if(g[j][i]+h[j][i]==2)
					d[j].push_back(i);
			}
			z*=d[j].size();
		}
		
//		for(int i=0;i<5;i++){
//			cout<<d[i].size()<<": ";
//			for(auto x:d[i]){
//				char c='A'+x;
//				cout<<c<<" ";
//			}
//			cout<<endl;
//		}
		if(z<k){
			cout<<"NO\n";
			continue;
		}
		k--;
		//cout<<z<<endl;
		z/=d[0].size();
		for(int j=1;j<5;j++){
			int c = k/z;
			//printf("%d / %d : %d\n",k,z,c);
			k%=z;
			char ch='A'+d[j-1][c];
			cout<<ch;
			z/=d[j].size();
		}
		char ch='A'+d[4][k];
		cout<<ch<<endl;
		//system("pause");
	}
	
}
/*

1
1
AYGSU
DOMRA
CPFAS
XBODG
WDYPK
PRXWO

BBOPT
COSBG
DTRAR
EPMMS
FSXNU
GFGHI




3
1
AYGSU
DOMRA
CPFAS
XBODG
WDYPK
PRXWO
CBOPT
DOSBG
GTRAR
APMMS
WSXNU
EFGHI
5
AYGSU
DOMRA
CPFAS
XBODG
WDYPK
PRXWO
CBOPT
DOSBG
GTRAR
APMMS
WSXNU
EFGHI
64
FGHIJ
EFGHI
DEFGH
CDEFG
BCDEF
ABCDE
WBXDY
UWYXZ
XXZFG
YYFYH
EZWZI
ZGHIJ
*/
