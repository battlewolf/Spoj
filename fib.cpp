using namespace std;
#include <iostream>
#include <vector>
#define REP(i, n) for(int i = 0; i < n; ++i)
#define MOD 100000007
typedef long long int ll;
typedef vector<vector<ll> > Matrix;

Matrix mul (Matrix A, Matrix B) 
{
	Matrix C(A.size(), vector<ll> (A.size(), 0));
	REP(i, A.size())
		REP(j, A[0].size())
			REP(k, B[0].size())
				C[i][j] += A[i][k] * B[k][j];
	return C;
}

Matrix pow (Matrix N, int p)
{
	if(p == 1) return N;
	else if(p == 2) return mul(N, N);
	else
	{
		if(p % 2 == 1)
			return mul(N, pow(N, p - 1) ) ;
		else
		{
			Matrix res = pow(N, p / 2);
			return mul(res, res);
		}
	}
}

ll fib(ll N) {
	vector<ll> F1(2);
	F1[0] = F1[1] = 1;


	//create T matrix
	Matrix T(2 , vector<ll> (2 , 0) );
	T[0][0] = 0; T[0][1] = 1;
	T[1][0] = 1; T[1][1] = 1;
	if(N == 1) return 1;
	T = pow(T, N - 1);

	//result in first row of T X F1
	ll res = 0;
	REP(i, 2)
		res = (res + T[0][i] * F1[i]) % MOD;
	return res;
}


