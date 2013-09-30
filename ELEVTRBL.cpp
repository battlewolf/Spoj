#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int floors, start, goal, up, down;

int bfs() {
	queue<pair<int, int> > Q; // the floor number and the distance as a pair
	Q.push(pair<int, int> (start, 0));
	bool seen[floors+1]; memset(seen, 0, sizeof(seen));
	int f, d;
	while(!Q.empty()) {
		f = Q.front().first; d = Q.front().second;
		Q.pop();
		if(f == goal) return d;
		seen[f] = 1;
		if(f + up <= floors && !seen[f + up]) 
			Q.push(pair<int, int> (f + up, d + 1));
		if(f - down >= 0 && !seen[f - down])
			Q.push(pair<int, int> (f - down, d + 1));
	}
	return -1;
}

main() {
	int d;
	scanf("%d %d %d %d %d", &floors, &start, &goal, &up, &down);
	if((d = bfs()) == -1) printf("use the stairs\n");
	else printf("%d\n", d);	
}
