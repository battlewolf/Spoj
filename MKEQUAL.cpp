#include <iostream>
using namespace std;

main() {
	int T, N, num, i;
	cin >> T;
	while(T--) {
		cin >> N; i = N;
		int sum = 0;
		while(N--) {
			cin >> num;
			sum = sum + num;
		}
		if( sum % N == 0 ) cout << i << '\n';
		else cout << i - 1 << '\n';
	}
}
