#include<unistd.h>
#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<algorithm>
#define TR(c,it) for(typeof(c.begin()) it = c.begin() ; it != c.end() ; it++)
#define ALL(c) c.begin(),c.end()
using namespace std;

vector<vector<int> > matrix(2 , vector<int> (4,9999));
vector<int> intersection_vector(3);

int Solve(int row , int column)
{
//	static int j = 0 ; 
//	j++;
//	cout<<"\n j :"<<j ;
//	cout<<"\n row "<<row<<" column :"<<column<<" matrix[row][column] :"<<matrix[row][column];
	//sleep(1500*1000);
	cout<<"\n\n";
	TR(matrix[0] , it)
		cout<<*it<<" ";
	cout<<endl;
	TR(matrix[1] , it)
		cout<<*it<<" ";
	if(matrix[row][column] == 9999 )
	{
		return 0 ; 
	}
	else
	{
		int number = matrix[row][column];
//		The element is present in the intersection_vector		
		if(binary_search (intersection_vector.begin() , intersection_vector.end() , number))
		{
				//search for the element in the 1-d vectors
			//	cout<<"\n im in";
				int row_index = (row+1) % 2 , index ,s1 , s2;
				vector<int>::iterator low;
				low = lower_bound (matrix[row_index].begin(),matrix[row_index].end(),number);
				index = low - matrix[row_index].begin(); //gives the index at which it occurs
				//cout<<"\n index :"<<index;
				s1 = Solve(row_index,index+1);
				//cout<<"\n did i execute?";
				s2 = Solve(row , column + 1);
			//	cout<<"\n s1:"<<s1<<" s2: "<<s2;
				matrix[row][column] = matrix[row][column] + max(s1,s2);
				
		}	 
		else
		{
			matrix[row][column] = matrix[row][column] + Solve(row , column + 1);
		}
		return matrix[row][column];
	}
}













main()
{
	cout<<"\n enter the values for the first vector";
	for(int i = 0 ; i < 3 ; i++)
		cin>>matrix[0][i];
	cout<<"\n enter the values for the second vector";
	for(int i = 0 ; i < 3 ; i++)
		cin>>matrix[1][i];
		
	vector<int>::iterator aat ; 
	aat = set_intersection(matrix[0].begin(),matrix[0].begin()+3,matrix[1].begin(),matrix[1].begin()+3,intersection_vector.begin());
	intersection_vector.resize(aat - intersection_vector.begin());	
	
//	cout<<"\n the intersection_vector : \n";
//	cout<<intersection_vector[0]<<" "<<intersection_vector[1]<<" "<<intersection_vector[2]<<" "<<intersection_vector[3];
	for(typeof(intersection_vector.begin()) iter = intersection_vector.begin() ; iter != intersection_vector.end() ; iter++)
		cout<<*iter;
	cout<<endl<<Solve(0,0)<<"unga aaya\n";
/*	for(int i = 0 ; i < 3 ; i++)
	{
		for(int j = 0 ; j < 3; j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}*/
	TR(matrix[0] , it)
		cout<<*it<<" ";
	cout<<endl;
	TR(matrix[1] , it)
		cout<<*it<<" ";
}


