//BFS
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<cmath>
#define FORIT(c,it) for(typeof(c.begin()) it = c.begin(); it != c.end() ; it++)
#define REP(i,size) for(int i = 0 ; i < size ; i++)
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define INF 1<<30 //infinity??
#define MAX 183
using namespace std;
typedef pair<int,int> pi;

char grid[MAX][MAX];
int graph[MAX][MAX];
const int xd[8] = {0, 0, -1, +1, -1, +1, -1, +1};
const int yd[8] = {+1, -1, 0, 0, -1, -1, +1, +1};
int T, R, C;

bool okay (int x,int y)
{
	return (x>=0 && x<R && y>=0 && y<C);
}

void bfs(pi A)
{
	queue<pair<int,int> > Q;
	Q.push(A);
	while(!Q.empty())
	{
		pi p = Q.front();
		Q.pop();
		//now look for the adjacent nodes
		REP(i,8)
		{
			if (okay(p.first+xd[i],p.second+yd[i]))
			{
				int d = abs(p.first + xd[i] - A.first) + abs(p.second +yd[i] - A.second );
				if (d < graph[p.first+xd[i]][p.second+yd[i]])
				{
					graph[p.first+xd[i]][p.second+yd[i]] = d;
					Q.push(pair<int,int>(p.first+xd[i],p.second+yd[i]));
				}				
				
			}
		}
	}
}

main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&R,&C);
		REP(i,R) scanf("%s",grid[i]);
		
		//Filling the graph now for the 'BFS' algorithm
		REP(i,R)
			REP(j,C)
				if(grid[i][j]=='1') graph[i][j] = 0;
				else graph[i][j] = INF;
		REP(i,R)
			REP(j,C)
				if(grid[i][j] == '1')
					bfs(pair<int,int>(i,j));
		printf("\n");
		REP(i,R)
		{
			REP(j,C)
				printf("%d ",graph[i][j]);
			printf("\n");
		}				
	}
}

