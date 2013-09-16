/*
 	User : Vinay
	Institution : CEG 
	Date : 31.05.13
	Method : DP
*/
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll unsigned long long int
#define all(c) c.begin(),c.end()
#define TR(c,it) for(typeof(c.begin()) it = c.begin() ; it != c.end() ; it++)
using namespace std;
ll N;
vector<ll> vi;
ll dp[1024][1024] ;
ll solve (ll i, ll j) {
	if ( i > j ) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	else {
		ll strat1, strat2;
		strat1 = strat2 = 0;
		strat1 = strat1 + vi[i];
		strat2 = strat2 + vi[j];
		if (vi[i+1] >= vi[j])
			strat1 = strat1 + solve (i+2,j);
		else
			strat1 = strat1 + solve (i+1,j-1);
		if (vi[i] >= vi[j-1])
			strat2 = strat2 + solve (i+1,j-1);
		else
			strat2 = strat2 + solve (i,j-2);	
		dp[i][j] = max(strat1, strat2);
		return dp[i][j]; 
		
	}
}
main () {
	N = 1;
	ll play = 1;
	while (1) {
		ll sum = 0;
		cin >> N;
		if (N == 0)break;
		vi.resize(N);
		memset (dp, -1, sizeof(dp));
		for (ll i = 0; i < N ; i++) {
			cin >> vi[i];
			sum = sum + vi[i];
		}
		ll val1 = solve (0, N-1);
		cout << endl <<  "In game "<< play <<", the greedy strategy might lose by as many as "<< 2 * val1 - sum<<" points.";	
		play++;		
	}
}
