#include <list>
#include <iostream>

using namespace std;

class queue_list
{
private:
	list<int> data;

public:
	// no need for constructor
	void enqueue(int t)
	{
		// user doesn't need to check if it's full
		data.push_back(t);
	}

	void dequeue()
	{
		data.pop_front();
	}

	int front()
	{
		return data.front();
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


//implemented using circular array;
class queue_array
{
private:
	int *arr;
	int capacity;
	int frontt;
	int size;

public:
	queue_array(int s)
	{
		arr = new int[s];
		capacity = s;
		size = 0;
		frontt = 0;
	}
	void enqueue(int t)
	{
	    //user need to check if queue if full or not
		int index = (frontt + size)%capacity;
		arr[index] = t;
		size++;
	}

	void dequeue()
	{
		frontt = (frontt + 1) % capacity;
		size--;
	}

	int front()
	{
		return arr[frontt];
	}


	bool empty()
	{
		return size == 0;
	}

	bool full()
	{
		return size == capacity;
	}

	int get_size()
	{
		return size;
	}
};


void test_queue_list()
{
	queue_list x;
	for (int i = 0; i < 10; i++)
	{
		x.enqueue(i);
		cout << "enqueuing " << i << endl;
		cout << "queue size " << x.size() << endl;
		cout << endl << endl;
	}
	cout << "dequeuing" << endl;
	for (int i = 0; i < 10; i++)
	{
		int top = x.front();
		x.dequeue();

		cout << "dequeue " << top << ", empty? -->" << x.empty() << endl;
		cout << "queue size " << x.size() << endl;
		cout << endl << endl;
	}
}


void test_queue_arr()
{
	queue_array x(10);
	for (int i = 0; i < 10; i++)
	{
		x.enqueue(i);
		cout << "enqueuing " << i << endl;
		cout << "queue size " << x.get_size() <<" empty?"<<x.empty()<< " full?" << x.full() << endl;
		cout << endl << endl;
	}
	cout << "dequeuing" << endl;
	for (int i = 0; i < 5; i++)
	{
		int top = x.front();
		x.dequeue();
	}
	for (int i = 0; i < 5; i++)
	{
		x.enqueue(i);
	}
	for (int i = 0; i < 10; i++)
	{
		int top = x.front();
		x.dequeue();

		cout << "dequeue " << top << ", empty? -->" << x.empty() << " full?" << x.full() << endl;
		cout << "queue size " << x.get_size() << endl;
		cout << endl << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		x.enqueue(i);
		cout << "enqueuing " << i << endl;
		cout << "queue size " << x.get_size() << endl;
		cout << endl << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		int top = x.front();
		x.dequeue();

		cout << "dequeue " << top << ", empty? -->" << x.empty() << endl;
		cout << "queue size " << x.get_size() << endl;
		cout << endl << endl;
	}
}


int main()
{
	test_queue_arr();
}
