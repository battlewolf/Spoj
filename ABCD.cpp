#define mp make_pair
#include<map>
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int N;
map<string,string> M;
string str1,str2,temp1,var1;
main()
{
	scanf("%d",&N); cin >> str1 ;

	M.insert(mp("AB","CD"));M.insert(mp("BA","CD"));
	M.insert(mp("AC","BD"));M.insert(mp("CA","BD"));
	M.insert(mp("AD","BC"));M.insert(mp("DA","BC"));
	M.insert(mp("BC","AD"));M.insert(mp("CB","AD"));
	M.insert(mp("BD","AC"));M.insert(mp("DB","AC"));
	M.insert(mp("CD","AB"));M.insert(mp("DC","AB"));
	str2 = M[str1.substr(0,2)];
	for(int i = 2 ; i < (N << 1) ; i+=2)
	{
		temp1 = M[str1.substr(i,2)];
		if(temp1[0] == str2[i-1]) swap(temp1[0],temp1[1]);
		str2 = str2 + temp1;	
	}
	cout << endl << str2;
}
//#include <vector>
//#include <list>
//#include <map>
//#include <set>
//#include <deque>
//#include <stack>
//#include <bitset>
//#include <algorithm>
//#include <functional>
//#include <numeric>
//#include <utility>
//#include <sstream>
//#include <iostream>
//#include <iomanip>
//#include <cstdio>
//#include <cmath>
//#include <cstdlib>
//#include <ctime>
//#include <string.h>
//#include <string>
//#include <queue>
//#include <iterator>
//using namespace std;
////my set of templates
// #define F(i,start,n) for(int i=start;i<n;i++)
// #define sz(a) int((a).size()) 
// #define P_B push_back 
// #define all(c) (c).begin(),(c).end() 
// #define trav(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
// #define present(c,x) ((c).find(x) != (c).end()) 
// #define cpresent(c,x) (find(all(c),x) != (c).end())
// #define ll long long
// #define pi pair<int,int>
// #define pll pair<long,long>
// #define pii pair<int,pi >
// #define X first
// #define Y second
// #define mp make_pair
// #define vi vector<int>
// #define vs vector<string>
// #define vpi vector<pi >
// #define vpii vector<pii >
// #define vpll vector<pll >
// #define MaxV (1<<30)
// #define LLMaxV (1ll<<60)
// #define vl vector<long>
// #define vll vector<long long>
// template<class T>string ToString(T t){stringstream s;s<<t;return s.str();}
// template<class T>void ToOther(T& t,string a){stringstream s(a);s>>t;}
//int main() {
//    int N,i;string input,s1,result;map<string,string> M;
//	scanf("%d",&N);
//	cin>>input;
//	M.insert(mp("AB","CD"));M.insert(mp("BA","CD"));
//	M.insert(mp("AC","BD"));M.insert(mp("CA","BD"));
//	M.insert(mp("AD","BC"));M.insert(mp("DA","BC"));
//	M.insert(mp("BC","AD"));M.insert(mp("CB","AD"));
//	M.insert(mp("BD","AC"));M.insert(mp("DB","AC"));
//	M.insert(mp("CD","AB"));M.insert(mp("DC","AB"));
//	for(i=0;i<2*N;i=i+2) {
//		s1=M[input.substr(i,2)];
//		if(i==0) {result+=s1;}
//		else if(result[i-1]==s1[0]){
//			swap(s1[0],s1[1]);
//			result+=s1;
//		}
//		else{
//			result+=s1;
//		}
//	}
//	cout<<result<<endl;
//	return 0;
//}


















