#include <iostream>
using namespace std;

int revNum(int num)
{
	int n = 0;
	while(num)
	{
		n *= 10;
		n = n + (num % 10);
		num = num / 10;
	}
	return n;
}

main()
{
	int T, num1, num2;
	cin >> T;
	while(T--)
	{
		cin >> num1 >> num2;
		cout << revNum( revNum(num1) + revNum(num2) )<< '\n';
	}
}
