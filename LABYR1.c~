#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char input[1010][1010], seen[1010][1010];
int  maxd, maxr, maxc, R, C, xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};

void dfs(int x, int y, int l) {
	if(l > maxd) {
		maxd = l;
		maxr = x;
		maxc = y;
	}
	seen[x][y] = 1;
	int i;
	for(i = 0; i < 4; i++) 
		if(x + xd[i] >= 0 && x + xd[i] < R && y + yd[i] >= 0 && y + yd[i] < C && seen[x+xd[i]][y+yd[i]] == 0
			&& input[x+xd[i]][y+yd[i]] == '.')
				dfs(x+xd[i], y+yd[i], l + 1);
		

}

main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int i, j;
		scanf("%d %d", &R, &C);
		for( i = 0; i < R; i++) scanf("%s", input[i]);
		for( i = 0; i < R; i++) {
			for( j = 0; j < C; j++) {
				if(input[i][j] == '.') {
					maxd = -1; memset(seen, 0, sizeof(seen));
					dfs(i, j, 0);
					maxd = -1; memset(seen, 0, sizeof(seen));
					dfs(maxr, maxc, 0);
					printf("Maximum rope length is %d.\n", maxd);
					goto fn;	
				}
			}
		}
		fn : ;
	}
}

