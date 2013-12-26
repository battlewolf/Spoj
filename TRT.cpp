#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int arr[2001], N;
int state[2001][2001];

int f(int i, int j) {
	if( i > j ) return 0;
	else if(state[i][j] != -1) return state[i][j];
	int	age =  ( (i - 1) + (N - j) ) + 1 ;
	return state[i][j] = max(arr[i] * age + f(i + 1, j), arr[j] * age + f(i, j - 1));
}
int
main() {
	cin >> N;
	memset(state, -1, sizeof (state) );
	for(int i = 1; i <= N; i++)
		cin >> arr[i];
	cout <<  f(1, N) << '\n';
	return 0;
}
