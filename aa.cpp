#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 100000
using namespace std;
typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> pii;
int T, R, C, choc_count, dirx[4] = {1, 0, -1, 0}, diry[4] = {0, 1, 0, -1};
char graph[101][101], seen[101][101];
int state[101][101][10];

bool okay(int i, int j) {
	return i >= 0 && i < R && j >= 0 && j < C && graph[i][j] != '#';
}

int dfs(int i, int j, int choc, int dist) {
	if(graph[i][j] == 'W' && choc == choc_count) return 0;
	state[i][j][choc] = dist;
	int m = MAX, op;
	for(int c = 0; c < 4; c++) {
		int vx = i + dirx[c], vy = j + diry[c];
		if(okay(vx, vy)) {
			if(graph[vy][vy] == 'C')
			{
				if(state[vx][vy][choc] == 0)
					op = 1 + dfs(vx, vy, choc + 1, dist + 1);
			}
			else {
				if(state[vx][vy][choc] == 0)
					op = 1 + dfs(vx, vy, choc, dist + 1);
			}

			m = min(m, op);
		}
		cout << endl << m;
	}
	return m;
}

main() {
	cin >> T;
	while(T--) {
		pair<int, int> start;
		choc_count = 0;
		cin >> R >> C;
		for(int i = 0; i < R; i++) {
			scanf("%s", graph[i]);
			for(int j = 0; j < C; j++) {
				if(graph[i][j] == 'C') choc_count++;
				else if(graph[i][j] == 'T') {
					start.first = i;
					start.second = j;
				}
			}
		}
		memset(state, 0, sizeof state);
		int d = dfs(start.first, start.second, 0, 1);
		cout << endl << d;
	}

}
