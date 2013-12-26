#include <iostream>
#include <vector>
using namespace std;

main() {
	int T; cin >> T;
	vector<int> nums;
	int num;
	for(int i = 0; i < T; i++) {
		cin >> num;
		if(num == 0) nums.push_back(1);
		if( (num & 1 ) == 0) {
			num = ~num;
			for(int i = 31;( (1 << i) & num ) == 1; i--) 
				num = num ^ ( 1 << i );			
			nums.push_back(num);
		}
	}
		for(int i = 0; i < nums.size(); i++)
			cout << endl << nums[i];
	
}
