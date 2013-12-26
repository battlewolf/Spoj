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
int N, T, time[50][50], toll[50][50];
typedef pair<int, int> pii;
typedef vector<vector<pii> > vvp;
pii doIt(int curr, int time_left, vvp &memo)
{
	if(time_left < 0) return pii (INF, INF);
	if(curr == N - 1) return pii (0, 0);
	if(memo[curr][time_left].first != -1)
		return memo[curr][time_left];
	pii ret (INF, INF);

}


main()
{
	while(cin >> N >> T, N)
	{
		REP(i, N)
			REP(j, N)
				cin >> time[i][j];
		REP(i, N)
			REP(j, N)
				cin >> toll[i][j];
		vector<vector<pii> > memo(N, vector<pii> (T, pii(-1, -1)));
	}
}
