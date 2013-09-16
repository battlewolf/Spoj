#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll ;
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
ll K, num1, num2 ; 
vector<ll> c,b;
matrix mul (matrix A, matrix B) {
  matrix C (A.size(), vector<ll> (B[0].size(),0) );
  for(int i = 0 ; i < A.size() ; i++) {
    for(int j = 0 ; j < B[0].size() ; j++) {
      for(int k = 0 ; k < A[0].size() ; k++) {
		C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
	}
    }
  }
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
	for(int i = 1 ; i < K+1 ; i++)
		F1[i] = b[i-1];
	
	matrix T (K+1, vector<ll> (K+1,0)) ;
	T[0][0] = T[0][1] = 1;
	for (int i = 1 ; i < K ; i++)
		T[i][i+1] = 1;
	for (int i = 1,j = K-1 ; i < K+1 ; i++,j--)
		T[K][i] = c[j];
		
	cout << endl << "Displaying the T matrix \n";
	for (int i = 0 ; i < K+1 ; i++) {
		for (int j = 0 ; j < K+1 ; j++)
			cout << T[i][j] << " ";
		cout << endl;
	}
	cout << endl << "Displaying the F1 matrix \n";
	for (int i = 0 ; i < K+1 ; i++)
		cout << F1[i] << "\n";
	
	matrix T_num2 = expo (T,num2);
	ll s1 = 0 , s2 = 0;
	for (int i = 0 ; i < K+1 ; i++)
		s2 = (s2 + T_num2[0][i] * F1[i]) % MOD;
	
	if (num1 < K)	{
		s1 = b[num1];
		return s2 - s1;
	}
	else {
		matrix T_num1 = expo (T,num1-1);
		for (int i = 0; i < K+1 ; i++)
			s1 = (s1 + T_num1[0][i] * F1[i]) % MOD;
		return s2 - s1;
	}
}
main() {
	int T ; 
	cin >> T;
	while (T--) {
		cin >> K;c.resize(K);b.resize(K);
		for (int i = 0 ; i < K ; i++) cin >> c[i];
		for (int i = 0 ; i < K ; i++) cin >> b[i];
		cin >> num1 >> num2 ;
		num1-- ; num2--;
		if (num1 < K && num2 < K) 
			cout << endl << b[num2] - b[num1];
		else 		
			cout << endl << solve ();
	}
}
























