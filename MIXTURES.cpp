//double dp 
#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>
#define INF 1<<25
using namespace std;
int input[101], N, dp[101][101], s[101][101];

int sum(int a, int b)
{
	if(a == b) return input[a];
	else if(s[a][b] != -1) return s[a][b];
	else
		return s[a][b] = (sum(a, b - 1) + input[b]) % 100;
}

int f(int i, int j)
{
	if(i == j) return 0; // one mixture and the smoke that comes is just zero, right? 
	else if(dp[i][j] != -1) return dp[i][j];	
	else
	{
		//chose a suitable 'k' splitting point in the array 
		int m = INF, comp;
		for(int k = i; k < j; k++)
		{
			comp = f(i, k) + f(k + 1, j) + ( sum(i, k) * sum(k + 1, j) ) ;
			m = min(m, comp);
		}
		return dp[i][j] = m;
	}	
}

main()
{
	while(scanf("%d", &N) == 1) {
		for(int i = 0; i < N; i++) cin >> input[i];
		memset(dp, -1, sizeof(dp));
		memset(s, -1, sizeof(s));
		cout  << f(0, N - 1) << "\n";
	}		
}
