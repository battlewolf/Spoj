#include <stdio.h>
#include <string.h>

int floors, start, goal, up, down;
int distances[1000001], queue[1000001];
int bfs() {
	int sptr, eptr, u;
	sptr = eptr = floors - 1;
	distances[start] = 1;
	queue[sptr] = start;
	sptr--;
	while( sptr != eptr  ) {
		u = queue[eptr]; eptr--;
		if( u == goal ) return distances[u] - 1;
		if( u + up <= floors && distances[u + up] == 0) {
			distances[u + up] = distances[u] + 1;
			queue[sptr] = u + up;
			sptr--;
		}
		if( u - down >= 1 && distances[u - down] == 0) {
			distances[u - down] = distances[u] + 1;
			queue[sptr] = u - down;
			sptr--;
		}
	}
	return -1;
}
int 
main() {
	int d;
	scanf("%d %d %d %d %d", &floors, &start, &goal, &up, &down);
	memset(distances, 0,  sizeof(int) * floors );
	if( (up == 0 && down == 0 && start != goal) || (up == 0 && goal > start) || (down == 0 && goal < start) ) 
		printf("use the stairs\n");

	else if(( d = bfs()) == -1) printf("use the stairs\n");
	else printf("%d\n", d);
	return 0;
}
