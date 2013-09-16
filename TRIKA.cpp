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
main()
{
		int M,N,X,Y,input[MAX][MAX];
		memset(input,9999,sizeof(input));
		scanf("%d%d%d%d",&M,&N,&X,&Y);
		input[M-1][N] = 0;
		REP(i,M) REP(j,N) scanf("%d",&input[i][j]);
		for(int i = M-1; i >= X-1; i--)
		{
				for(int j = N-1; j >= Y-1; j--)
				{


						if(i == X-1 && j == Y-1)
						{
								int var = input[X-1][Y-1] - min(input[X][Y-1],input[X-1][Y]);
								if(var < 0) printf("N");
								else printf("\nY %d",var);
								break;
						}

						input[i][j] = min(input[i][j] + input[i+1][j], input[i][j] + input[i][j+1]);

				}
		}

}
