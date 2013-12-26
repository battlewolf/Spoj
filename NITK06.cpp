#include <cstdio>
using namespace std;
int arr[10000];
main() {
	int T, N;
	scanf(" %d ", &T);
	while(T--) {
		scanf(" %d ", &N);	
		for(int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		if(N == 2 && arr[0] != arr[1]) {
			printf("NO\n");
			continue;
		}
		for(int i = 0; i < N-1; ++i) {
			if(arr[i] > arr[i+1])	break;
			else {
				arr[i+1] = arr[i+1] - arr[i];
				arr[i] = 0;
			}
		}
		if(arr[N-1] == 0) printf("YES\n");
		else printf("NO\n");
	}
}
