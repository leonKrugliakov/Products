//****************************************************************************************************
//
//      File:                ProductList.cpp
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
//		    1.    Product.h - Contains the Product Structure
//			2.	  DoublyLinkedList - Contains the DoublyLinkedList Class
//			3.	  Node.h - Contains the Node Structure
//
//****************************************************************************************************

#include <iostream>
#include <fstream>
#include <string>

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

#include "Product.h"
#include "DoublyLinkedList.h"

//****************************************************************************************************

char getChoice();
void buildList(DoublyLinkedList<Product>& pro);
void process(DoublyLinkedList<Product>& pro);
void displayProducts(const DoublyLinkedList<Product>& pro);
void displayProductsRev(const DoublyLinkedList<Product>& pro);
void countProducts(const DoublyLinkedList<Product>& pro);
void removeProduct(DoublyLinkedList<Product>& pro);
void findProduct(const DoublyLinkedList<Product>& pro);

//****************************************************************************************************

int main()
{
	DoublyLinkedList<Product> productList;

	buildList(productList);

	process(productList);
}

//****************************************************************************************************

char getChoice() 
{
	char choice;

	cout << endl;

	cout << "A. Search for a product in the list." << endl;
	cout << "B. Remove a product from the list." << endl;
	cout << "C. Count the number of proucts in the list." << endl;
	cout << "D. Display the list in forward order." << endl;
	cout << "E. Display the list in reverse order." << endl;
	cout << "F. Quit." << endl;

	cout << "Please enter a choice: ";

	cin >> choice;

	return toupper(choice);
}

//****************************************************************************************************

void buildList(DoublyLinkedList<Product>& pro) 
{
	ifstream myfile;
	Product product;
	int size = 0;
	myfile.open("ProductFile.txt");
	
	if (myfile.is_open())
	{
		while (myfile >> product)
		{
			
			if (!(pro.insert(product))) 
			{
				cout << "There was an issue inserting a line from the file." << endl;
			}
		}
	}

	myfile.close();
}

//****************************************************************************************************

void process(DoublyLinkedList<Product>& pro) 
{
	char choice = ' ';

	while (choice != 'F')
	{
		choice = getChoice();

		switch (choice) 
		{
		case 'A':
			cout << string(50, '*');
			findProduct(pro);
			break;
		case 'B':
			cout << string(50, '*');
			removeProduct(pro);
			break;
		case 'C':
			cout << string(50, '*');
			countProducts(pro);
			break;
		case 'D':
			cout << string(50, '*');
			displayProducts(pro);
			break;
		case 'E':
			cout << string(50, '*');
			displayProductsRev(pro);
			break;
		case 'F':
			cout << "Quitting.." << endl;
			break;
		default:
			cout << "You have entered an incompatible input." << endl;
		}
	}
}

//****************************************************************************************************

void displayProducts(const DoublyLinkedList<Product>& pro) 
{
	if (!(pro.display())) 
	{
		cout << "Something went wrong with displaying the product list." << endl;
	}
}

//****************************************************************************************************

void displayProductsRev(const DoublyLinkedList<Product>& pro)
{
	if (!(pro.displayReverse()))
	{
		cout << "Something went wrong with displaying the product list in reverse order." << endl;
	}
	
}

//****************************************************************************************************

void countProducts(const DoublyLinkedList<Product>& pro)
{
	int size = pro.getSize();

	cout << endl << "There are " << size << " products in the list." << endl;
}

//****************************************************************************************************

void removeProduct(DoublyLinkedList<Product>& pro)
{
	Product product;

	cout << endl << "Enter the id of the product you would like to remove: ";
	
	cin >> product.pid;

	if (!(pro.remove(product)))
	{
		cout << "Something went wrong with removing the product." << endl;
	}

	cout << product;
}

//****************************************************************************************************

void findProduct(const DoublyLinkedList<Product>& pro)
{
	Product product;

	cout << endl << "Enter the id of the product you would like to find: ";

	cin >> product.pid;

	if (!(pro.retrieve(product)))
	{
		cout << "Something went wrong with retrieving the product." << endl;
	}

	cout << product;
}

