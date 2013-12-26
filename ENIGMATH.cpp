#include <iostream>
#include <algorithm>
#define int long long int
using namespace std;
int gcd(int a, int b)
{
	if(b == 0) return a;
	else return gcd(b, a % b);
}

main()
{
	int T, x ,y;
	cin >> T;
	while(T--)
	{
		cin >> x >> y;
		int t1 = x, t2 = y;
		if(t2 > t1) swap(t1, t2);
		int m =( x * y ) / gcd(t1, t2);
		cout << m / x << ' ' << m / y << '\n';
	}
}
