#include <iostream>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int> > V(16);
int seen[1<<16];
void init() {
#define pb push_back
	V[1].pb(2);
	V[1].pb(3);
	V[1].pb(5);
	V[1].pb(9);
	V[2].pb(6);
	V[2].pb(10);
	V[2].pb(4);
	V[3].pb(7);
	V[3].pb(11);
	V[3].pb(4);
	V[4].pb(8);
	V[4].pb(12);
	V[5].pb(6);
	V[5].pb(13);
	V[5].pb(7);
	V[6].pb(14);
	V[6].pb(8);
	V[7].pb(15);
	V[7].pb(8);
	V[8].pb(16);
	V[9].pb(13);
	V[9].pb(10);
	V[9].pb(11);
	V[10].pb(12);
	V[10].pb(14);
	V[11].pb(15);
	V[11].pb(12);
	V[12].pb(16);
	V[13].pb(14);
	V[13].pb(15);
	V[14].pb(16);
	V[15].pb(16);
}

bool check(int i, int j, int num) {
	i--;
	j--;
	return ( ( ! ( ( 1 << i ) & num) && ( ( 1 << j ) & num) ) || ( ( ( 1 << i ) & num ) && ! ( ( 1 << j ) & num ) ) );
}

void bfs(int start) {
	queue<int> Q;
	Q.push(start);
	seen[start] = 0;
	while(!Q.empty())
	{
		int see = Q.front(), put;
		Q.pop();
		for(int i = 1; i <= 15; i++)
		{
			for(int j = 0; j < V[i].size(); j++)
			{
				if( check(i, V[i][j], see) ) 
				{
					put = see;
					put ^= ( 1 << ( i - 1 ) ) ;
					put ^= ( 1 << ( V[i][j] - 1 ) );
					if(seen[put] == -1)
					{
						if(seen[see] + 1 == 4) return;
						seen[put] = seen[see] + 1;
						Q.push(put);
					}
				}
			}
		}
	}
}

main() {
	
	int T, state;
	bool num;
	init();
	memset(seen, 0xff, sizeof seen);
	bfs(0xff00);
	cin >> T;
	for(int j = 1; j <= T; j++) {
		state = 0;
		for(int i = 0; i <= 15; i++) if(cin >> num, num) state |= (1 << i);
		(seen[state] == -1) ? cout << "Case #" << j << ": more\n" : cout << "Case #" << j << ": " << seen[state] << '\n';
	}
}

