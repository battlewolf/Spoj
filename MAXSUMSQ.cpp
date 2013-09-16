#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#define i64 long long int
#define INF 1<<30
#define REP(i,size,a) for(int i=a;i<size;i++)
#define ll long long int
using namespace std;
//const int INF = 0x3f3f3f3f;
const double EPS = 1e-10;
const int MAX = 100001;

int a[MAX];

int main() {
	int t, i, n, maxsum, sum, mn;
	i64 cnt, rct;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) scanf("%d", &a[i]);
		maxsum = -INF;
		sum = mn = rct = 0;
		cnt = 1;
		for(i = 0; i < n; i++) {
			sum += a[i];
			if(sum - mn > maxsum) {
				maxsum = sum - mn;
				rct = cnt;
			}
			else if(sum - mn == maxsum) {
				rct += cnt;
			}
			if(sum < mn) {
				mn = sum;
				cnt = 1;
			}
			else if(sum == mn) {
				cnt++;
			}
		}
		printf("%d %lld\n", maxsum, rct);
	}
	return 0;
}
