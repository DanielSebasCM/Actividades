// =================================================================
//
// File: list.h
// Author:
// Date:
//
// =================================================================
#ifndef LIST_H
#define LIST_H

#include <string>
#include <sstream>
#include "exception.h"
#include "header.h"

template <class T>
class List;

// =================================================================
// Definition of the Node class
// =================================================================
template <class T>
class Node
{
private:
	Node(T);
	Node(T, Node<T> *);

	T value;
	Node<T> *next;

	friend class List<T>;
};

// =================================================================
// Constructor. Initializes the value of the node. The variable next
// is initialized to null.
//
// @param val, stored value in the node.
// =================================================================
template <class T>
Node<T>::Node(T val) : value(val), next(NULL)
{
}

// =================================================================
// Constructor. Initializes both instance variables.
//
// @param val, stored value in the node.
// @param nxt, the next node.
// =================================================================
template <class T>
Node<T>::Node(T val, Node *nxt) : value(val), next(nxt)
{
}

// =================================================================
// Definition of the List class
// =================================================================
template <class T>
class List
{
private:
	Node<T> *head;
	uint size;

public:
	List();
	~List();

	uint length() const;
	bool empty() const;
	bool contains(T) const;
	void clear();
	std::string toString() const;

	T front() const;
	T last() const;
	T get(uint) const;

	void push_front(T);
	void push_back(T);
	void insert_at(T, uint);

	T pop_front();
	T pop_back();
	T remove_at(uint);

	long int indexOf(T) const;
};

// =================================================================
// Constructor. Initializes both instance variables to zero.
// =================================================================
template <class T>
List<T>::List() : head(NULL), size(0)
{
}

// =================================================================
// Destructor. Remove all items from the list.
// =================================================================
template <class T>
List<T>::~List()
{
	clear();
}

// =================================================================
// Returns if the list is empty or not
//
// @returns true if the list is empty, false otherwise.
// =================================================================
template <class T>
bool List<T>::empty() const
{
	return (head == NULL);
}

// =================================================================
// Returns the number of items in the list.
//
// @returns size, the number of items in the list.
// =================================================================
template <class T>
uint List<T>::length() const
{
	return size;
}

// =================================================================
// Determines if an item is in the list.
//
// @returns true if val is in the list, false otherwise
// =================================================================
template <class T>
bool List<T>::contains(T val) const
{
	Node<T> *current;

	current = head;
	while (current != NULL)
	{
		if (current->value == val)
			return true;

		current = current->next;
	}
	return false;
}

// =================================================================
// Remove all items from the list.
// =================================================================
template <class T>
void List<T>::clear()
{
	Node<T> *current, *next_node;

	current = head;
	while (current != NULL)
	{
		next_node = current->next;
		delete current;
		current = next_node;
	}

	head = NULL;
	size = 0;
}

// =================================================================
// String representation of the elements in the list.
//
// @returns a string containing all the elements of the list.
// =================================================================
template <class T>
std::string List<T>::toString() const
{
	std::stringstream aux;
	Node<T> *current;

	current = head;
	aux << "[";
	while (current != NULL)
	{
		aux << current->value;
		if (current->next != NULL)
			aux << ", ";

		current = current->next;
	}
	aux << "]";
	return aux.str();
}

// =================================================================
// Returns the first item in the list.
//
// @returns the object T at the beginning of the list.
// @throws NoSuchElement, if the list is empty.
// =================================================================
template <class T>
T List<T>::front() const
{
	if (empty())
		throw NoSuchElement();

	return head->value;
}

// =================================================================
// Returns the last item in the list.
//
// @returns the object T at the end of the list.
// @throws NoSuchElement, if the list is empty.
// =================================================================
template <class T>
T List<T>::last() const
{
	Node<T> *current;

	if (empty())
		throw NoSuchElement();

	current = head;
	while (current->next != NULL)
		current = current->next;

	return current->value;
}

// =================================================================
// Returns the element that is in the position indicated by index.
//
// @returns the element in index
// @throws IndexOutOfBounds, if index >= size.
// Complexity O(n) where n = index
// =================================================================
template <class T>
T List<T>::get(uint index) const
{
	if (index >= size)
		throw IndexOutOfBounds();

	Node<T> *current = head;

	for (size_t i = 0; i < index; i++)
		current = current->next;

	return current->value;
}

// =================================================================
// Add an item to the beginning of the list. Increase the size of
// the list.
// =================================================================
template <class T>
void List<T>::push_front(T val)
{
	Node<T> *new_head;

	new_head = new Node<T>(val);
	new_head->next = head;
	head = new_head;
	size++;
}

// =================================================================
// Add an item to the end of the list. Increase the size of
// the list.
// =================================================================
template <class T>
void List<T>::push_back(T val)
{
	Node<T> *current, *new_tail;

	if (empty())
	{
		push_front(val);
		return;
	}

	current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}

	new_tail = new Node<T>(val);
	new_tail->next = current->next;
	current->next = new_tail;
	size++;
}

// =================================================================
// Add an element in index (0 <= index <= size). The element that
// was in that position is shifted to the right.
//
// @throws IndexOutOfBounds, if index > size.
// Complexity O(n) where n = index
// =================================================================
template <class T>
void List<T>::insert_at(T val, uint index)
{
	if (index > size)
		throw IndexOutOfBounds();

	if (index == 0)
		return push_front(val);

	Node<T> *current, *new_node;
	current = head;

	for (size_t i = 0; i < index - 1; i++)
		current = current->next;

	new_node = new Node<T>(val, current->next);
	current->next = new_node;
	size++;
}

// =================================================================
// Delete the item at the beginning of the list.
//
// @returns the element that was at the beginning of the list.
// @throws NoSuchElement if the list is empty
// =================================================================
template <class T>
T List<T>::pop_front()
{
	T val;
	Node<T> *p;

	if (empty())
		throw NoSuchElement();

	p = head;

	head = p->next;
	val = p->value;

	delete p;
	size--;
	return val;
}

// =================================================================
// Delete the item at the end of the list.
//
// @returns the element that was at the end of the list.
// @throws NoSuchElement if the list is empty
// =================================================================
template <class T>
T List<T>::pop_back()
{
	Node<T> *current, *previous;
	T val;

	if (empty())
	{
		throw NoSuchElement();
	}

	if (size == 1)
	{
		return pop_front();
	}

	previous = NULL;
	current = head;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}

	previous->next = current->next;
	val = current->value;

	delete current;
	size--;

	return val;
}

// =================================================================
// Delete the element found in index (0 <= index <size).
//
// @returns the element that was in index.
// @throws IndexOutOfBounds, if index >= size.
// Complexity O(n) where n = index
// =================================================================
template <class T>
T List<T>::remove_at(uint index)
{
	T aux;

	if (index >= size)
		throw IndexOutOfBounds();

	if (index == 0)
		return pop_front();

	Node<T> *current, *tmp_node;
	current = head;

	for (size_t i = 0; i < index - 1; i++)
		current = current->next;

	tmp_node = current->next;
	aux = tmp_node->value;
	current->next = tmp_node->next;

	delete tmp_node;
	size--;

	return aux;
}

// =================================================================
// Returns the position of an item in the list.
//
// @returns the position of an item in the list, -1 otherwise.
// @throws IndexOutOfBounds, if index >= size.
// Complexity O(n) where n = size
// =================================================================
template <class T>
long int List<T>::indexOf(T val) const
{
	int index = 0;

	Node<T> *current;
	current = head;
	while (current != NULL)

	{
		if (current->value == val)
		{
			return index;
		}
		current = current->next;
		index++;
	}
	return -1;
}

#endif /* LIST_H */
