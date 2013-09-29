//Kruskal
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int PRICE, V, E; 

struct node {
	int start;
	int cost;
	int end;
};

vector<node> graph;

bool compare(const node &left,const node &right) {
	return left.cost < right.cost;
}

bool find(int v1, int v2, vector<int> &links, vector<int> &count) {
	
	while(links[v1] != v1) v1 = links[v1];
	while(links[v2] != v2) v2 = links[v2];
	
	return v1 == v2 ? true : false;
}

void dUnion(int v1, int v2, vector<int> &links, vector<int> &count) {
	
	while(links[v1] != v1) v1 = links[v1];
	while(links[v2] != v2) v2 = links[v2];
	
	if(count[v1] <= count[v2]) {
		links[v1] = v2;
		count[v2] += count[v2];
	}
	else {
		links[v2] = v1;
		count[v1] += count[v1];
	}
}


void kruskal() {
	int cost = 0, i = 0;
	
	vector<int> links(V+1);
	vector<int> count(V+1);
	
	for(int j = 1; j <= V; j++) {
		links[j] = j;
		count[j] = 1;
	}
	
	set<int> S;	
	/*consider an edge. If the end nodes belong to the same set, its a loop. So, it shouldn't be considered.*/
		
	while(i < E && S.size() != V) {
		int v1 = graph[i].start, v2 = graph[i].end;
		if(! find(v1, v2, links, count) ) {
			dUnion(v1, v2, links, count);
			cost += graph[i].cost;
			S.insert(v1);
			S.insert(v2);
		}		
		i++;	
	}
	printf("\n%d", cost * PRICE);	
}

main() {
	int t;
	scanf("%d",&t);
	while( t-- ) {
		scanf("%d%d%d",&PRICE ,&V, &E);
		graph.resize(E);
		
		for(int i = 1; i <= E; i++) 
			cin >> graph[i-1].start >> graph[i-1].end >> graph[i-1].cost;
			
		sort(graph.begin(), graph.end(), compare);
		kruskal();		
	}
}
