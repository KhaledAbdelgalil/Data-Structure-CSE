#include <iostream>
using namespace std;

// Array implementation
//topp represents last element full
class stack_arr
{
private:
	int *arr; // holds stack data
	int capacity; // size of the stack
	int topp; // represent the top element index

public:
	stack_arr(int x)
	{
		capacity = x;
		arr = new int[x];
		topp = -1;
	}

	void push(int t)
	{
		// user is responsible to check if it's full or not before calling
		arr[++topp] = t;
	}

	void pop()
	{
		topp--;
	}

	int top()
	{
		return arr[topp];
	}

	bool full()
	{
		return topp + 1 == capacity;
	}
	bool empty()
	{
		return topp == -1;
	}

	int size()
	{
		return topp + 1;
	}
};

void test_stack()
{
	stack_arr x(10);
	cout << "stack capacity is 10" << endl;
	for (int i = 0; i < 10; i++)
	{
		x.push(i);
		cout << "pushing "<<i<<endl;
		cout << "stack size " << x.size()<<endl;
		cout << endl << endl;
	}
	cout << "removing" << endl;
	for (int i = 0; i < 10; i++)
	{
		int top = x.top();
		x.pop();
		cout << "removing " <<top<< ", empty? -->" << x.empty() << endl;
		cout << "stack size " << x.size() << endl;
		cout << endl << endl;
	}
}


int main()
{
	test_stack();
}
