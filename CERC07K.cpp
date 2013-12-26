#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#define REP(i, start, end) for(int i = start; i <= end; i++)
#define TR(c, it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define DEBUG(x) cout << endl << " x : " << x
#define MAX 102
using namespace std;
typedef pair<int, int> pi;
typedef pair< pi, int > pii;
char graph[MAX][MAX];

int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};
int state[102][102][16];
int R, C;
// rgby 
//the state is represented as x-cord, y-cord and a mask

bool inBound(int i, int j) {
	return i >= 0 && i < R && j >= 0 && j < C && graph[i][j] != '#';
}


void BFS(pi &start) {
	queue< pii > Q;
	memset(state, 0, sizeof state);
	Q.push( pii (start, 0) );
	state[start.first][start.second][0] = 1; // starting state
	while(!Q.empty()) {
		pi u = Q.front().first;
		int umask = Q.front().second;
		Q.pop();
		REP(i, 0, 3) {
			int vx = u.first + dirx[i], vy = u.second + diry[i], ux = u.first, uy = u.second, vmask;
			if(inBound(vx, vy)) {
			
				if(graph[vx][vy] == 'X') {
					cout << "Escape possible in "<<state[ux][uy][umask]<<" steps.\n";
					return;
				}
			
				if(graph[vx][vy] >= 'a' && graph[vx][vy] <= 'z'){ // a key
					//add key. It makes sense to add only one key
					switch(graph[vx][vy]) {
						case 'r':
							vmask = umask | 0x8;
							break;
						case 'g':
							vmask = umask | 0x4;
							break;
						case 'b':
							vmask = umask | 0x2;
							break;
						case 'y':
							vmask = umask | 0x1;
							break;
					}
					if(state[vx][vy][vmask] == 0) {//which means we haven't seen this node yet
						Q.push( pii (pi (vx, vy), vmask) ) ;
						state[vx][vy][vmask] = state[ux][uy][umask] + 1;
					}
				}
				else if(graph[vx][vy] >= 'A' && graph[vx][vy] <= 'Z') { // a door
					switch(graph[vx][vy]) {
						cout << endl << "\n door : vx :"<<vx<<" vy : "<<vy<<" vmask: "<<vmask;
						case 'R':
							if((umask & 0x8)&&state[vx][vy][umask]==0) { // the key for the red door is with the user
								Q.push( pii (pi (vx, vy), umask) );
								state[vx][vy][umask] = state[ux][uy][umask] + 1;
							}break;
						case 'G':
							if((umask & 0x4)&&state[vx][vy][umask]==0) {
								Q.push( pii (pi (vx, vy), umask) );
								state[vx][vy][umask] = state[ux][uy][umask] + 1;
							}break;
						case 'B':
							if((umask & 0x2)&&state[vx][vy][umask]==0) {
								Q.push( pii (pi (vx, vy), umask) );
								state[vx][vy][umask] = state[ux][uy][umask] + 1;
							}break;
						case 'Y':
							if((umask & 0x1)&&state[vx][vy][umask]==0) {
								Q.push( pii (pi (vx, vy), umask) );
								state[vx][vy][umask] = state[ux][uy][umask] + 1;
							}

					}
				}
				else if((graph[vx][vy] == '.' || graph[vx][vy] == '*') && state[vx][vy][umask]==0) {
					Q.push( pii (pi (vx, vy), umask) );
					state[vx][vy][umask] = state[ux][uy][umask] + 1;
				}
			}
					
		}

	}
	cout << "The poor student is trapped!\n";
}


main() {
	while(1) {
		cin >> R >> C;
		if( R == 0 &&  C == 0 ) break;
		pair<int, int> start;
		bool f = 0;
		REP(i, 0, R - 1) {
			cin >> graph[i];
			if(!f) {
				REP(j, 0, C - 1)
					if(graph[i][j] == '*') {
						start.first = i;
						start.second = j;
						f = 1;
					}
			}
		}
		BFS(start);
	}	
}
