#include <iostream>
using namespace std;
main() {
	int num1, num2, num3;
	while (1){
	cin >> num1 >> num2 >> num3;
	if (num1 ==0 && num2 ==0 && num3 ==0) break ;
	if (num2 - num1 == num3 - num2) cout << endl << "AP " << num3 + (num3 - num2);
	else	cout << endl << "GP " << num3 * (num3 / num2);
	}
}
