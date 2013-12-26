#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#define TR(c,it) for(typeof(c.begin()) it = c.begin(); it != c.end() ; it++)
#define FOR(i,len) for(int i = 0 ; i < len ; i++)
#define ALL(c) c.begin(),c.end()
#define pb push_back
using namespace std;
vector<int> agnes, user;
int dp[2001][2001];
int lcs(int i, int j)
{
	if(i == agnes.size() || j == user.size())
		return 0;
	else if(dp[i][j] != -1)
		return dp[i][j];
	else
	{
		if(agnes[i] == user[j])
			return dp[i][j] = 1 + lcs(i + 1, j + 1);
		else
			return dp[i][j] = max(lcs(i + 1, j), lcs(i, j + 1));
	}
}

main()
{
	int T;
	cin >> T;
	while(T--)
	{
		agnes.clear();
		int temp, first;
		while(cin >> temp, temp)
			agnes.pb(temp);
		int m = -1;
		while(true)
		{
			user.clear();
			cin >> first;
			if(first == 0) break;
			user.pb(first);
			while(cin >> temp, temp)
				user.pb(temp);
			memset(dp, -1, sizeof dp);
			m = max(m, lcs(0, 0));
		}
		cout << m << '\n';
	}
}

