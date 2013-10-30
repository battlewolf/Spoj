//double dp 
#include <string.h>
#include <stdio.h>
#define INF 1<<25
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
		int m = INF, comp, k;
		for(k = i; k < j; k++)
		{
			comp = f(i, k) + f(k + 1, j) + ( sum(i, k) * sum(k + 1, j) ) ;
			m = m > comp ? comp : m;
		}
		return dp[i][j] = m;
	}	
}

main()
{
	while(scanf("%d", &N) == 1) {
		int i;
		for(i = 0; i < N; i++) scanf("%d", &input[i]);
		memset(dp, -1, sizeof(dp));
		memset(s, -1, sizeof(s));
		printf("%d\n", f(0, N-1));
	}		
}
