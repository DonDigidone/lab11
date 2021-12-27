#include <iostream>
using namespace std;

template <typename T>
struct Element
{
	T number;
	Element* next;
	Element* prev;
};

template <typename T>
class Queue
{
	Element<T>* head;
	Element<T>* tail;
public:
	Queue();
	Queue(const Queue& other);
	Queue(Queue&& other)noexcept;
	~Queue();

	void push(T element);
	T pop();
	T peek();
	int get_size();

	Queue& operator=(const Queue& other);
	Queue& operator=(Queue&& other)noexcept;

	friend ostream& operator<<(ostream& stream, const Queue& that)
	{
		if (that.head == NULL) return stream << "Очередь пуста";
		Element<T>* temp = that.head;
		while (temp != that.tail)
		{
			stream << temp->number << " ";
			temp = temp->prev;
		}
		return stream << temp->number;
	}
};
