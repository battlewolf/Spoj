#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
int mat[100][100];
int solve (int n, int l) {
	if (l == 3)
		return 1;
	else if (mat[n][l] != -1)
		return mat[n][l];
	else {
		int s = 0;
		for (int i = 0 ; i <= 9 ; i++)
			if (n <= i)
				s = s + solve(i, l+1);
		mat[n][l] = s;
		return s;
	}		
}
main() {
	int s = 0 ;
	memset(mat, -1, sizeof(mat));
	for (int i = 0 ; i <= 9 ; i++)
	{
		cout << endl << solve(i, 1);
		s = s + solve(i, 1);
//		cout << endl << solve(i,1);
	}
	
	cout << endl << " s : "  << s;
}
