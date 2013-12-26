#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
char grid[11][21][21];
int  R, C, P, state[10][20][20];
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

int xd[5] = {1, 0, -1, 0, 0}, yd[5] = {0, 1, 0, -1, 0};

bool okay(int i, int j, int p)
{
	return i >= 0 && i < R && j >= 0 && j < C && grid[p][i][j] != '1';
}

int bfs()
{
	memset(state, 0, sizeof state);
	queue< pair < pair < int, int > , int> > Q;
	Q.push( pair < pair < int, int > , int > ( pair < int, int > (0, 0), 0));
	state[0][0][0] = 1;

	while( ! Q.empty() )
	{
		pair<int, int> cxy = Q.front().first;
		int p = Q.front().second;
		Q.pop();
		if(cxy.first == R - 1 && cxy.second == C - 1)
			return state[p][cxy.first][cxy.second];
		int ux = cxy.first, uy = cxy.second;
		for(int i = 0; i < 5; ++i)
		{	
			int vx = ux + xd[i], vy = uy + yd[i];
			if(okay (vx, vy, (p + 1) % P))
			{
				if(state[ (p + 1) % P][vx][vy] == 0)
				{
					Q.push( ppi ( pii ( vx, vy ), (p + 1) % P) );
					state[ (p + 1) % P ][vx][vy] = state[p][ux][uy] + 1;
				}
			}
		}
	}
	return -1;
}

main() 
{
	int cas = 1;
	while(cin >> R, cin >> C, cin >> P, R)
	{
		for(int i = 0; i < P; i++)
			for(int j = 0; j < R; j++)
				cin >> grid[i][j];
		int d = bfs();
		if(d == -1)
			printf ("\nCase %d: Luke and Leia cannot escape.", cas);
		else
			printf ("\nCase %d: Luke and Leia can escape in %d steps.", cas, d - 1);
		cas++;
	}
}
