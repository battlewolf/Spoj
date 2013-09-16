#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long int  ll ;
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007 ;
ll K = 2, num1, num2; 
vector<ll> c,b;
matrix mul (matrix A, matrix B) {
  matrix C (A.size(), vector<ll> (B[0].size(),0) );
  for(ll i = 0 ; i < A.size() ; i++) {
    for(ll j = 0 ; j < B[0].size() ; j++) {
      for(ll k = 0 ; k < A[0].size() ; k++) {
		C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
	}
    }
  }
  return C;
}

matrix expo (matrix num, ll pow) {
	if (pow == 1) return num ;
	if (pow == 2) return mul (num, num);
	
	if (pow & 1)
		return mul (num, expo (num, pow - 1)) ;
	else {
		matrix result = expo (num, pow >> 1);
		return mul (result, result);
	}
}  

ll solve () {
	vector<ll> F1(K+1);
	F1[0] = 0;
	for(ll i = 1 ; i < K+1 ; i++)
		F1[i] = b[i-1];
	
	matrix T (K+1, vector<ll> (K+1,0)) ;
	T[0][0] = T[0][1] = 1;
	for (ll i = 1 ; i < K ; i++)
		T[i][i+1] = 1;
	for (ll i = 1,j = K-1 ; i < K+1 ; i++,j--)
		T[K][i] = c[j];
		

	
	matrix T_num2 = expo (T,num2+1);
	ll s1 = 0 , s2 = 0;
	for (ll i = 0 ; i < K+1 ; i++)
		s2 = (s2 + T_num2[0][i] * F1[i]) % MOD;
	if (num1 == 0)
		return s2 % MOD; 
	else if(num1 == 1)
		return (s2 -  b[0]) % MOD;
	else
	{
		matrix T_num1 = expo (T,num1);
		for (ll i = 0; i < K+1 ; i++)
			s1 = (s1 + T_num1[0][i] * F1[i]) % MOD;
		return (s2 - s1) % MOD;
	}
//return 0;
}
main() {
	ll T ; 
	cin >> T;
	c.resize(K);b.resize(K);
	c[0] = c[1] = 1; b[0] = 0 ; b[1] = 1;
	while (T--) {
		 cin >> num1 >> num2  ;
		 if (num1 < K && num2 < K) {
			ll s = 0;
			for (ll i = num1 ; i <= num2 ; i++)
				s = s + b[i];
			cout << endl << s ;
		}
		else 		
			cout << endl << solve ();
	}
}
























