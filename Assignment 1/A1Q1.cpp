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
		/*tail = new node<t>;
		head = tail;*/
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
	void del(int const index)
	{
		if (index < 0)//Check for values lesser than 0
		{
			cout << "\nError: Enter Positive Values\n";
		}
		else if (head != NULL && index == 0)//Deleting 0th Index
		{
			node<t>* current = head;
			head = head->next;
			delete current;
		}
		else
		{
			node<t>* current = head;
			for (int i = 0; i < index - 1; i++)//Finding the required Index
			{
				if (current != NULL)
				{
					current = current->next;
				}
			}
			if (current != NULL && current->next != NULL)//Deleting Index
			{
				node<t>* temp = current->next;
				current->next = current->next->next;
				delete temp;
			}
			else//Check for when the value is greater than the no of Index
			{
				cout << "\nINDEX DOESNOT EXIST!!!";
			}
		}
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
	void Union(ss<t>const& S2)
	{
		node<t>* current= S2.head;
		while (current != NULL)
		{
			insert(current->data);
			current = current->next;
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
	ss<int> s2;
	s1.insert(3);
	s1.insert(2);
	s1.insert(5);
	s1.insert(4);
	s1.insert(7);
	s1.insert(4);
	cout << "Sorted List 1: \n";
	s1.print();
	s1.del(4);
	cout << "\nLinked list After Deletion: \n";
	s1.print();
	s2.insert(1);
	s2.insert(6);
	s2.insert(8);
	s2.insert(9);
	s2.insert(10);
	cout << "\nSorted List 2: \n";
	s2.print();
	s1.Union(s2);
	cout << "\nUnion: \n";
	s1.print();
}