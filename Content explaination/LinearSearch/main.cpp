#include <iostream>
using namespace std;
int LinearSearch(int arr[],int n,int key)//average O(n)//no need for extra space
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key) return i;
    }
    return -1;
}
int main()
{

    int arr[] = { 90,10,40,70,5 };
	int n = sizeof(arr) / sizeof(arr[0]);//5*4=20 => 20/4 =>5

	int num;
	cout << "Enter an Integer :";
	cin >> num;

	int result = LinearSearch(arr,n,num);
	if (result == -1)
		cout << "The Number : (" << num << ") Was Not Found." << endl;
	else
		cout << "The Number : (" << arr[result] << ") Was Found At Index : (" <<result<<")"<< endl;



    return 0;
}
