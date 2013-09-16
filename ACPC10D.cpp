#include<iostream>
#include<vector>
#include<algorithm>
#define LL long long int
using namespace std;
vector<vector<LL> > V(100000);
main()
{
	static int co = 0;
	int no_of_rows,temp;
	cin>>no_of_rows;while(no_of_rows!=0){
	for(int i = 0 ; i < no_of_rows ; i++)
	{
		V[i].resize(3,0);
		for(int j = 0 ; j < 3 ; j++)
			cin>>V[i][j];
	}
	V[0][2] = V[0][2] + V[0][1];
	V[1][0] = V[0][1] + V[1][0];
	V[1][1] = V[1][1] + min(V[0][1],min(V[1][0],V[0][2]));
	V[1][2] = V[1][2] + min(V[0][1],min(V[1][1],V[0][2]));
	
	for(int i = 2 ; i <= no_of_rows-1 ; i++)
	{
		V[i][0] = V[i][0] + min(V[i-1][0],V[i-1][1]);
		V[i][1] = V[i][1] + min(min(V[i-1][0],V[i-1][1]),min(V[i][0],V[i-1][2]));
		V[i][2] = V[i][2] + min(V[i][1],min(V[i-1][1],V[i-1][2]));
	}co++;
	cout<<endl<<co<<". "<<V[no_of_rows-1][1];	
	cin>>no_of_rows;	
}}
