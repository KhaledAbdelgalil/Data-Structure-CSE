#include <bits/stdc++.h>

using namespace std;
void test_lower_upper_bounds()
{
	vector<int> arr(10);
	for (size_t i = 0; i < 9; i++)
	{
		//arr[i] = i * 2;
		arr[i]=10;
		cout << arr[i] << " ";
	}
	arr[9]=12;
	cout<<arr[9];
	cout<<endl;
	for (size_t i = 0; i < 10; i++)
	{
		bool found = binary_search(arr.begin(), arr.end(), i * 2);
		if (found)
		{
			cout << "mawgood" << endl;
		}
	}

	vector<int>::iterator x = lower_bound(arr.begin(), arr.end(), 1);//lower bound and upper bound the array must be sorted
	int index = x - arr.begin();//to get index
	cout << endl;
	/*cout << *(lower_bound(arr.begin(), arr.end(), 1))<< " should be 2" <<endl;
	cout << *(lower_bound(arr.begin(), arr.end(), 2))<< " should be 2" << endl;
	cout << *(upper_bound(arr.begin(), arr.end(), 2))<< " should be 4" << endl;*/
	cout << *(lower_bound(arr.begin(), arr.end(), 10))<< " should be 10" <<endl;//lower bound get iterator for minmum element fit equal or just after
	cout << *(upper_bound(arr.begin(), arr.end(), 10))<< " should be 12" << endl;//upper bound get iterator for element just after that element

}
int main()
{
    test_lower_upper_bounds();
    return 0;
}
