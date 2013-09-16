#include<iostream>
#include<set>
#include<stack>
#include<map>
#include<queue>
#define MAX 10000
#define cpresent(val) find(all(c),val)!=c.end()
#define FOR(variable,range) for(int variable = 0 ; variable < range ; variable++)
#define all(c) c.begin(),c.end()
#define TR(c,it) for(typeof(c.begin()) it = c.begin() ; it != c.end() ; it++)
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
vvi Graph(MAX); //holds the  Graph
//vvi Temp_Graph(MAX);
vvi Layers(MAX);
vi Discovered(MAX,0);
int N; 
int BFS(int node_to_start)
{
	int layer_counter = 0 ;
	//queue<int> Q;
	Layers[0].push_back(node_to_start);
	Discovered[node_to_start-1] = 1;
	//Q.push(node_to_start);
	while(Layers[layer_counter].begin() != Layers[layer_counter].end() )
	{
		//int current_node_processed = Q.front();
		//cout<<"\n current_node_processed: "<<current_node_processed;
		//Q.pop();
		for(typeof(Layers[layer_counter].begin()) at = Layers[layer_counter].begin() ; at != Layers[layer_counter].end() ; at++){
			int current_node_processed = *at;
			TR(Graph[current_node_processed-1],it)
			{
				int adjacent_node = *it ;
				if(!Discovered[adjacent_node-1])
				{
					Discovered[adjacent_node-1] = 1;//known
					//Q.push(adjacent_node);
					Layers[layer_counter+1].push_back(adjacent_node);
					//layer_counter++;
					//				Put_In_Tree(current_node_processed,adjacent_node);
				}
			}}
		layer_counter++;
	}		
	//cout<<"\nlayercounter "<<layer_counter;
	return layer_counter;
}

main()
{
	//	Read_Graph();
	//	Print_Graph();
	//	BFS(3);
	//	Print_Tree();

	/**
	  Identify the root of the tree and do BFS. We will get the longest path.
	  A tree can have only root.
	 **/
	cin>>N;
	int vertex1,vertex2,root,max;
	for(int i = 1 ; i <= N-1 ; i++)
	{
		cin>>vertex1>>vertex2;
		Graph[vertex1-1].push_back(vertex2);
		//	Graph[vertex2-1].push_back(vertex1);
		//		Temp_Graph[vertex2-1].push_back(vertex1);
	}
	//	find the root
	/*for(int i = 0 ; i < N;i++)
	  {
	  if(Temp_Graph[i].size() == 0)
	  root = i+1;
	  }*/
	//cout<<"\n"<<BFS(root)-1; 
	max = BFS(1);
	Discovered.resize(MAX,0);
	Layers.clear();
	for(int i = 1 ; i < N ; i++)
	{
		int temp = BFS(i+1);
		if(max < temp)
			max = temp;
		Discovered.resize(MAX,0);
		Layers.clear();
	}
	cout<<"\n max:"<<max;

}







