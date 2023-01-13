//****************************************************************************************************
//
//      File:                DoubleLinkedList.h
//
//      Student:             Leon Krugliakov
//
//      Assignment:          Program #7
//
//      Course Name:         Data Structures I
//
//      Course Number:       COSC 3050 - 10
//
//      Due:                 October 12th, 2020
//
//
//      This program reads in data from a file into a custom Products structure and 
//		arranges them in a doubly linked list.
//		Then the program gives the user options to display the list in order or in
//		reverse order. As well as the option to count the number of items in the list,
//		search and display an item in the list using it's product id, or to remove
//		an item from the list based off of it's product id.
//
//      Other files required:
//		    1.    ProductList.cpp - Contains the driver function
//			2.	  Product.h - Contains the Product structure
//			3.	  Node.h - Contains the Node Structure
//
//****************************************************************************************************

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

//****************************************************************************************************

#include "Node.h"

//****************************************************************************************************

template <typename T>
class DoublyLinkedList
{
private:
	Node<T>* front;
	Node<T>* rear;
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	bool insert(const T & dataIn);
	bool insertRear(const T & dataIn);
	bool insertBefore(const T & dataIn, const T & dataBefore);
	bool remove(T & dataOut);
	bool removeFront(T & dataOut);
	bool retrieve(T & dataOut) const;
	bool viewFront(T & dataOut) const;
	bool viewRear(T & dataOut) const;
	bool display() const;
	bool displayReverse() const;
	int getSize() const;
	bool isFull() const;
	bool isEmpty() const;
};

//****************************************************************************************************

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() 
{
	front = rear = nullptr;
}

//****************************************************************************************************

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() 
{
	Node<T>* temp;

	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}

	rear = nullptr;
}

//****************************************************************************************************

template <typename T>
bool DoublyLinkedList<T>::insertRear(const T & dataIn) 
{
	bool success = false;

	Node<T>* pBefore = rear;
	Node<T>* pAfter = nullptr;
	Node<T>* pNew = new (nothrow) Node<T>(dataIn, pBefore, pAfter);

	if (pNew != nullptr)
	{
		if (pBefore != nullptr)
		{
			pBefore->next = pNew;
		}
		else
		{
			front = pNew;
		}

		rear = pNew;

		success = true;
	}

	return success;
}


template <typename T>
bool DoublyLinkedList<T>::insertBefore(const T & dataIn, const T & dataBefore)
{
	bool success = false;

	Node<T>* pSearch = front;

	while (pSearch->data != dataBefore)
	{
		pSearch->next;
	}

	Node<T>* pNew = new (nothrow) Node<T>(dataIn, pSearch->prev, pSearch);

	if (pNew != nullptr)
	{
		if (pSearch->prev != nullptr)
		{
			pSearch->prev->next = pNew;
		}
		else
		{
			front = pSearch->prev;
		}

		if (pSearch != nullptr)
		{
			pSearch->prev = pNew;
		}
		else
		{
			rear = pNew;
		}
	}

	return success;
}

//****************************************************************************************************

template <typename T>
bool DoublyLinkedList<T>::insert(const T & dataIn) 
{
	bool success = false;

	Node<T>* pBefore = nullptr;
	Node<T>* pAfter = front;

	while (pAfter != nullptr && pAfter->data < dataIn)
	{
		pAfter = pAfter->next;
	}

	if (pAfter != nullptr)
	{
		pBefore = pAfter->prev;
	}
	else
	{
		pBefore = rear;
	}

	Node<T>* pNew = new (nothrow) Node<T>(dataIn, pAfter, pBefore);

	if (pNew != nullptr)
	{
		if (pBefore != nullptr)
		{
			pBefore->next = pNew;
		}
		else
		{
			front = pNew;
		}

		if (pAfter != nullptr)
		{
			pAfter->prev = pNew;
		}
		else
		{
			rear = pNew;
		}

		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename T>
bool DoublyLinkedList<T>::remove(T & dataOut) 
{
	bool success = false;

	Node<T>* pDel = front;

	while (pDel != nullptr && pDel->data.pid < dataOut.pid)
	{
		pDel = pDel->next;
	}

	if (pDel != nullptr && pDel->data.pid == dataOut.pid)
	{
		dataOut = pDel->data;

		if (pDel->prev != nullptr)
		{
			pDel->prev->next = pDel->next;
		}
		else
		{
			front = pDel->next;
		}

		if (pDel->next != nullptr)
		{
			pDel->next->prev = pDel->prev;
		}
		else
		{
			rear = pDel->prev;
		}

		delete pDel;
		success = true;
	}

	return success;
}

template <typename T>
bool DoublyLinkedList<T>::removeFront(T & dataOut)
{
	bool success = false;

	Node<T>* pDel = front;


	if (pDel != nullptr)
	{
		dataOut = pDel->data;

		front = pDel->next;

		if (pDel->next != nullptr)
		{
			pDel->next->prev = nullptr;
		}

		delete pDel;

		success = true;
	}

	return success;
}


//****************************************************************************************************

template <typename T>
bool DoublyLinkedList<T>::retrieve(T & dataOut) const
{
	bool success = false;

	Node<T>* temp = front;

	while(temp != nullptr && temp->data.pid != dataOut.pid)
	{
		temp = temp->next;
	}

	if (temp != nullptr && temp->data.pid == dataOut.pid)
	{
		dataOut = temp->data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename T>
bool DoublyLinkedList<T>::viewFront(T & dataOut) const
{
	bool success = false;

	if (front != nullptr)
	{
		dataOut = front->data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename T>
bool DoublyLinkedList<T>::viewRear(T & dataOut) const
{
	bool success = false;

	if (front != nullptr)
	{
		dataOut = rear->data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename T>
bool DoublyLinkedList<T>::display() const
{
	bool success = false;

	Node<T>* temp = front;

	while (temp != nullptr) 
	{
		cout << temp->data;
		temp = temp->next;
		success = true;
	}

	cout << endl;

	return success;
}

//****************************************************************************************************

template <typename T>
bool DoublyLinkedList<T>::displayReverse() const
{
	bool success = false;

	Node<T>* temp = rear;

	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->prev;
		success = true;
	}

	cout << endl;

	return success;
}

//****************************************************************************************************

template <typename T>
int DoublyLinkedList<T>::getSize() const
{
	int size = 0;

	Node<T>* temp = front;

	while (temp != nullptr)
	{
		size++;
		temp = temp->next;
	}

	return size;
}

//****************************************************************************************************

template <typename T>
bool DoublyLinkedList<T>::isFull() const
{
	bool success = false;

	Node<T>* temp = new (nothrow) Node<T>(3, nullptr, nullptr);

	if (temp->data == 3)
	{
		success = true;
		delete[] temp;
	}

	return success;
}

//****************************************************************************************************

template <typename T>
bool DoublyLinkedList<T>::isEmpty() const
{
	return (front == nullptr);
}

//****************************************************************************************************




#endif