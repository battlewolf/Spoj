#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <set>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

char input[54][54];
bool known[54][54];

int X, Y, maxlen;
const int xd[8] = {0, 0, -1, +1, -1, +1, -1, +1};
const int yd[8] = {+1, -1, 0, 0, -1, -1, +1, +1};

bool okay (int x, int y)
{
	if (x >=0 && x < X && y >=0 && y < Y) return true;
	else false;
}

void DFS (int x, int y, int l)
{
	if (l > maxlen) maxlen = l;
	known[x][y] = true;
	for (int i = 0 ; i < 8 ; i++)
	{
		if (okay(x + xd[i],y + yd[i]) && !known[x + xd[i]][y + yd[i]])
		{
			if(input[x + xd[i]][y + yd[i]] - input[x][y] == 1)
				DFS(x + xd[i], y + yd[i], l + 1);
		}
	}	
}

main() 
{
	int cas = 1;
	while(1)
	{
		cin >> X >> Y;
		if (X == 0 && Y == 0) break;
		for (int i = 0 ; i < X ; i++)
			scanf("%s",input[i]);
		for(int j = 0 ; j < Y ; j++)
			input[X][j] = '\0';
		
		int max = 0;
		for (int i = 0 ; i < X ; i++)
		{
			for (int j = 0 ; j < Y ; j++)
			{
				memset(known,0,sizeof(known));
				if(input[i][j] == 'A')
				{
					maxlen = 1;
					DFS(i,j,1);
					if(maxlen > max)max = maxlen;
				}
			}
		}
		printf("\nCase %d: %d",cas,max);
		cas++;
				
	}	
}
