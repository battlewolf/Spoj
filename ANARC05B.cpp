#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int arr1[10000], arr2[10000], n1, n2;
int dp[10000][2];
int solve(int index, bool pos)
{
	if( ( pos == 0 && index == n1 ) || ( pos == 1 && index == n2 ) )
		return 0;
	else if(dp[index][pos] != -1)
		return dp[index][pos];
	else
	{
		int op1, op2;
		op1 = op2 = 0;
		if(arr1[index] == arr2[index])
			op1 = arr1[index] + solve(index + 1, pos ^ 1); //hopping
		else if(pos == 0)
			op2 = arr1[index] + solve(index + 1, pos);
		else if(pos == 1)
			op2 = arr2[index] + solve(index + 1, pos);
		return dp[index][pos] = max(op1, op2);
	}
}

main()
{
	while(cin >> n1, n1)
	{
		for(int i = 0; i < n1; ++i)
			scanf("%d", &arr1[i]);
		cin >> n2;
		for(int i = 0; i < n2; ++i)
			scanf("%d", &arr2[i]);
		memset(dp, -1, sizeof dp);
		printf(" %d ", max(solve(0, 0), solve(0, 1)));
		for(int i = 0; i < n1; i++)
			cout << endl << dp[i][0];

	}
}
