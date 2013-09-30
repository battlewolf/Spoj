#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
char graph[21][21];
int dist[21][21], xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};

void BFS(int &M, int &N) {
	int startx = -1, starty = -1;
	for(int i = 0; i < M; i++)
		if(i == 0 || i == M - 1)
			for(int j = 0; j < N; j++)
				if(graph[i][j] == '.') {
					startx = i;
					starty = j;
				}
		else 
			for(int j = 0; j < M; j = j + (M-1))
				if(graph[i][j] == '.') {
					startx = i;
					starty = j;
				}
	if(startx == -1 && starty == -1) {
		printf("Invalid\n");
		return;
	}
	queue<pair<int, int> > Q;
	Q.push(pair<int, int> (startx, starty));
	dist[startx][starty] = 1;
	while(!Q.empty()) {
		int x = Q.front().first, y = Q.front().second; Q.pop();
		dist[x][y] = 1;
		for(int i = 0; i < 4; i++) {
			if(!dist[x + xd[i]][y + yd[i]] && graph[x + xd[i]][y + yd[i]] != '#')
				Q.push(pair<int, int> (x+xd[i], y+yd[i]));
		}
		
	}	
}

main() {
	int T, M, N;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &M, &N);
		for(int i = 0; i < M; i++)
			scanf("%s", graph[i]);
		memset(dist, -1, sizeof(dist));
		BFS(M, N);		
	}
}
