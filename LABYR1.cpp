#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#define REP(i,size,start) for(int i = start ; i < size ; i++)
using namespace std;
typedef pair<int,int> pi;
char input[1000][1000];

const int xd[8] = {0, 0, -1, +1, -1, +1, -1, +1};
const int yd[8] = {+1, -1, 0, 0, -1, -1, +1, +1};

int BFS(pi A)
{
	int d = 0;
	queue<pi> Q;
	Q.push(A);
	while(!Q.empty())
	{
		
	}
}

main()
{
	int T,C,R;
	cin >> T;
	while(T--)
	{
		cin >> C >> R;
		
	}
}
