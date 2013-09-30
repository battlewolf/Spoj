#include <queue>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>
#define MAX 2001
using namespace std;
int colors[MAX+1], V, E;
map<int, int> M;

int bfs(vector<vector<int> > &graph, int start) {
	int u, c, v;
	colors[start] = 1;
	queue<int> Q;
	Q.push(start);
	while(!Q.empty()) {
		u = Q.front(); c = colors[u]; Q.pop();
		int n = graph[u].size();
		for(int j = 0; j < n; j++) {
			v = graph[u][j];
			if(colors[v] == c) return -1;
			else if(colors[v] == 0) {
				colors[v] = M[c];
				Q.push(v);				
			}				
		}
	}
	return 1;
}

main() {
	M[1] = 2;
	M[2] = 1;
	bool f;
	int T, u, v;
	scanf("%d", &T);
	for(int counter = 1; counter <= T; counter++) {
		f = 1;
		scanf("%d %d", &V, &E);
		vector<vector<int> > graph(V+1);
		for(int i = 0; i <= V; i++) colors[i] = 0;
		for(int i = 1; i <= E; i++) {
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
			graph[v].push_back(u);			
		}				
		for(int i = 1; i <= V; i++) {
			if(colors[i]==0) {
				if(bfs(graph, i) == -1)	{
					printf("Scenario #%d:\nSuspicious bugs found!\n", counter);
					f = 0;
					break;
				}				
			}			
		}
		if(f)	printf("Scenario #%d:\nNo suspicious bugs found!\n", counter);		
	}
}
