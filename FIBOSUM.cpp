/*#include <ctime>
#include <map>
#include <cstdlib>
#include <xiostream>
#include <vector>
using namespace std;
typedef long long int ll;
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007,K = 3; 
matrix mul (matrix A, matrix B){
	matrix C (A.size()-1+1, vector<ll> (B[0].size()-1+1,0));
	for (int i = 1 ; i <= K ; i++) {
		for (int j = 1 ; j <= K ; j++) {
			for(int k = 1 ; k <= K ; k++) {
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
	for (int i = 1 ; i <= K ; i++){
		for (int j = 1 ; j <= K ; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}
main() {
	srand (time(NULL));
	matrix A (K+1, vector<ll> (K+1));
	for (int i = 1 ; i <= K ; i++) {
		for (int j = 1 ; j <= K ; j++) 
//			 A[i][j] = rand() % 100 + 1 ;
			cin >> A[i][j] ;
	}
	clock_t tStart = clock();
	matrix B = expo (A, 9);
	cout << "\nTime taken :" << (double) (clock() - tStart)/CLOCKS_PER_SEC ; 
	disp (B); 
}*/
#include <iostream>
#include <vector>
#include <cstdio>
#define REP(i,limit) for(int i = 1 ; i <= limit - 1 ; i++)
#define ULL unsigned long long int
using namespace std;
const ULL MOD = 1000000007;
typedef vector<vector<ULL> > matrix;

matrix mul (matrix A, matrix B) {
	matrix C(A.size(),vector<ULL> (B[0].size(),0));
	REP(i,A[0].size()){
		REP(j,B[0].size()){
			REP(k,B.size()){
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;	
			}
		}
	}
	return C;
}

matrix expo (matrix num, ULL pow) {
	if (pow == 1) return num;
	if (pow == 2) return mul (num,num);
	else if (!(pow & 1)){
		matrix result = expo (num, pow - 1);
		return mul (result,result);
	}
	else
		return mul (num, expo(num, pow >> 1));
}

main () {
//	Compute the T matrix and F matrix first .
// f(1) = 0 AND f(2) = 1
	matrix T (4,vector<ULL> (4,0));
	T[1][1] = T[1][2] = T[2][3] = T[3][2] = 1;
	
	vector<ULL> F(4,0); F[3] = 1;
	ULL t,val1, val2;
//	cin >> t;
//	while (t--)
	 {
		cin >> val1 >> val2;
		val1++;val2++;
		bool flag = 0;
		ULL ans1 = 0, ans2 = 0;
		if (val1 == 1 && val2 == 1)
			cout << endl << 0;
		else if (val1 == val2)
			cout << endl << 0;
		else {
			if (val1 == 1)
				{ans1 = 0;flag = 1;}
			else{
				matrix Tval2 = expo(T,val2);
				for (int i = 1 ; i <= 3 ;i++)
					ans2 = (ans2 + Tval2[1][i] * F[i])%MOD;
				if (!flag)
					cout << ans2;
				else {
					matrix Tval1 = expo(T,val1-1);
					for (int i = 1 ; i <= 3 ; i++)
						ans1 = (ans1 + Tval1[1][i] * F[i])%MOD;
					cout << endl << (ans2 - ans1)%MOD;				
				}				
			}			
		}		
	}
}






















