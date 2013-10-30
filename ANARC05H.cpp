#include <cstdio>
#include <cstring>
using namespace std;
char num[33]; int len, dp[1024][1024];
int f(int p, int ps) {
	if(p == len) return 1;
	else if(dp[p][ps] != -1) return dp[p][ps];
	else {
		int sum = 0, c = 0;
		for(int i = p; i < len; i++) {
			sum = sum + num[i] - '0';
			if(sum >= ps)
				c = c + f(i + 1, sum);
		}	
		return dp[p][ps] = c;
	}
}
main() {
	int t = 1;
	while(scanf("%s", num) == 1 && (num[0] >= '0' && num[0] <= '9'))
	{
		memset(dp, -1, sizeof(dp));
		len = strlen(num);
		printf("%d. %d\n", t++, f(0, 0));
	}
}
