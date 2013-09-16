#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#define MAX 10000002
bool memo[MAX];
int K, L, m, budget;
main()
{
		scanf("%d%d%d",&K,&L,&m);
		memo[0] = 0;
		for(int i = 1; i < MAX; i++)
		{
				if(memo[i - 1] == 0)
						memo[i] = 1;
				else if(i - K >= 0 && memo[i - K] == 0)
						memo[i] = 1;
				else if(i - L >= 0 && memo[i - L] == 0)
						memo[i] = 1;

		}

		while(scanf("%d", &budget) != EOF)
		{
				if(memo[budget]) printf("A");
				else printf("B");

		}

}
