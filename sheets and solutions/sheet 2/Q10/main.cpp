//if n%3=1 &m%3=2 then (n+m)%3=0 divisible by 3
//divide elements 9 8 7 6 5 4 3 2 1
//9 6 3 rem=0
//8 5 2 rem=2
//7 4 1 rem=1
#include <iostream>
#include<queue>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;
// 981 > 891 > 198 > 189 --> all 4 numbers are divisible by 3
// 9 8 7 6 5 4 3 2 1 1
// 9 6 3
// 8 5 2
// 7 4 1 1 --> sum = 46 % 3 = 1
// =======
// 9 8 7 6 5 4 3 2 2 1
// 9 6 3
// 8 5 2 2
// 7 4 1  --> 47 % 3 = 2
void largestmultipleof3(vector<int> numbers)
{
	// numbers are limited to 0-9
	// --> so [1,2,3,4,5,6,7,8,9] is a valid vector
	// --> [1, 9, 1, 1, 2, 4, 8, 7, 4] is a valid vector also
	queue<int> zero,one, two;
	int total_sum = 0;
	bool possible = true;
	sort(numbers.begin(), numbers.end());
	for (size_t i = 0; i < numbers.size(); i++)
	{
		int number = numbers[i];
		if (number % 3 == 0)
		{
			zero.push(number);
			total_sum += number;
		}
		else if (number % 3 == 1)
		{
			one.push(number);
			total_sum += number;
		}
		else  // remainder = 2
		{
			two.push(number);
			total_sum += number;
		}
	}

	if (total_sum % 3 == 1)
	{

		// numbers are 9 2 2 1 1 1
		// the answer could be either --> 9 2 2 1 1 or 9 1 1 1
		// of course the first is better as i'll remove only one

		if (one.size() >= 1)
		{
			one.pop();
		}
		else if (two.size() >= 2)
		{

			two.pop();
			two.pop();
		}
		else
		{
			possible = false;
		}
	}
	else if(total_sum %3 == 2)
	{
		// numbers are 9 2 1 1 1
		// the answer could be either --> 9 1 1 1 or 9 2 1
		// of course the first is better as i'll remove only one

		if (two.size() >= 1)
		{
			two.pop();
		}
		else if (one.size() >= 2)
		{
			one.pop();
			one.pop();
		}
		else
		{
			possible = false;
		}
	}

	// now the queues contains the numbers that has sum divisable by 3
	// now we want them sorted from big to small
	if (possible)
	{
		list<int> temp;
		queue<int> x[] = { zero,one,two };
		for (size_t i = 0; i < 3; i++)
		{
			while (!x[i].empty())
			{
				temp.push_back(x[i].front());
				x[i].pop();
			}
		}
		// now create a sorted vector out of the list
		vector<int> result(temp.begin(), temp.end());
		sort(result.begin(), result.end());
		int number = 0;
		for (size_t i = 0; i < result.size(); i++)
		{
			if (i != 0)
				number *= 10;
			number += result[result.size() - i - 1];

		}
		cout << number << endl;
	}
	else
	{
		cout << "Not Possible!" << endl;
	}

}


void test_largest_multiple_of_3()
{
	int arr1[] = { 8, 1, 7, 6, 0 };// 8 7 6 0
	int arr2[] = { 9, 1, 1, 2, 2 };// 9 2 2 1 1
	int arr3[] = { 9, 1, 0, 2, 2 };// 9 2 1 0
	int arr4[] = { 8, 2, 0, 0, 0 };// 0
	vector<int> x(arr1, arr1 + 5);
	vector<int> m(arr2, arr2 + 5);
	vector<int> n(arr3, arr3 + 5);
	vector<int> o(arr4, arr4 + 5);
	largestmultipleof3(x);
	largestmultipleof3(m);
	largestmultipleof3(n);
	largestmultipleof3(o);
}
int main()
{
    test_largest_multiple_of_3();
    return 0;
}
