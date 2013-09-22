#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

main() {
	int N;
	vector<int> arr1, arr2, arr3, arr4;
	cin >> N;
	for(int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr1.push_back(temp);
	}
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < N; k++) {
				arr2.push_back(arr1[i] * arr1[j] + arr1[k]);
			}
		}
	}
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < N; k++) {
				arr3.push_back(arr1[i] * arr1[j] + arr1[j] * arr1[k]);
			}
		}
	}
	sort(arr2.begin(), arr2.end());
	sort(arr3.begin(), arr3.end());
	arr4.resize(arr2.size() + arr3.size(), -1);
	
	vector<int>::iterator it = set_intersection(arr2.begin(), arr2.begin() + arr2.size(), arr3.begin(), arr3.begin() + arr3.size(),arr4.begin());	
	int c = 0;
	for(int i = 0; arr4[i] != -1 && i < arr4.size(); i++) c++;
	cout << endl << c;
//	int c = 0;
//	cout << endl << " arr2.size " << arr2.size() << " " << " arr3.size " << arr3.size();
//	
	
}
