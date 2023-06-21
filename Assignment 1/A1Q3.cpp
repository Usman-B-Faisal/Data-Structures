#include<iostream>
using namespace std;

template<class t>
class node
{

public:
	t data;
	node* next;
	node()
	{
		data = 0;
		next = NULL;
	}
	node(t x)
	{
		data = x;
		next = NULL;
	}
};

template<class t>
class ss//Sorted Set
{
	node <t>* head;
	node <t>* tail;
public:
	ss()
	{
		tail = NULL;
		head = NULL;
	}
	void insert(t const data)//sorting while inserting New Node and keeping frequency of elements 1 
	{
		node<t>* newN = new node<t>(data);
		node<t>* current;
		if (head == NULL || head->data > newN->data)//case 1: New Node is smaller than Head or there is no Head
		{
			newN->next = head;
			head = newN;
		}
		else //case 2: New Node is greater than Head
		{
			current = head;
			while (current->next != NULL && current->next->data < newN->data)//Finding appopriate location for New Node
			{
				current = current->next;
			}

			if (current->next != NULL)//Inserting New Node before the last Node
			{
				if (current->next->data != newN->data)//Condition to keep the frequency of element 1
				{
					newN->next = current->next;
					current->next = newN;
				}
			}

			else//Inserting Newnode at the end
			{
				newN->next = current->next;
				current->next = newN;
			}

		}
	}
	void reverse()//For reversing the Linked List
	{
		node<t>* current = head, * previous = NULL, * next = NULL;
		while (current != NULL)
		{
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}
		head = previous;
	}
	void print() const
	{
		node<t>* temp = head;
		if (head == NULL)//When there is no Data
		{
			cout << "\nList is Empty!!!\n";
		}
		for (int i = 0; temp != NULL; i++)//Printing Data
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
	}
	~ss()
	{
		node<t>* temp1 = head;
		node<t>* temp2 = head;
		while (temp1 != NULL)
		{
			temp2 = temp1->next;
			delete temp1;
			temp1 = temp2;
		}
		cout << "\nDestructor Called...\n";
	}
};
int main()
{
	ss<int> s1;
	s1.insert(1);
	s1.insert(3);
	s1.insert(2);
	s1.insert(5);
	s1.insert(4);
	s1.insert(7);
	s1.insert(6);
	cout << "Original Linked List: \n";
	s1.print();
	cout << "\nReversed Linked List: \n";
	s1.reverse();
	s1.print();
	return 0;
}