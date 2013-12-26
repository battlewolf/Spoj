#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 1000
#define int long long int
#define MOD 2147483647
#define REP(i, end) for(int i = 0; i < end; ++i)

int dp[MAX + 1][MAX + 1], N;
char grid[MAX + 1][MAX + 1];
bool seen[MAX + 1][MAX + 1];
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};


inline bool ok(int r, int c)
{
	return r >= 0 && r < N && c >= 0 && c < N && grid[r][c] == '.' ;
}

bool bfs()
{
	queue<pair<int, int> > Q;
	Q.push( pair<int, int> (0, 0) );
	seen[0][0] = true;
	while( !Q.empty() )
	{
		int x = Q.front().first, y = Q.front().second;
		Q.pop();
		if(x == N - 1 && y == N - 1)
			return true;
		REP(i, 4)
		{
			int vx = x + dirx[i], vy = y + diry[i];
			if(ok(vx, vy) && !seen[vx][vy])
			{
				seen[vx][vy] = true;
				Q.push(pair<int,int> (vx, vy));
			}
		}
	}
	return false;
}


main(void)
{
	cin >> N;
	REP(i, N)
	{
		REP(j, N)
			cin >> grid[i][j], dp[i][j] = -1, seen[i][j] = false;
		grid[i][N] = '\0';
	}
	dp[N - 1][N - 1] = 1;
	for(int i = N - 1; i >= 0; i--)
	{
		for(int j = N - 1; j >= 0; j--)
		{
			if(grid[i][j] != '#' && !(i == N - 1 && j == N - 1))
			{
				int op1 = 0, op2 = 0;
				if(ok(i + 1, j) && dp[i + 1][j] != -1) op1 = dp[i + 1][j], op1 = op1 > MOD ? op1 % MOD : op1;
				if(ok(i, j + 1) && dp[i][j + 1] != -1) op2 = dp[i][j + 1], op2 = op2 > MOD ? op2 % MOD : op2;
				dp[i][j] = ( (op1 + op2) > MOD ) ? (op1 + op2) % MOD : (op1 + op2);
			}
		}
	}
/*	REP(i, N)
	{
		cout << endl;
		REP(j, N)
			cout << dp[i][j] << ' ';
	}*/
	int d = dp[0][0];

	if(d > 0)
		cout << d << '\n';
	else if(d <= 0)
	{
		bool reach = bfs();
		if(reach == true)
			cout << "THE GAME IS A LIE\n";
		else
			cout << "INCONCEIVABLE\n";  
	}
}
