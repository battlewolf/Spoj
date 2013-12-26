using namespace std;

#include <iostream>

#define MAX 5000 

bool islucky[ MAX + 1 ];
int numbers[MAX + 1];

void precompute()
{
	int index = 1;
	for(int inc = 2; inc < MAX; ++inc)
	{
		if(!islucky[inc])
		{
			numbers[index++] = inc;
			int cnt = -1;
			for(int j = inc; j <= MAX; j++)
			{
				/*if(islucky[j])
				{
					if(cnt++ == inc)
					{
						islucky[j] = false;
						cnt = 1;
					}
				}*/
				if(!islucky[j]) cnt++;
				if(!islucky[j] && cnt == inc) islucky[j] = true, cnt = 0;
			}
		}
	}
}

int main() 
{
	precompute();
	int n;
	while( cin >> n, n)	cout << numbers[n] << '\n';
	return 0;
}

