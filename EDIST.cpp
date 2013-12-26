#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;
string input1, input2;

int edist(int n1, int n2) {
	if(n1 == 0 && n2 == 0) return 0;
	if(n1 == 0 && n2 != 0) return n2 + 1;
	if(n1 != 0 && n2 == 0) return n1 + 1;
	
	int op1, op2, op3;
	op3  = INT_MAX;
	op1 = 1 + edist(n1 - 1, n2);
	op2 = 1 + edist(n1, n2 - 1);
	if(input1[n1] != input2[n2])
		op3 = 1 + edist(n1 - 1, n2 - 1);
	else
		op3 = edist(n1-1, n2-1);
	return min(min(op1, op2), op3);
}

main() {
	int T;
	cin >> T;
	while(T--) {
		cin >> input1 >> input2;
		int n1 = input1.size(), n2 = input2.size();
		if(n1 > n2) swap(n1, n2);
		cout << endl << edist(n1 - 1, n2 - 1);
	}
}

