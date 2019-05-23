#include <list>
#include <iostream>

using namespace std;


class stack_list
{
private:
	list<int> data;
public:
	// no need for constructor

	void push(int t)
	{
		// user doesn't need to check if it's full
		data.push_back(t);
	}

	void pop()
	{
		data.pop_back();
	}

	int top()
	{
		return data.back();
	}


	bool empty()
	{
		return data.size() == 0;
	}

	int size()
	{
		return data.size();
	}
};


void test_stack()
{
	stack_list x;
	// no stack capacity needed
	for (size_t i = 0; i < 10; i++)
	{
		x.push(i);
		cout << "pushing " << i<<endl;
		cout << "stack size " << x.size() << endl;
		cout << endl << endl;
	}
	cout << "removing" << endl;
	for (size_t i = 0; i < 10; i++)
	{
		int top = x.top();
		x.pop();

		cout << "removing " << top << ", empty? -->" << x.empty() << endl;
		cout << "stack size " << x.size() << endl;
		cout << endl << endl;
	}
}




int main()
{
	test_stack();
}
