#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> pii;
int T, R, C, choc_count, dirx[4] = {1, 0, -1, 0}, diry[4] = {0, 1, 0, -1};
char graph[101][101];
int state[101][101][10];

bool okay(int i, int j) {
	return i >= 0 && i < R && j >= 0 && j < C && graph[i][j] != '#';
}

int BFS(pi &start) {
	memset(state, 0, sizeof state);
	queue<pii> Q;
	state[start.first][start.second][0] = 1;
	Q.push(pii (pair<int, int> (start.first, start.second), 0));
	while(!Q.empty()) {
		
	}
	return -1;
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
		int d = BFS(start);
		if(d == -1) cout << "Mission Failed!\n";
		else cout << d << '\n';
	}

}
