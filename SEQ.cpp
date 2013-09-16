#include <iostream>
#include <vector>
#include <algorithm>
#define REP(i,n) for(int i = 1 ; i <= n ;i++)
using namespace std;

typedef long long int ll;
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000000;
ll K , n;
vector<ll> b, c;
matrix mul (matrix A, matrix B){
	matrix C(K+1, vector<ll> (K+1)) ;
	REP(i,K){
		REP(j,K){
			ll s = 0;
			REP(k,K)
				s = (s + A[i][k] * B[k][j]) % MOD;
			C[i][j] = s;
		}
	}
	return C;			
}
matrix expo (matrix num, int pow){
	if (pow == 1) return num;
	if (pow & 1) return mul(num,expo(num,pow-1));
	else{
		matrix result = expo(num, pow>>1);
		return mul(result,result);
	}
}

int solve(){
	vector<ll> F1 (K+1);
	REP(i,K) F1[i] = b[i];
	//So we have filled F1 and now we have to fill the T transformation matrix
	matrix T (K+1,vector<ll>(K+1,0));
	for(int i = 1 ; i <= K-1 ; i++) T[i][i+1] = 1;
	for(int i = 1,j = K ; i <= K ; i++,j--) T[K][i] = c[j]; 
	T = expo (T,n-1);
	ll s = 0;
	for(int i = 1 ; i <= K ;i++)
		s = (s + T[1][i] * F1[i]) % MOD;
	return s;			
}
main(){
	//b stores the first k values and c stores the constants
	int T;cin>>T;
	while(T--){
		cin>>K;
		b.resize(K+1);c.resize(K+1);
		REP(i,K) {cin>>b[i];}
		REP(i,K) {cin>>c[i];}
		cin>>n;
		cout<<endl<<solve();
	}
}
