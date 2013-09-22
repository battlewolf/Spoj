//BFS

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int prime[100001], A, B;
bool seen[100001];

void primeCompute() {
	memset(prime, 1, sizeof(prime));
	int max = 10000;
	for(int i = 2; i * i <= max; i++)
		if(prime[i])
			for(int j = i * i; j < max; j+=i)
				prime[j] = 0;	
}

struct number {
		int t_3, t_2, t_1, t_0;
		int dist;
};
int BFS() {
	memset(seen, 0, sizeof(seen));

	number pu;

	pu.t_0 = A % 10;
	pu.t_1 = (A / 10) % 10;
	pu.t_2 = (A / 100) % 10;
	pu.t_3 = (A / 1000) % 10;
	pu.dist = 0;
	
	seen[A] = 1;
	queue<struct number> Q;
	Q.push(pu);	
		
		
	while( !Q.empty() ) {
		struct number aux = Q.front();
		Q.pop();
				
//		cout << endl << "hello";		
		if(aux.t_0 * 1 + aux.t_1 * 10 + aux.t_2 * 100 + aux.t_3 * 1000 == B) {return aux.dist;}
//		cout << endl << aux.t_0 * 1 + aux.t_1 * 10 + aux.t_2 * 100 + aux.t_3 * 1000;
		
		//modify each digit and see if its a prime and push into queue(if its a prime)		
		
		for(int i = 0; i <= 9; i++) {
			number temp = aux;
			int num_construct = (i * 1) + (temp.t_1 * 10) + (temp.t_2 * 100) + (temp.t_3 * 1000);
			if(!seen[num_construct] && prime[num_construct]) {
				seen[num_construct] = 1;
				temp.t_0 = i;
				temp.dist = temp.dist + 1;
				Q.push(temp);
		
			}
			
								
		}		
			
		for(int i = 0; i <= 9; i++) {
			struct number temp = aux;
			int num_construct = (temp.t_0 * 1) + (i * 10) + (temp.t_2 * 100) + (temp.t_3 * 1000);
			if(!seen[num_construct] && prime[num_construct]) {
				temp.t_1 = i;
				seen[num_construct] = 1;
				temp.dist++;
				Q.push(temp);
			}
			
								
		}		
			
		for(int i = 0; i <= 9; i++) {
			struct number temp = aux;
			int num_construct = temp.t_0 * 1 + temp.t_1 * 10 + i * 100 + temp.t_3 * 1000;
			if(!seen[num_construct] && prime[num_construct]) {
				temp.t_2 = i;temp.dist++;
				seen[num_construct] = 1;
				Q.push(temp);		
			}
			
								
		}		
			
		for(int i = 1; i <= 9; i++) {
			struct number temp = aux;
			int num_construct = (temp.t_0 * 1 + temp.t_1 * 10 + temp.t_2 * 100 + i * 1000);
			if(!seen[num_construct] && prime[num_construct]) {
				temp.t_3 = i;temp.dist++;
				seen[num_construct] = 1;
				Q.push(temp);
			}
		}		
	}
	return -1;
	
}

main() 
{
	primeCompute();		
	int T; // A ----> B
	cin >> T;
	while(T--) {
		cin >> A >> B;
		cout<< BFS() << endl;
	}
}
