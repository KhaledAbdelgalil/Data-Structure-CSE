#include <iostream>

using namespace std;

int main()
{
    int input = 0;
	int * arr = new int[10];
	int size1 = 0;
	int capacity = 10;
	cout << "input a number" << endl;
	cin >> input;
	size1++;
	while (input != -1)
	{
		if(size1 == capacity)
		{
			int * newptr = new int[capacity * 2];
			capacity = capacity * 2;
			for (int i = 0; i < size1; i++)
			{
				newptr[i] = arr[i];
			}
			delete[]arr;
			arr = newptr;
		}
		arr[size1++] = input;
		cout << "input a number" << endl;
		cin >> input;

	}
	/*2d array*/
	int ** x = new int*[5];
	for (int i = 0; i < 5; i++)
	{
		x[i] = new int[5];
	}
	// use
	for (int i = 0; i < 5; i++)
	{
		delete[]x[i];
	}
	delete[]x;
    return 0;
}
