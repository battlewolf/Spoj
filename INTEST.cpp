#include <cstdio>
using namespace std;


main() {
	int T, num, div, count = 0;
	scanf("%d %d", &T, &num);
	while(T--)
	{
		scanf("%d", &div);
		if(div % num == 0) count++;
	}
	printf("%d\n", count);
}
