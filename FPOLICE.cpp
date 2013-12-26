#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <set>
#include <iterator>
#include <vector>
#include <string>

#define INF 1<<20
#define REP(i, end) for(int i = 0; i < end; ++i)
using namespace std;

typedef pair<int, int> pii;
int N, T, times[100][100], risk[100][100];
// risk & time
pii doIt(int curr, int time_left, vector<vector<pii> > &memo)
{
	if(time_left < 0) return make_pair(INF, INF);
	if(curr == N - 1) return make_pair(0, 0);
	if(memo[curr][time_left].first != -1) return memo[curr][time_left];

	pii calc = make_pair(INF, INF);
	for(int i = 0; i < N; ++i)
	{
		if(i != curr)
		{
			pii op = doIt(i, time_left - times[curr][i], memo);
			if(op.first + risk[curr][i] < calc.first)
			{
				calc.first = op.first + risk[curr][i];
				calc.second = op.second + times[curr][i];
			}
		}
	}
	return memo[curr][time_left] = calc;
}

main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> N >> T;
		REP(i, N)
			REP(j, N)
				scanf("%d", &times[i][j]);
		REP(i, N)
			REP(j, N)
				scanf("%d", &risk[i][j]);
		vector<vector<pii> > memo(N, vector<pii> (T + 1, pii ( -1, -1 ) ) );
		pii ans = doIt(0, T, memo);
		cout << ans.first << ' ' << ans.second << '\n';
	}
}


