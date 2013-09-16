#include<iostream>
#include<set>
#include<stack>
#include<map>
#include<queue>
#include<string>
#define cpresent(val) find(all(c),val)!=c.end()
#define FOR(variable,range) for(int variable = 0 ; variable < range ; variable++)
#define all(c) c.begin(),c.end()
#define TR(c,it) for(typeof(c.begin()) it = c.begin() ; it != c.end() ; it++)
using namespace std;
typedef vector<int> vi; 
typedef vector<vector<int> > vvi;
vvi Graph(10000); //holds the  Graph
int N,M ; //number of vertices and edges
vi Discovered(10000,0);

void BFS(int node_to_start)
{
//	int layer_counter = 0 ;
	queue<int> Q;
	Discovered[node_to_start-1] = 1;
	Q.push(node_to_start);
	while(!(Q.empty()))
	{
		int current_node_processed = Q.front(),root; //the current_node_processed also is the root of the subtree
	//	cout<<"\n current_node_processed: "<<current_node_processed;
		Q.pop();
		TR(Graph[current_node_processed-1],it)
		{
			int adjacent_node = *it ;
			if(adjacent_node == root)
				continue;
			if(!Discovered[adjacent_node-1])
			{
				Discovered[adjacent_node-1] = 1;//known
				Q.push(adjacent_node);
		//		Put_In_Tree(current_node_processed,adjacent_node);
			}
			else
			{
				return ;
			}
		}
		root = current_node_processed;
	}		
	return ;
}

main()
{
	bool success = 0 ;
	int vertex1,vertex2;
	cin>>N>>M;
	if(N ==1 && M==0 )
		cout<<"\nNO";{
	for(int i = 0 ; i < M ; i++)
	{
		cin>>vertex1>>vertex2;
		Graph[vertex1-1].push_back(vertex2);
		Graph[vertex2-1].push_back(vertex1);
	}
	/*for(int i = 0 ; i < N ; i++)
	{
		cout<<"\n For node :"<<i+1;
		TR(Graph[i],it)
			cout<<" "<<*it;
	}*/
	BFS(1);
	int i;
	for(i = 0 ; i < N ; i++)
	{
		if(Discovered[i] == 0)
			{cout<<"\nNO";break;}
	}
	if(i==N)
		cout<<"\nYES";
}







}
