//****************************************************************************************************
//
//      File:                Product.h
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
//			2.	  DoublyLinkedList - Contains the DoublyLinkedList Class
//			3.	  Node.h - Contains the Node Structure
//
//****************************************************************************************************

#ifndef PRODUCTLIST_H
#define PRODUCTLIST_H

//****************************************************************************************************

#include <iostream>

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

struct Product 
{
	int pid;
	char pName[50],
		manufacture[50];
	double price;
	int quantity;

	bool operator== (const Product& right) const;
	bool operator!= (const Product& right) const;
	bool operator< (const Product& right) const;
	bool operator<= (const Product& right) const;
	bool operator> (const Product& right) const;
	bool operator>= (const Product& right) const;
	void operator= (Product& right);

	friend ostream &operator << (ostream& ostr, const Product& right);
	friend istream &operator >> (istream& istr, Product& right);
};

//****************************************************************************************************

bool Product::operator==(const Product& right) const
{
	bool status;

	if (this->pid == right.pid)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

//****************************************************************************************************

bool Product::operator!=(const Product& right) const
{
	bool status;

	if (this->pid != right.pid)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

//****************************************************************************************************

bool Product::operator<(const Product& right) const
{
	bool status;

	if (this->pid < right.pid)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

//****************************************************************************************************

bool Product::operator<=(const Product& right) const
{
	bool status;

	if (this->pid <= right.pid)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

//****************************************************************************************************

bool Product::operator>(const Product& right) const
{
	bool status;

	if (this->pid > right.pid)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

//****************************************************************************************************

bool Product::operator>=(const Product& right) const
{
	bool status;

	if (this->pid >= right.pid)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

//****************************************************************************************************

void Product::operator=(Product& right)
{
	this->pid = right.pid;

	strcpy_s(this->pName, right.pName);
	strcpy_s(this->manufacture, right.manufacture);

	this->price = right.price;
	this->quantity = right.quantity;
}

//****************************************************************************************************

ostream &operator<<(ostream &ostr, const Product &obj)
{
	ostr << endl << obj.pid << " " << obj.pName << " "
		<< obj.manufacture << " " << obj.price << " "
		<< obj.quantity << endl;

	return ostr;
}

//****************************************************************************************************

istream &operator>>(istream &istr, Product &pro)
{
	istr >> pro.pid;
	istr.ignore();
	istr.getline(pro.pName, 50, '\n');
	istr.getline(pro.manufacture, 50, '\n');
	istr >> pro.price;
	istr >> pro.quantity;

	return istr;
}

//****************************************************************************************************

#endif