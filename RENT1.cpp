#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
struct node {
	int st;
	int et;
	int du;
};
bool compare(const node &l,const node &r) {
	return l.st < r.st;
}

int bfind(vector<node> &vs, int fi, int start, vector<bool> &b){
	int  end = vs.size() - 1, mid = (start + end) >> 1;
	while(start < end)
	{
		mid = (start + end) >> 1;
		if(vs[mid].st >= fi && b[mid] == 0) return mid;
		else if(vs[mid].st < fi)
			start = mid;
		
	}
	return -1;
}


main() {
	int T, D;
	cin >> T;
	while(T--) {
		cin >> D;
		vector< node > vs(D);
		for(int i = 0; i < D; i++)
			cin >> vs[i].st >> vs[i].et >> vs[i].du;
		sort(vs.begin(), vs.end(), compare);
		int m = vs[0].du;
		for(int i = 0, n = vs.size(); i < n; ++i) {
			vector<bool> b(n, 0);
			int start = vs[i].start
		}
	}
}
