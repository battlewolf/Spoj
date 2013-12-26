#include <queue>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int N;
char graph[2][26][26];
int dirx[] = {1, 0, -1, 0, 0};
int diry[] = {0, 1, 0, -1, 0};
typedef pair < pair < int, int > , int > ppii;

int bfs()
{
	map < pair < pair < int, int > , int > , int > M;
	queue < pair < pair < int, int > , int > > Q;
	Q.push(pair < pair < int, int > , int > ( pair < int, int> (0, 0), 1) );
	M[ ppii ( pair < int, int > ( 0, 0), 0 ) ] = 1;
	while ( ! Q.empty() )
	{
	}
	return -1;
}
main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> N;
		for(int i = 1; i <= N; ++i)
			cin >> graph[0][i];
		for(int i = 1; i <= N; ++i)
			cin >> graph[1][i];

	}
}
