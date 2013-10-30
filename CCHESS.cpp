/*BFS*/
#define pi pair<int,int> 
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define INF 1<<32
using namespace std;
int X[] = {-1, +1, -1, +1, -2, +2, -2, +2};
int Y[] = {+2, +2, -2, -2, +1, +1, -1, -1};
/*
 *int store[9][9], x, y, dx, dy;
 *bool ok(int i, int j)
 *{
 *    return (i >= 1 && i <= 8 && j >=1 && j <=8);
 *}
 *void dfs(int i, int j)
 *{
 *    cout << endl << " i " << i << " j " << j;
 *    if( ok(i,j) && !(i == dx && j == dy))
 *    {
 *        for(int c = 0; c < 8; c++)
 *        {
 *            int tx = i + X[c], ty = j + Y[c];
 *            if(ok (tx, ty) && store[tx][ty] == 9999)
 *            {
 *                int var = store[i][j] + i * tx + j * ty;
 *                store[tx][ty] = min(var, store[tx][ty]);
 *                dfs(tx, ty);
 *            }
 *        }
 *
 *    }
 *
 *}
 *
 *
 *main() {
 *        while (scanf("%d%d%d%d",&x, &y, &dx, &dy) != EOF)
 *        {
 *                memset(store, 9999, sizeof store);
 *
 *                store[x][y] = 0;
 *                dfs(x, y);
 *                for(int i = 1; i < 9; i++)
 *                {
 *                    for(int j = 1; j < 9 ; j++)
 *                        printf("%d ",store[i][j]);
 *                    printf("\n");
 *                }
 *        }
 *}
 */
bool seen[8][8];
int dist[8][8];
int x, y, dx, dy;

bool ok(int i, int j) {
		return (i >= 0 && i <= 7 && j >= 0 && j <= 7);		
}

void bfs(int i, int j) {
		memset(seen, 0, sizeof seen);
		memset(dist, 999999, sizeof dist);
		queue<pair<int,int> > Q;
		seen[i][j] = true;
		dist[i][j] = 0;
		Q.push(pair<int,int> (i, j));

		while(!Q.empty()) {
				pi P = Q.front();

				i = P.first;
				j = P.second;
				seen[P.first][P.second] = true;
				/*
				 *                if(i == dx && j == dy)
				 *                        break;
				 *
				 */
				Q.pop();

				for(int c = 0; c < 8; c++) {
						int tx = i + X[c], ty = j + Y[c];
						if(ok(tx, ty))
						{
								if(!seen[tx][ty]){	
										Q.push(pair<int,int> (tx,ty));
										dist[tx][ty] = min(dist[tx][ty],dist[i][j] + ((i * tx )+ (j * ty)));
								}
						}
				}
		}
		if(!seen[dx][dy]) {
			printf("\n-1");
			return;
		}
		printf("\n%d",dist[dx][dy]);
/*		for(int i = 0 ; i < 8 ; i++)
		{
			cout << endl ;
			for(int j = 0 ; j < 8 ; j++)
				cout << dist[i][j] << " ";
		}
*/
}
main()
{
		while(scanf("%d",&x) != EOF)
		{
			scanf("%d%d%d",&y,&dx,&dy);
			bfs(x,y);	
		}
}










