#include <iostream>
using namespace std;
int main()
{
	int a;
	float r = 0.08;
	int t = 5 * 12;
	float i;
	cout << "Enter amount deposited ";
	cin >> a;
	i = a * r * t;
	cout << "interest after 5yrs is " << i << endl;
	return 0;
}
