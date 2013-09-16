#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//vector<vector<int> > DP;
/*int DP[3][3]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
int count(int n, int k){
	cout<<"asdasd";
	if(n == 0)
		return 0;
	if(k == 0)
		return 1;
	if(DP[n][k] != -1)
		return DP[n][k];
	int val = 0 ;
	for(int i = 0 ; i <= k && i < n ; i++){
		val = val + count(n-1 ,k-i);
	}
	DP[n][k] = val;
	return DP[n][k];
}

main(){
	int n,k;
	cin>>n>>k;
	/**cout<<"asdasd";
	DP.resize(n);
	for(int i = 0 ; i < n ; i++){
		DP[i].resize(k,-1);		
	}*/
//	cout<<endl<<count(n,k);
//	for(int i = 0 ; i < 3 ; i++){
//		for(int j = 0 ; j < 3 ; j++){
//			cout<<DP[i][j]<<" ";}
//		cout<<endl;
//		}
//		
//}
