#include <iostream>
using namespace std;
int main()
{
	int arr[100], n , pos, element;
	cout << "Enter the number of elements in array: ";
	cin >> n;
	cout << "Enter elements of the array: " << endl;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << "Enter position you want to insert element: ";
	cin >> pos;
	cout << "Enter element to be inserted: ";
	cin >> element;
	if(pos < 0 || pos > n)
	{
		cout << "invalid position: " << endl;
	}
	else
	{

		for(int i = n; i > pos; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[pos] = element;
		n++;
		cout << "Array after insertion is: ";
		for(int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
