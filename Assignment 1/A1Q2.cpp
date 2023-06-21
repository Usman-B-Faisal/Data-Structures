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
	void rotate(int k)
	{
		int count = 0;
		if (k < 0)
		{
			cout << "INVALID INPUT!!! Enter A Positive Value\nError: Rotation Didnot Occur\n";
		}
		else
		{
			node<t>* temp1 = head;
			for (int i = 0; i < k - 1; i++)//Finding the required Index
			{
				if (temp1 != NULL)
				{
					temp1 = temp1->next;
					count++;
				}
			}
			node<t>* temp2 = temp1;
			while (temp2->next != NULL)//Deleting Index
			{
				temp2 = temp2->next;
				count++;
			}
			if(count<k)//Check for when the value is greater than the no of Index
			{
				cout << "\nINDEX DOESNOT EXIST!!!\nError: Rotation Didnot Occur\n";
			}
			else
			{
				temp2->next = head;
				head = temp1->next;
				temp1->next = NULL;
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
	cout << "List Before Rotation: \n";
	s1.print();
	cout << "\nList After Rotation: \n";
	s1.rotate(4);
	s1.print();
	return 0;
}