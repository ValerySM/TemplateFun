// Autor: Valery Sokolov Morgenshteyn ID: 336424221
#ifndef _LIST_H
#define _LIST_H
#include<iostream>

template <class T>

class List
{
public:
	List();
	List(const List& p1);
	T& operator=(T&& data);
	void operator+=(T data);
	void operator-=(T other);
	List<T> UNION(List<T> other);
	List<T> INTERSECT(List<T> other);
	T get_next(bool restart=false);
	int get_size() { return size; };
	friend std::ostream& operator<<(std::ostream& os, const List<T>& dt) {
		auto it = dt.head;
		for (it = dt.head;it!=nullptr&& it->next != nullptr; it = it->next)
			os << it->data << ", ";
		if(it != nullptr)
			os << it->data << std::endl;
		return os;
	};
	~List();
	



private:

	class Node
	{
	public:
		Node(T data);

		T data;
		Node* next;
		
	};

	Node* head;
	int size;
	int cur=0;
	bool contains(T data);
	

};


template<class T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}

template<class T>
List<T>::List(const List& p1)
{
	size = 0;
	head = nullptr;
	for (Node* it = p1.head; it != nullptr; it = it->next)
		*this += it->data;
}

template<class T>
T& List<T>::operator=(T&& other)
{
	~List();
	for (Node* it = other.head; it != nullptr; it = it.next)
		*this += it->data;
	return *this;
}

template<class T>
void List<T>::operator-=(T other)
{
	int index = 0;
	Node* it;
	for (it = head; it != nullptr; it = it->next)
	{
		if (it->data == other)
			break;
		index++;
	}
	if (it == nullptr)
		return;

	//first case
	if (index == 0)
	{
		if (size == 1)
		{
			delete head;
			head = nullptr;
			size--;
			return;
		}
		else //size>1;
		{
			Node* oldHead = head;
			head = head->next;
			delete oldHead;
			size--;
			return;
		}
	}
	else //index>0
	{
		Node* prev = head, * old = nullptr;

		for (int i = 0; i < index - 1; i++)
			prev = prev->next;

		old = prev->next;
		prev->next = old->next;
		delete old;
		size--;
		return;
	}
}

template<class T>
List<T> List<T>::UNION(List<T> other)
{
	List<T> result;
	for (Node* it = other.head; it != nullptr; it = it->next)
		if (!result.contains(it->data))
			result += it->data;

	for (Node* it = this->head; it != nullptr; it = it->next)
		if (!result.contains(it->data))
			result += it->data;
			
	return result;
	//return List<T>();
}

template<class T>
List<T> List<T>::INTERSECT(List<T> other)
{
	List<T> result;
	for (Node* it = other.head; it != nullptr; it = it->next)
		if (!result.contains(it->data) && this->contains(it->data))
			result += it->data;

	for (Node* it = this->head; it != nullptr; it = it->next)
		if (!result.contains(it->data) && other.contains(it->data))
			result += it->data;

	return result;
}
template<class T>
T List<T>::get_next(bool restart)
{
	Node* it = head;
	T res;
	if (restart)
	{
		cur = 0;
	}
	for (int i = 0; i < cur; i++)
	{
		it = it->next;
	}
	cur++;
	if (cur > size-1)
		cur = size-1;
	if (restart)
		cur = 0;
	return it->data;
}
template<class T>
List<T>::Node::Node(T data)
{
	this->data = data;
	this->next = nullptr;
}



template<class T>
List<T>::~List()
{
	for (Node* it = head; it != nullptr;)
	{
		Node* next;
		next = it->next;
		delete it;
		it = next;
	}
}

template<class T>
bool List<T>::contains(T data)
{
	for (Node* it = head; it != nullptr; it = it->next)
		if (it->data == data)
			return true;
	return false;
}

template<class T>
void List<T>::operator+=(T data)
{
	Node* newOne = nullptr, * last = nullptr;
	newOne = new Node(data);
	if (head == nullptr)
	{
		head = newOne;
		size++;
		return;
	}

	for (last = head; 
		last->next != nullptr; 
		 last=last->next);
	last->next = newOne;
	size++;
}

#endif