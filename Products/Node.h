//****************************************************************************************************
//
//      File:                Node.h
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
//			3.	  DoublyLinkedList.h - Contains the DoubleLinkedList Class
//
//****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//****************************************************************************************************

template <typename TYPE>
struct Node
{
	TYPE data;
	Node<TYPE>* prev;
	Node<TYPE>* next;
	Node();
	Node(TYPE d, Node<TYPE>* p = nullptr, Node<TYPE>* n = nullptr);
};

//****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node()
{
	data = 0;
	next = prev = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node(TYPE d, Node<TYPE>* n, Node<TYPE>* p)
{
	data = d;
	prev = p;
	next = n;
}

//****************************************************************************************************

#endif