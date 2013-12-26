#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string input;
int state[6101][6101];

int f(int i, int j) {
	if( i >= j ) return 0;
	else if(state[i][j] != -1) return state[i][j];
	else if(input[i] == input[j]) return state[i][j] = f(i + 1, j - 1);
	else if(input[i] != input[j])
		return state[i][j] = ( 1 + min(f(i-1+1, j - 1) , f(i + 1, j+1-1)) ) ;
}

main() {
	int T;
	cin >> T;
	while(T--) {
		cin >> input;
		memset(state, -1, (input.size() * input.size() * sizeof(int)));
		cout << f(0, input.size() - 1) << '\n';
	}
}
