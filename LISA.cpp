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
#define TR(c,it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define REP(i,end) for(int i = 0 ; i < end; i++)
#define MAX 1000
#define con(c) atoi(c)
using namespace std;

char input[] = "1+2*3+4";
int n = sizeof(input) / sizeof(char);
int arr[4];

int solve(int i, int j)
{
	if (i == j)
		return arr[i];
	else
	{
		int m = 9999;
		for(int cut = i+1; cut <= j; cut++)
		{
			int expr = solve(i,cut) + solve(cut, j);
			if() 
		}
	}		
}
main()
{
	int M[MAX][MAX];
	int n = sizeof(input) / sizeof(char);
	for(int i = 0,j = 0 ; i < 4; i++,j+=2)
		arr[i] = atoi(&input[j]);
	
	printf("\n%d",solve(0,3));
}
