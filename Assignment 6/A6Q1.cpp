#include <iostream>
#include<fstream>
#include<sstream>
#include<string.h>
using namespace std;

class node
{
public:
	int id;
	int weight;
	string vertice;
	node* next;
	node()//o(1)
	{
		id = 0;
		weight = 0;
		vertice;
		next = NULL;
	}
	node(int i, int w)//o(1)
	{
		id = i;
		weight = w;
		vertice;
		next = NULL;
	}
	node(string v, int i)//o(1)
	{
		id = i;
		weight = 0;
		vertice = v;
		next = NULL;
	}
};
class List
{
public:
	node* head;
	node* tail;
	List()//o(1)
	{
		head = nullptr;
		tail = nullptr;
	};//o(1)
	int size = 0;
	int stringsize = 1;//for string
	void push_back(string v, int id)//o(1) inserts data at tail
	{
		node* newN = new node(v, id);
		if (head == nullptr)//o(1)
		{
			head = newN;
			tail = newN;
			size++;
		}
		else//o(1)
		{
			node* curr = head;
			newN->next = tail->next;
			tail->next = newN;
			tail = newN;
			size++;
		}
	}
	void push(int id, int w)//o(1) inserts data at tail
	{
		node* newN = new node(id, w);
		if (head == NULL)
		{
			head = newN;
			tail = newN;
		}
		else
		{
			node* curr = head;
			newN->next = NULL;//tail->next;
			tail->next = newN;
			tail = newN;
		}
	}
	void pop_front()//o(1) removes node from start
	{
		if (head != NULL) {
			node* temp = head;
			head = head->next;
			delete temp;
			size--;
		}
	}
	int Size()//o(1) returns size of queue
	{
		return size;
	}
	int front()//o(1) returns data of head
	{
		return head->id;
	}
	bool isEmpty()//for checking if stack if empty o(1)
	{
		if (head == NULL)
			return true;
		return false;
	}
	~List()//o(n) destructor
	{
		node* temp1 = head;
		node* temp2 = head;
		while (temp1 != NULL)//o(n)
		{
			temp2 = temp1->next;
			delete temp1;
			temp1 = temp2;
		}
	}
	void print() const//O(n)
	{
		node* temp = head;
		if (head == NULL)//When there is no Data
		{
			cout << "\nList is Empty!!!\n";
		}
		for (int i = 0; temp != NULL; i++)//Printing Data
		{
			cout << "[" << temp->id << " : " << temp->vertice << " : " << temp->weight << "]  ";
			temp = temp->next;
		}
		cout << "\n";
	}
	void outfile()//0(n) saves data in file
	{
		ofstream out;
		out.open("output.txt");
		node* temp = head;
		out << "Every Vertex With It's Location And Weight Is Given Below\n\n";
		for (int i = 0; temp != NULL; i++)
		{
			out << "Vertex: " << temp->id << "	Location: " << temp->vertice << "	Weight: " << temp->weight << "\n";
			temp = temp->next;
		}

	}
	void printrest() const//O(n)
	{
		node* temp = head;
		if (head == NULL)//When there is no Data
		{
			cout << "\nList is Empty!!!\n";
		}
		for (int i = 0; temp != NULL; i++)//Printing Data
		{
			cout << "[" << temp->id << " : " << temp->weight << "]  ";
			temp = temp->next;
		}
		cout << "\n";
	}
};
class Node//o(1) Node class for class minheap
{
public:
	int key;
	int value;
	Node()
	{
		key = 2147483647;
		value;
	}
};
class MinHeap
{
	int hsize;      //number of elements in heap; 
	int maxsize;    //size of the array
public:
	Node* h;
	int l = 0;
	int index = 0;
	MinHeap(int s = 10)
	{
		maxsize = s;
		hsize = 0;
		h = new Node[maxsize];//store the lower end of closed interval 
		for (int i = 0; i < maxsize; i++)
		{
			h[i].key = 2147483647;
		}
	}
	void BuildHeap(int a)//O(1) Insertion of minheap
	{
		if (hsize == 0)
		{
			h[0].value = a;
			l++;
			hsize++;
		}
		else
		{
			h[l].value = a;
			l++;
			hsize++;
			minheap(l - 1, 0);
		}
	}
	void minheap(int l1, int l2)//0(1) Heapify after Insertion
	{
		l2 = (l1 - 1) / 2;//l1-1/2
		if (l1 <= 0)
			return;
		else if (h[l1].key < h[l2].key)
		{
			swap(h[l1].key, h[l2].key);
			swap(h[l1].value, h[l2].value);
			l1 = l2;
			minheap(l1, l2);
		}
	}
	void heapifyMin(int parent)//0(1) Heapify after updation or deletion
	{
		int smallest = parent;
		int leftchild = 2 * parent + 1;
		int rightchild = 2 * parent + 2;

		if (leftchild < l && h[leftchild].key < h[smallest].key)
			smallest = leftchild;

		if (rightchild < l && h[rightchild].key < h[smallest].key)
			smallest = rightchild;

		if (smallest != parent)
		{
			swap(h[parent].key, h[smallest].key);
			swap(h[parent].value, h[smallest].value);
			heapifyMin(smallest);
		}
	}
	void DecreaseKey(int k, int v)//0(n) check for finding smallest route
	{
		for (int i = 0; i < maxsize; i++)
		{
			if (h[i].value == v && h[i].key > k)
			{
				h[i].key = k;
			}
		}
	}
	bool isEmpty()//O(1) checks if heap is empty
	{
		if (h[0].value == -1)
			return true;
		return false;
	}
	void ExtractMin()//0(1) deletes first node of heap while also being a helper function for heapifyMin()
	{
		h[0] = h[l - 1];
		h[l - 1].key = -1;
		h[l - 1].value = -1;
		l--;
		heapifyMin(0);
	}
	void swap(int& a, int& b)//0(1) swaps data
	{
		int temp = b;
		b = a;
		a = temp;
	}
	void print()//0(n) prints data
	{
		cout << "Min Interval:\t";
		for (int i = 0; i < maxsize; i++)
		{
			if (h[i].value > 0)
				cout << h[i].key << "->" << h[i].value << "\t";
		}
	}
	~MinHeap()//0(1) destructor
	{
		delete[] h;
	}
};
class graph
{
public:
	MinHeap a;
	List* Alist;
	int ALsize;
	int count = 0;
	graph()////o(1)
	{
		Alist = NULL;
		ALsize = 0;
	}
	graph(int SIZE)//o(1)
	{
		Alist = new List[SIZE];
		ALsize = SIZE;
	}
	graph(string name)// inputs data from file i.e filehandling
	{
		ifstream f;
		f.open(name);
		int t_vertex;
		f >> t_vertex;

		ALsize = t_vertex;
		Alist = new List[ALsize];
		f.ignore();

		for (int i = 0; i < t_vertex; i++)
		{
			string name;
			getline(f, name);
			int ind = name.find(' ');
			string num = name.substr(0, ind - 1);
			stringstream ID1(num);

			int id;
			ID1 >> id;
			name = name.substr(ind + 1, name.size());

			addinfo(id, name);
		}
		int total_edges;
		f >> total_edges;
		f.ignore();

		for (int i = 0; i < total_edges; i++)
		{
			int s_id, d_id, weight;
			string data;
			stringstream nums;

			getline(f, data);
			int j = data.find(',');
			string l = data.substr(0, j);
			data = data.substr(j + 1, data.size());
			nums << l;
			nums >> s_id;

			j = data.find(' ');
			string s = data.substr(0, j);
			data = data.substr(j + 1, data.size());
			nums.clear();
			nums << s;
			nums >> d_id;

			nums.clear();
			nums << data;
			nums >> weight;

			addedge(s_id, d_id, weight);
		}
	}
	void addinfo(int id, string data)////o(1) store data in Alist[0]
	{
		Alist[0].push_back(data, id);
	}
	void addedge(int u, int v, int w)////o(1) adds edges
	{
		Alist[v].push(u, w);
		Alist[u].push(v, w);
	}
	void OriginalList()
	{
		cout << "----------------------------------------------------------------------------------------------------\n";
		cout << " Original List: \n";
		cout << "[ID : LOCATION : WEIGHT] -> ";
		Alist[0].print();
		cout << "----------------------------------------------------------------------------------------------------\n";
	}
	void ExportData()//o(1) exports data
	{
		Alist[0].outfile();
	}
	void printAlist()//o(n^2) prints data of graph
	{
		cout << "----------------------------------------------------------------------------------------------------\n";
		cout << endl << " UPDATED LIST WITH WEIGHT\n";
		for (int i = 0; i < ALsize; i++)
		{
			if (i == 0)
			{
				cout << "[ID : LOCATION : WEIGHT] -> ";
				Alist[i].print();
			}
			else
			{
				cout << endl;
				cout << "ID " << i << ": [ID : WEIGHT] -> ";
				Alist[i].printrest();
				Alist[i].outfile();
			}
		}
		cout << "----------------------------------------------------------------------------------------------------\n";
	}
	void iheap()
	{
		node* current = Alist[0].head;
		while (current != NULL)
		{
			a.BuildHeap(current->id);
			current = current->next;
		}
		cout << "Shortest Route Will Be The Following From Top-To-Bottom(vertex to vertex)\n";
		for (int i = 0; i < 7; i++)
			ShortestRoute();
	}
	void ShortestRoute()//Algo For findinf Shortest Route
	{
		if (count == 0)
		{
			a.h[0].key = 0;
			count++;
		}
		node* curr = Alist[a.h[0].value].head;
		cout << "Vertex " << a.h[0].value << " Extraced with Weight " << a.h[0].key;
		while (curr != NULL)
		{
			a.DecreaseKey(curr->weight, curr->id);
			curr = curr->next;
		}
		//a.print();
		node* current = Alist[0].head;
		while (current != NULL)
		{
			if (current->id == a.h[0].value)
			{
				current->weight = a.h[0].key;
			}
			current = current->next;
		}
		if (!a.isEmpty())
		{
			a.ExtractMin();
		}
		cout << endl;
	}
	~graph()////o(n^2) destructor of graph
	{
		node* curr;
		for (int i = 0; i < ALsize; i++)
		{
			curr = Alist[i].head;
			while (!Alist[i].isEmpty())
			{
				Alist[i].pop_front();
			}
		}
		cout << "\nDestructor Called\n";
	}
};
void graphinsertion(int op)
{
	graph g(8);
	g.addinfo(1, "office1");
	g.addinfo(2, "lab 1");
	g.addinfo(3, "lab 4");
	g.addinfo(4, "lab 9");
	g.addinfo(5, "lab 10");
	g.addinfo(6, "office2");
	g.addinfo(7, "office6");
	g.addedge(1, 3, 4);
	g.addedge(1, 2, 6);
	g.addedge(2, 4, 2);
	g.addedge(2, 5, 4);
	g.addedge(2, 3, 12);
	g.addedge(3, 6, 2);
	g.addedge(3, 7, 3);
	g.addedge(4, 5, 6);
	g.addedge(5, 6, 2);
	if (op == 2)
	{
		g.iheap();
		//system("cls");
		cout << "\nComplete Data Transfered To File output.txt\n";
		g.ExportData();
	}
	else if (op == 3)
	{
		string temp1;
		cout << "Enter vertex Location: ";
		cin >> temp1;
		g.addinfo(8, temp1);
		cout << "\nEntered Vertex 8 at Location " << temp1 << endl;
	}
	else if (op == 4)
	{
		int temp, temp1, temp2;
		cout << "Enter vertex 1 ranging from 1-7: ";
		cin >> temp1;
		cout << "Enter vertex 2 ranging from 1-7: ";
		cin >> temp2;
		cout << "Enter weight > 0 between above vertices: ";
		cin >> temp;
		if (temp1 <= 7 && temp1 >= 1 && temp2 <= 7 && temp2 >= 1 && temp > 0)
		{
			g.addedge(temp1, temp2, temp);
			cout << "\nEntered edge between " << temp1 << " and " << temp2 << " of weight " << temp << endl;
		}
		else cout << "\nWrong Input\n";
	}
	else if (op == 0 || op == 5)
	{
		g.OriginalList();
		g.iheap();
		g.printAlist();
	}
}
int main()
{
	//graph g("info.txt");
	
	int Operation;
begin:
	cout << "Press 1 to insert graph from a file:\nPress 2 to save graph in a file:\nPress 3 to add vertex in exising graph:\nPress 4 add edge in existing graph:\nPress 5 to print graph:\nPress 6 to exit:\n";
	cin >> Operation;
	if (Operation == 1)//Insertion from graph
	{
		system("cls");
		graphinsertion(0);
	}
	else if (Operation == 2)//save graph in a file
	{
		system("cls");
		graphinsertion(2);

	}
	else if (Operation == 3)//add vertex in exising graph
	{
		system("cls");
		graphinsertion(3);
	}
	else if (Operation == 4)//add edge in existing graph
	{
		system("cls");
		graphinsertion(4);
	}
	else if (Operation == 5 )//print graph
	{
		system("cls");
		graphinsertion(5);
	}
	else if (Operation == 6)//Exit
	{
		system("cls");
		return 0;
	}
	else
	{
		cout << "\nError Invalid Input...\n\n";
	}
	goto begin;
	return 0;
}