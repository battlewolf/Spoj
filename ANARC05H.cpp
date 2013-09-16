#include<iostream>
#include<set>
#include<stack>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<queue>
#include<string>
//#define N 8
#define all(c) c.begin(),c.end()
#define TR(c,it) for(typeof(c.begin()) it = c.begin() ; it != c.end() ; it++)
using namespace std;
//int arr[1000],N;
vector<int> arr;
int N;


main()
{

	string s;
	cin>>s;
//	N = s.size();
//	arr.resize(N);		
	typeof(s.begin()) it = s.begin();		
	while(it != s.end()){
		char c = *it ;
		arr.push_back(atoi(c));				
	}
}
