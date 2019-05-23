#include <iostream>
using namespace std;
//TimeComplexity:WorstCase:O(logn)averageCase O(logn) BestCase:O(1)
//SpaceComplexity::no need for extra space
int BinarySearch(int arr[],int l,int h,int key)
{
    while(l<=h)
    {
        int m=(l+h)/2;
        if(arr[m]==key) return m;
        else if(arr[m]>key) h=m-1;
        else l=m+1;
    }
    return -1;
}
int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int num;
	cout << "Enter an Integer :";
	cin >> num;

	int result = BinarySearch(arr, 0, n - 1, num);
	if(result == -1)
		cout << "The Number : (" << num << ") Was Not Found." << endl;
	else
		cout << "The Number : (" << arr[result] << ") Was Found At Index : (" << result << ")" << endl;
    return 0;
}
