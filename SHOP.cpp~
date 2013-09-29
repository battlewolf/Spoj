//djikstra
#include <queue>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#define INF 987654321
using namespace std;
typedef pair<int, int> pii;
int graph[26][26], aux[26][26], R, C, xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1}; 
bool seen[26][26];

bool okay(int i, int j) {
	return i >= 0 && i < R && j >= 0 && j < C && graph[i][j] != -1;
}

void djikstra(pii start, pii end) {
	int we, x, y;
	memset(seen, 0, sizeof(seen));
	seen[start.first][start.second] = 1;
	aux[start.first][start.second] = 0;
	priority_queue<pair<int,pii>, vector<pair<int,pii> >, greater<pair<int, pii> > > Q;
	Q.push(pair<int,pii> (0, pii (start.first, start.second)));
	while(!Q.empty()) {
		we = Q.top().first;
		x = Q.top().second.first;
		y = Q.top().second.second;
		Q.pop();
		seen[x][y] = 1;
		for(int i = 0; i < 4; i++) {
			if(okay(x + xd[i], y + yd[i])) {
				if(!seen[x + xd[i]][y + yd[i]] && we + graph[x+xd[i]][y+yd[i]] <= aux[x+xd[i]][y+yd[i]]) {
					aux[x+xd[i]][y+yd[i]] = we + graph[x+xd[i]][y+yd[i]];
					Q.push(pair<int,pii> (aux[x+xd[i]][y+yd[i]], pii (x+xd[i], y+yd[i])));
				}
			}
		}
		if(x == end.first && y == end.second) break;		
	}
	printf("%d\n", aux[end.first][end.second]);
}

main() {
	while(1) {
		scanf("%d%d", &C, &R);
		int x, y, x1, y1;
		if(R == 0 && C == 0) break;
		string in;
		for(int i = 0; i < R; i++) {
			cin >> in;
			for(int j = 0; j < in.size(); j++) {
				if(in[j] == 'X') graph[i][j] = -1;
				else if(in[j] == 'S') {
					graph[i][j] = 0;
					x = i; y = j;
				}
				else if(in[j] == 'D') {
					graph[i][j] = 0;
					x1 = i; y1 = j;
				}
				else {
					graph[i][j] = in[j] - '0';
				}
				aux[i][j] = INF;
			}
		}
		djikstra(pii (x,y), pii(x1,y1));
					
	}
}
