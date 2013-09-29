#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#define FOR(i,end) for(int i = 0; i < end; i++)
using namespace std;
typedef pair<int,int> pii;
int V, E, endnode;

pii dfs ()


void printGraph(vector<vector<node> > &graph) {
	FOR(i, V) {
		for(typeof(graph[i+1].begin()) it = graph[i+1].begin(); it != graph[i+1].end(); it++) {
			node N = *it;
			cout << N.vertex << N.cost << " ";
		}
		cout << endl;
	}
}


main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &V);
		E = V - 1;
		vector<vector<pii> > graph(V+1);
		bool seen[V+1];
		FOR(i,E) {
			int vertex1, vertex2, cost;
			scanf("%d%d%d", &vertex1, &vertex2, &cost);
			graph[vertex1].push_back(pii (vertex2, cost));
			graph[vertex2].push_back(pii (vertex1, cost));
		}
		memset(seen, 0, sizeof(seen));
		
		
//		printGraph(graph);			
	}
}
