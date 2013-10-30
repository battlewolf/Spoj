#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 1844674407370955161L

using namespace std;
typedef long long int ll;
string input, ops;
vector<ll> numbers;
ll dp[102][102], dp2[102][102];;
ll f(int i, int j){
	if(i == j) return numbers[i];
	else if(dp[i][j] != -1) return dp[i][j];
	ll m = -1, cop;
	for(int k = i; k < j; k++) {
		if(ops[k] == '+')
			cop = f(i, k) + f(k + 1, j);
		else
			cop = f(i, k) * f(k + 1, j);
		m = max(m, cop);
	}
	return dp[i][j] = m;
}

ll f1(int i, int j) {
	if(i == j) return numbers[i];
	else if(dp2[i][j] != -1) return dp2[i][j];
	ll m = MAX, cop;
	for(int k = i; k < j; k++) {
		if(ops[k] == '+') cop = f1(i, k) + f1(k + 1, j);
		else cop = f1(i, k) * f1(k + 1, j);
		m = min(m, cop);
	}
	return dp2[i][j] = m;
}

int main() {
	// your code goes here
	int T;
	cin >> T;
	while(T--) {
		cin >> input;
		if(input.size() == 1) {
			cout << input[0] << ' '  << input[0] << '\n';
			continue;
		}
		memset(dp, -1, sizeof dp);
		memset(dp2, -1, sizeof dp2);
		for(int i = 0; i < input.size(); i++) {
			if(input[i] == '+' || input[i] == '*')
				ops += input[i];
			else
				numbers.push_back(input[i] - '0');
		}
		cout << f(0, numbers.size() - 1) << ' ' <<  f1(0, numbers.size() - 1) << '\n';
		ops.clear();
		numbers.clear();
	}
	return 0;
}
