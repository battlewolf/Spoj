#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007,K = 2;
int M, N; 
matrix mul (matrix A, matrix B){
	matrix C (A.size(), vector<ll> (B[0].size()));
	for (int i = 0 ; i < A.size() ; i++) {
		for (int j = 0 ; j < A[0].size() ; j++) {
			for(int k = 0 ; k < B.size() ; k++) {
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
			}
		}
	}
	return C;
}
matrix expo (matrix num, int pow) {
	if (pow == 1) return num ;
	if (pow == 2) return mul (num, num);
	if (pow & 1) return mul (num, expo (num, pow - 1));
	else {
		matrix result = expo (num, pow >> 1);
		return mul (result,result);

	}
}
void disp (matrix A) {
	for (int i = 0 ; i < K  +  1; i++){
		for (int j = 0 ; j < K +  1; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
	cout << endl << endl ;
}
ll solve () {
	vector<ll> F1 (K+1);
	F1[0] = 0 ; F1[1] = 0 ; F1[2] = 1;
	//Computer Transformatino matrix T	
	matrix T (K+1, vector<ll> (K+1,0));
	T[0][0] = T[0][1] = 1;
	T[1][2] = 1;
	T[2][1] = 1;
	T[2][2] = 0;
	cout <<" I am safe till here ";
	if ( M < 2 && N < 2){
		cout << " burundi ";	
	}
	else {
		matrix S_M = expo (T, N);
		matrix S_N = expo (T,M-1);
		cout << "\n Displaying T matrix \n";
		disp (T);
		cout << "\n Displaying M matrix \n";
		disp (S_M);
		cout << "\n Displaying N matrix \n";
		disp (S_N);
		ll n = 0 , m = 0;
		for (int i = 0 ; i < K+1 ; i++)
			n = (n + S_N[0][i] * F1[i]) % MOD;	
		for (int i = 0 ; i < K+1 ; i++)
			m = (m + S_M[0][i] * F1[i]) % MOD;
		cout << "n:" << n << " m:" << m;
		return abs (n-m) ;
	}
}

main() {
	int t ; cin >> t ; while (t--){
		cin >> N >> M ; 
		cout << endl << solve() ; 
	}
}
