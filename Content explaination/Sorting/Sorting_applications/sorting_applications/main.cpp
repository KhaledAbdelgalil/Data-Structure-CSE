#include <bits/stdc++.h>

using namespace std;

//1st application: input an unsorted array, and we want to find if the array elements are unique or not
bool unique_array_slow_version(vector<int> arr)//this has been proved to be O(n2)
{
    int size1=arr.size();
	for (int i = 0; i < size1-1; i++)
	{
		for (int j = i+1; j < size1; j++)
		{
			if (arr[i] == arr[j])
				return false;
		}
	}
	return true;
}

bool unique_array_fast_version(vector<int> arr)
{
	sort(arr.begin(), arr.end()); // costs O(nlogn) which is < O(n2)

	for (int i = 0; i < arr.size()-1; i++)
	{
		if (arr[i] == arr[i + 1])
			return false;
	}
	return true;
}
//2nd application: Deleting Duplicates
vector<int> delete_duplicates_slow_version(vector<int> arr)
{
	list<int> result; // don't know its size, so list is better than a vector
	for (int i = 0; i < arr.size(); i++)
	{	// for each index i should I add the number corresponding or not?
		bool found = false;
		for (std::list<int>::iterator it = result.begin();it!= result.end();it++)
		{
			if (arr[i] == *it)
				found = true;
		}
		if (!found)
			result.push_back(arr[i]);
	}
	vector<int> vec_result(result.begin(), result.end());
	return vec_result;
}

vector<int> delete_duplicates_fast_version(vector<int> arr) // O(nlogn)
{
	sort(arr.begin(), arr.end()); // costs O(nlogn) which is < O(n^2)
	list<int> result;
	for (int i = 0; i < arr.size(); i++) // this for loop is O(n) because while and for works on same index
	{
		while (i < arr.size() - 1 && arr[i] == arr[i + 1] )
			i++;
		result.push_back(arr[i]); // O(1) linked-list insertion is fast
	}
	/*if(arr[arr.size()-1] != arr[arr.size() -2 ])//because it will not push last element if 0 0 0 1 1 1 2 2 2 3
		result.push_back(arr[arr.size() -1]);*/
	vector<int> vect_result(result.begin(), result.end());
	return vect_result;
}
int main()
{
    int arr[]={0,0,0,1,1,1,2,2,2,2};
    vector<int>arr2(arr,arr+10);
    vector<int>print=delete_duplicates_fast_version(arr2);

    cout<<unique_array_fast_version(arr2)<<endl;
    for(int i=0;i<print.size();i++)
        cout<<print[i]<<" ";
    cout<<endl;
    return 0;
}
