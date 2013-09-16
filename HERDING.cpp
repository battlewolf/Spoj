#include <vector>
#include <list>
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

/*Templates*/
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

bool visited[MAX][MAX];
int row, column;
char input[MAX][MAX+1];
set<pair<int, int> > S;

int recurse(int r, int c) {
	if(visited[r][c] == true && S.find(pi (r,c)) != S.end())
		return 1;
	else if(visited[r][c] == true)
		return 0;
	else {
		visited[r][c] = true;
		S.ins(pi (r,c));
		if(input[r][c] == 'N')
			return recurse(r-1, c);
		else if(input[r][c] == 'E')
			return recurse(r, c+1);
		else if(input[r][c] == 'W')
			return recurse(r, c-1);
		else
			return recurse(r+1, c);
	}
}

main() {
	memset(visited, 0, sizeof(visited));
	pi p;
	scanf("%d%d",&row,&column);
	
	
	int sum = 0;
	for(int i = 0 ; i < row; i++) {
		scanf("%s",input[i]);	
	}
	
	for(int i = 0; i < row; i++) {
		for(int j = 0 ; j < column; j++) {
			if(!visited[i][j]){
				sum += recurse(i,j);
				S.clear();
			}
		}
	}
		
	printf("\n%d",sum);

}
























