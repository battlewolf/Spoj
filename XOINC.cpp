#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 2000
int N, input[MAX + 1], dp[MAX + 1][MAX + 1];

// I code for fun
/*
int doIt(int index, int multiplier)
{
	if(index >= N) return 0;
	int &ret = dp[index][multiplier];
	if(ret == -1)
	{
		for(int consider = 1; consider <= multiplier * 2; consider ++ )
		{
			int coins = 0, ccount = 1;
			for(int i = index; ccount <= consider && i < N; ccount++, i++)
				coins += input[i];
			//skipping for the 2nd-opponent
			for(int i = 1; i <= consider * 2; i++)
				ret = max(ret, coins + doIt(index + consider + i, i));
		}
	}
	return ret;
}*/








main()
{
	cin >> N;
	for(int i = 0; i < N; ++i) cin >> input[i];
	
	memset(dp, -1, sizeof dp);
	cout << doIt(0, 1) << '\n';
}
