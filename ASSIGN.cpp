#include<iostream>
#include<vector>
#include<algorithm>

#define ALL(c) c.begin(),c.end()
#define ULL unsigned long long int

using namespace std;
vector<vector<int> > V;
vector<vector<bool> > Aux;
vector<int> column_Known;

int N;
ULL cost;
void Solve(int row,int au)
{
	if(row == N)
	{
		cost++;
		return ;
	}
	/*if(Aux[row][au] == 1)
	{
		cost++;
		return;
	}*/
	else
	{
		typeof(column_Known.begin()) it;
		for(int i = 0 ; i < N ; i++)
		{
			it = find(ALL(column_Known),i);
			if(it!= column_Known.end())
				continue ;
			else if(V[row][i] == 1)
			{
		//		Aux[row][i] = 1;
				column_Known.push_back(i);
				Solve(row+1,au);
				column_Known.pop_back();
			}
			else
				continue;			
		}
	}
}
main()
{
	int c;
	cin>>c;
	while(c--)
	{		
		
		cin>>N;
		V.resize(N);
	//	Aux.resize(N);
		for(int i = 0 ; i < N ; i++)
		{
			V[i].resize(N);
	//		Aux[i].resize(N);
			for(int j = 0 ; j < N ; j++)
				{cin>>V[i][j];}
		}
		cost = 0;
		Solve(0,0);
		cout<<endl<<cost;
		
	}	
}
