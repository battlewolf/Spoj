#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <set>
#include <iterator>
#include <vector>
#include <string>
#define FOR(i,size) for(int i = 0 ; i < size ; i++)
using namespace std;
vector<vector<int> > mat1,mat2;
int N,T;

main()
{
	while(1)
	{
		scanf("%d%d",&N,&T);
		if(N==0 && T==0) break;
		mat1.resize(N);
		mat2.resize(N);
		FOR(i,N)
		{
			mat1[i].resize(N);
			mat2[i].resize(N);
			FOR(j,N) scanf("%d",&mat1[i][j]);
		}
		FOR(i,N) FOR(j,N) scanf("%d",&mat2[i][j]);
	}
}
