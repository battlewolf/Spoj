/*#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>

#define ULL  long long int
#define TR(c,it) for(typeof(c.begin()) it = c.begin() ; it != c.end() ; it++)
using namespace std;
map<ULL,ULL> m;
map<ULL,ULL> kv;
ULL Solve(ULL weight)
{
	static ULL i  = 0 ;
	i++;
	cout<<endl<<i;
	if(weight == 0)
		return 0;
	else if(weight < 0)
		return 99999999;
	else if(m.find(weight) != m.end())
		return m[weight];
	else
	{
	//	ULL s1 = 60 + Solve(weight - 10);
	//	ULL s2 = 1 + Solve(weight - 1);
	//	ULL s3 = 50 + Solve(weight - 1);
		
		typeof(kv.begin()) its = kv.begin() ;
		ULL min = its->first + Solve(weight - (its->second));		
		typeof(kv.begin()) it = kv.begin();
		it++;
		for(; it != kv.end() ; it++)
		{
			ULL calc = it->first + Solve(weight - (it->second));
			if(calc < min)
				min = calc;
		}	
		m[weight] = min;
		return m[weight];
	}
}

main()
{
	
	
	//kv[1] = 1;
	//kv[50] = 30;
	int T,E,F,N,P,W;
	//cout<<"\n enter the number of test cases? ";
	cin>>T;
	while(T--)
	{
		//cout<<"\n enter the empty and full pigs ? ";
		cin>>E>>F;
		int weight = F - E;
	//	cout<<"\n enter the number of values and weights? ";
		cin>>N;
		while(N--)
		{
	//		cout<<"enter the value";
			cin>>P;
//			cout<<"\n enter the weight";
			cin>>W;	
			kv[P] = W ;		
		}
		int sol = Solve(weight);
		if(sol >= 99999999)
			cout<<"\nThis is impossible.";
		else
			cout<<"\nThe minimum amount of money in the piggy-bank is "<<sol<<".";
		kv.erase(kv.begin(),kv.end());
		m.erase(m.begin(),m.end());
	}
	//cout<<endl<<Solve(100);
	//TR(m,it)
	//{
	//	cout<<endl<<it->first<<" "<<it->second;
	//}
}	*/



#include<iostream>
#include<map>
#include<vector>
#define LL  long long int
#define ALL(c) c.begin(),c.end()
#define TR(c,it) for(typeof(c.begin()) it = c.begin() ; it != c.end() ; it++)
using namespace std;

vector<LL> Weights; // this array will hold the solutions and will compute bottum up
map<LL,LL> Value_Weight;// this pair will store the value weight pair

int main()
{
	LL T,E,F,N,P,W,Weight_Needed;
	cin>>T;
	while(T--)
	{
		cin>>E>>F;
		Weight_Needed = F - E;
		cin>>N;
		while(N--)
		{
			int f = 0 ;
			cin>>P;
			cin>>W;
			typeof(Value_Weight.begin()) it = Value_Weight.begin();
			for(; it != Value_Weight.end() ; it++)
			{
				
				if(W == it->first && it->second < P)
					{f=1; break;}
				else
					continue;
				
			}
			if(f != 1){
				Value_Weight[W] = P ;
				 }
					
		}
		Weights.resize(Weight_Needed+1);
		Weights[0] = 0 ;
		for(LL i = 1 ; i <= Weight_Needed ; i++)
		{
			LL min = 999999;
			TR(Value_Weight,it)
			{
				LL index = i - it->first , temp;
				if (index < 0)
					continue;
				else
				{
					temp = Weights[index] + it->second ;
					if(temp < min)
						min = temp;
				}
			}
		
				Weights[i] = min ;	
		
			
		}
		if(Weights[Weight_Needed] == 999999)
			cout<<endl<<"This is impossible.";
		else
			cout<<endl<<"The minimum amount of money in the piggy-bank is "<<Weights[Weight_Needed]<<".";
		/*TR(Value_Weight,it)
			cout<<endl<<it->first<<" "<<it->second;*/
		
		Weights.erase(ALL(Weights));
		Value_Weight.erase(ALL(Value_Weight));
		
		
	}

}











