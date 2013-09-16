#include <cstdio>
#include <cstring>
#define ll long long 
using namespace std;
ll len;
ll dp[5005];
char str[5005];
ll solve (int i)
{
	if (i >= len) return 1;
	if (dp[i]) return dp[i];
	if (str[i]=='0') return 0;
	ll m1 = 0,m2 = 0;
	m1 = m1 + solve (i+1);
	if (i+1 < len && str[i]>'0' && 10 * (str[i] - '0') + (str[i+1] - '0') <= 26) m2 = m2 + solve (i+2);
	return (dp[i] = (m1+m2));
}

main() {
	while (1) {
		scanf("%s",str);
		len = strlen(str);
		if (str[0]=='0')break;
		memset(dp,0,sizeof(dp));
		printf ("\n%lld",solve(0));
	}
	
}
