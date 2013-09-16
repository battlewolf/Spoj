#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>

/* Templates*/
#define INF 1<<32
#define PI 3.141592653589793
#define AND &&
#define OR || 
#define NOT !
#define all(c) c.begin(),c.end()
#define present(container, element) (container.find(element) != container.end()) 
#define cpresent(container, element) (find(all(container),element) != container.end())
#define ins insert
#define sz size
#define pb push_back
#define pp pop
#define v(data) vector<data>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vs vector<string>
#define mp make_pair()
#define pi pair<int, int>
#define vpi v(pi)
#define matrix(data) vector<vector<data> > 
#define FOR(i,end,begin) for(int i=start; i <= end; i++)
#define TR(c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define REP(i,end) for(int i = 0 ; i < end; i++)
#define MAX 1000
using namespace std;
int dist[8][8], x, y, dx, dy;
bool seen[8][8];
int X[] = {-1, +1, -1, +1, -2, +2, -2, +2};
int Y[] = {+2, +2, -2, -2, +1, +1, -1, -1};
bool ok(int i, int j)
{
		return (i >= 0 && i <= 7 && j >= 0 && j <= 7);
}

void bfs(int r, int c)
{
		memset(seen , 0, sizeof(seen));
		queue<pi> Q;
		Q.push(pair<int,int> (r,c));
		dist[r][c] = 0;
		while(!Q.empty())
		{
				pi P = Q.front();
				seen[P.first][P.second] = 1;
				r = P.first;
				c = P.second;
				Q.pop();
				for(int i = 0; i < 8; i++)
				{
						int tx, ty;
						tx = r + X[i];
						ty = c + Y[i];
						if(ok(tx,ty) && !seen[tx][ty])
						{
								dist[tx][ty] = 1 + dist[r][c];
								Q.push(pair<int,int> (tx,ty));
						}
				}
		}
		printf("\n%d",dist[dx][dy]);
}	

main()
{
		char s1[3];
		char s2[3];
		int T;
		scanf("%d",&T);
		while(T--){
				scanf("%s",s1);
				scanf("%s",s2);
				x = s1[0] % 97;
				y = atoi(&s1[1]) - 1;
				dx = s2[0] % 97;
				dy = atoi(&s2[1]) - 1;
				bfs(x,y);
		}
}

