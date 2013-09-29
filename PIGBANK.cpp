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











