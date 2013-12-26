#include <cstdio>
#include <algorithm>
using namespace std;
int arr[1000000];

main() {
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T;i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + T);
	for(int i = 0; i < T; i++)
		printf("%d\n", arr[i]);
}
