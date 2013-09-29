//djikstra
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100010
#define ll long long int
#define INF 987654321
#define REP(i,size) for(int i = 0; i < size; i++)
#define TR(c,it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
using namespace std;
typedef pair<int,int> pii;
int V, E, start, end, d[MAX], seen[MAX];
vector<pii> graph[MAX];


void djikstra() {
	int u, v, cost, we;
	for(int i = 0; i <= V; i++) {
		graph[i].clear();
		d[i] = INF;
		seen[i] = 0;
	}
	for(int i = 1; i <= E; i++) {
		scanf("%d %d %d", &u, &v, &cost);
		graph[v].push_back(pii (cost, u));
		graph[u].push_back(pii (cost, v));
	}
	priority_queue<pii, vector<pii>, greater<pii> > Q;
	d[start] = 0;
	Q.push(pii (0, start));
	while ( !Q.empty() ) {
		u = Q.top().second;
		cost = Q.top().first;
		Q.pop();
		seen[u] = 1;
		int s = graph[u].size();
		for(int i = 0; i < s; i++) {
			we = graph[u][i].first;
			v = graph[u][i].second;
			if(!seen[v] && d[v] >= cost + we) {
				d[v] = cost + we;
				Q.push(pii (d[v], v));
			}
		}
		if(u == end) break;	
	}
	d[end] == INF ? printf("NONE\n") : printf("%d\n", d[end]);
}

main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d %d", &V, &E, &start, &end);
		djikstra();
	}
}
