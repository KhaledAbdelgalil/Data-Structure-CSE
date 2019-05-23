#include <iostream>
#include<vector>

using namespace std;
//half-interval-search//logarithmic-search
int binary_search(vector<int> arr,int beg,int end,int value)
{
	if (beg > end)
		return -1;

	int mid = (beg + end )/ 2;
	if (arr[mid] == value)
	{
		return mid;
	}
	else if (arr[mid] > value)// no need for the range of mid -> end
		return binary_search(arr, beg, mid - 1, value);
	else// no need for the range of beg -> mid
		return binary_search(arr, mid + 1, end, value);
}
void test_binary_search()
{
	vector<int> arr(10);
	for (size_t i = 0; i < 10; i++)
	{
		arr[i] = i*2;
	}

	for (int i = -1; i < 21; i++)
	{
		cout << binary_search(arr, 0, 9, i)<<endl;
		//cout << i<<" "<<binary_search_iterative(arr, i) << endl;
	}
}
int main()
{
    test_binary_search();
    return 0;
}
