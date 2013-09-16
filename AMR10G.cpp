#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll; 
main () {
	ll T, K, N;
	cin >> T;
	while (T--) 
	{
		vector<ll> heights;
		cin >> N >> K;
		for (int i = 0 ; i < N ; i++)
		{
			int temp;
			cin >> temp;
			heights.push_back(temp);
		}
		sort(heights.begin(),heights.end());
		if (K == 1) cout << endl << 0;
		else if (K == N) cout << endl << heights[N-1] - heights[0];
		else
		{
			
		}
	}
}

