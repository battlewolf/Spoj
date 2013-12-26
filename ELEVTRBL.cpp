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

ll floors, start, goal, up, down;

ll bfs() {
	queue<ll> Q;
	ll u, v, d;
	Q.push(start); ll build[floors + 1];
	memset(build, -1, sizeof build);
	build[start] = 0;
	while(!Q.empty()) {
		u = Q.front();
		Q.pop();
		if(u == goal) return build[u];
		if(u + up <= floors && build[u+up] == -1) {
			Q.push(u + up);
			build[u + up] = build[u] + 1;
		}if(u - down >= 1 && build[u-down] == -1) {
			Q.push(u - down);
			build[u - down] = build[u] + 1;
		}
	}
	return -1;
}

main() {
	ll d;
	cin >> floors >> start >> goal >> up >> down;
	if((up == 0 && down == 0 && start != goal) || (up == 0 && goal > start) || (down == 0 && goal < start) ) cout << "use the stairs\n";
	else if((d = bfs()) == -1) cout << "use the stairs\n";
	else cout << d << '\n';
}



