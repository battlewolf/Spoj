#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define FOR(i,start,end) for(int i = start; i <= end; i++)
using namespace std;
int t, N, e;
vector<bool> visited;
vector<vector<int> > graph;
void BFS(int start) {
	visited[start] = 1;
	queue<int> Q;
	Q.push(start);
	while(!Q.empty()) {
		int node = Q.front();
		Q.pop();
		for(typeof(graph[node].begin()) it = graph[node].begin(); it != graph[node].end(); it++) {
			int n = *it;
			if(!visited[n]) {
				visited[n] = 1;
				Q.push(n);
			}
		}
	}
}
main() {
	cin >> t;
	while(t--) {
		cin >> N >> e;
		visited.resize(N, 0);
		graph.resize(N);
		for(int i = 1; i <= e; i++) {
			int node1, node2;
			cin >> node1 >> node2;
			graph[node1].push_back(node2);
			graph[node2].push_back(node1);
		}
		int count = 0;
		for(int i = 0; i <= N-1; i++) {
			if(!visited[i])
			{
				BFS(i);
				count++;
			}
					
		}
		cout << endl << count;
		visited.clear();
		graph.clear();		
	}
}
