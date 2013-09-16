#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long int
using namespace std;
struct data {
	ll start;
	ll end;
	ll price;
};
bool compare_by_start (const data &l, const data &r) {
	return l.start < r.start ;
}
main () {
	ll T, n;
	cin >> T;
	vector<struct data> V;
	while (T--) {
		cin >> n;
		V.resize(n);
		for (ll i = 0 ; i < n ; i++) { 
			cin >> V[i].start >> V[i].end >> V[i].price;
			V[i].end = V[i].start + V[i].end;
		}
		sort (V.begin(),V.end(),compare_by_start);
		ll max = -9999;
		for (ll i = 1 ; i < n ; i++) {
			/*
				Find the non-overlapping duration nearest to the one given and then add it to this value. If it is
				greater update, else leave it as such.
			*/
			/*Now I use the Binary Search algorithm to find the value*/
			
		}
	}
}
