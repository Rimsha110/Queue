#include <iostream>
using namespace std;
template <class T>
class Queue
{
private:
	int count;
	int front;
	int rear;
	int size;
	T* queue;
public:
	Queue()
	{
		count = 0;
		size = 1;
		front = rear = -1;
		queue = nullptr;
	}
	Queue(int s)
	{
		size = s;
		count = 0;
		front = rear = -1;
		queue = new T[s];
	}
	~Queue()
	{
		if (queue)
		{
			delete[] queue;
			queue = nullptr;
		}
	}
	bool isFull()
	{
		if (count == size)
			return true;
		else
			return false;
	}
	bool isEmpty()
	{
		if (count == 0)
			return true;
		else
			return false;
	}
	void enqueue(T val)
	{
		if (isFull())
		{
			resize();
		}
		rear = (rear + 1) % size;
		queue[rear] = val;
		count++;
		if (front == -1)
		{
			front = 0;
		}
	}
	void dequeue()
	{
		if (isEmpty())
		{
			cout << "Your queue is empty! There is nothing to dequeue. \n";
		}
		else
		{
			front++;
			count--;
			if (count == 0)
			{
				front = -1;
				rear = -1;
			}
		}
	}
	T peak()
	{
		return queue[front];
	}
	void resize()
	{
		T* temp;
		temp = new T[2 * size];
		int i = 0;
		while (front != rear)
		{
			temp[i] = queue[front];
			front = (front + 1) % size;
			i++;
		}
		temp[i] = queue[front];
		size = 2 * size;
		front = 0;
		rear = count - 1;
		delete[] queue;
		queue = temp;
	}
};
int main()
{
	int s;
	cout << "Enter size of queue: ";
	cin >> s;
	while (s <= 0)
	{
		cout << "Please enter non-zero positive size: ";
		cin >> s;
	}
	Queue <int> que(s);
	que.enqueue(2);
	que.enqueue(5);
	que.enqueue(7);
	que.enqueue(9);
	cout << que.peak() << endl;
	return 0;
}