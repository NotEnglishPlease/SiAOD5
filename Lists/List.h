#ifndef LIST_H
#define LIST_H

using namespace std;

template<typename T>
class List
{
public:

	List();
	~List() {};

	size_t getSize();

	void pushFront(T data);

	void popFront();

	long lFind(T data);

	void earase(size_t index);

	T& operator[](size_t index);

private:
	template<typename T>
	class Node
	{
	public:
		Node* ptrNext;
		T data;

		Node(T data, Node* ptrNext = nullptr)
		{
			this->data = data;
			this->ptrNext = ptrNext;
		}
	};

	Node<T>* head;
	size_t size;
};

#endif
