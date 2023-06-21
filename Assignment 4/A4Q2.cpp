#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template <class K, class V>
class node
{
public:
	V value;
	K key;
	node* left;
	node* right;
	//node()//Default Constructor
	//{
	//	value = NULL;
	//	Key = NULL;
	//	left = NULL;
	//	right = NULL;
	//}
	//node(K k, V v)//Overloaded Constructor
	//{
	//	value = v;
	//	Key = k;
	//	left = NULL;
	//	right = NULL;
	//}
};
template <class K, class V>
class SpecialBST//CONSTRUCTOR  O(1)
{
public:
	node<K, V>* root;
	bool stateofinsertion; 
	vector<pair<K, V>> Printing;
	bool datafound;
	SpecialBST()
	{
		stateofinsertion = false;
		datafound = false;
		root = NULL;
	}
	bool insert(K key, V value)//O(n)
	{
		stateofinsertion = false;
		root = insert(root, key, value);
		return stateofinsertion;
	};
	node<K, V>* insert(node<K, V>* root, K key, V value)//For First Node----O(logn)
	{
		if (root == NULL)
		{
			node<K, V>* newN = new node<K, V>;
			newN->key = key;
			newN->value = value;
			newN->left = newN->right = NULL;
			stateofinsertion = true;
			return newN;
		}
		if (root->key == key)//Prevents Duplicate Data
			return root;
		if (key < root->key)//If key<root->key then right rotation is performed
		{
			node<K, V>* newN = insert(root->left, key, value);
			root->left = newN->right;
			newN->right = root;
			return newN;
		}
		else //If key>root->key then left rotation is performed
		{
			node<K, V>* newN = insert(root->right, key, value);
			root->right = newN->left;
			newN->left = root;
			return newN;
		}
	}
	V* search(K key)//search function
	{
		datafound = false;
		root = search(key, root);
		if (datafound)
		{
			cout << "DATA FOUND\n";
			return &root->value;
		}
		else cout << "DATA NOT FOUND\n";
		return NULL;
	}
	node<K, V>* search(K data, node <K, V>*& Node)//search function
	{
		if (Node == NULL)
			return NULL;
		if (Node->key == data)
		{
			datafound = true;
			return Node;
		}
		else if (Node->key > data)// If key < root->key then right rotation is performed
		{
			node<K, V>* rec = search(data, Node->left);
			if (rec == NULL)
			{
				return Node;
			}
			Node->left = rec->right;
			rec->right = Node;
			return rec;
		}
		else // If key > root->key then left rotation is performed
		{
			node<K, V>* rec = search(data, Node->right);
			if (rec == NULL)
			{
				return Node;
			}
			Node->right = rec->left;
			rec->left = Node;
			return rec;
		}
	}
	bool Delete(K key)//O(logn)
	{
		datafound = false;
		root = Delete(root, key);
		return datafound;
	}
	node<K, V>* Delete(node<K, V>* root, K key)//deletes node and change the root by rotation---O(n)
	{
		if (root == NULL) 
			return NULL;
		if (key < root->key) 
		{
			node<K, V>* newN = Delete(root->left, key);
			if (datafound)
			{
				root->left = newN;
				return root;
			}
			if (newN == NULL) 
				return root;
			root->left = newN->right;//change the root by right rotation
			newN->right = root;
			return newN;
		}
		else if (root->key < key) 
		{
			node<K, V>* newN = Delete(root->right, key);
			if (datafound) 
			{
				root->right = newN;
				return root;
			}
			if (newN == NULL)
				return root;
			root->right = newN->left;//change the root by left rotation
			newN->left = root;
			return newN;
		}
		else//deleting node
		{
			datafound = true;
			if (root->right == NULL)
			{
				node<K, V>* left = root->left;
				delete root;
				return left;
			}
			node<K, V>* GN = getSN(root->right);
			root->key = GN->key;
			root->value = GN->value;
			root->right = Delete(root->right, GN->key);
			return root;
		}
	}
	node<K, V>* getSN(node<K, V>* root)//finds smallest node->data and returns it
	{
		while (root != NULL && root->left != NULL)
			root = root->left;
		return root;
	}
	void getPredecessor(node <K, V>* newN, K key)//finds parent node and returns it
	{
		while (newN->right != NULL)
			newN = newN->right;
		key = newN->key;
	}
	vector<pair<K,V>>* getvaluesinorder()//In order printing
	{
		Printing.clear();
		InOrder(root);
		return &Printing;         
	}
	void InOrder(node<K, V>* root)//In order printing
	{
		if (root == NULL) return;
		InOrder(root->left);
		Printing.push_back(make_pair(root->key, root->value));
		InOrder(root->right);
	}
	vector<pair<K, V>>* getvalueslevelwise()//printing level wise
	{
		Printing.clear();
		levelwise(root);
		return &Printing;
	}
	void levelwise(node<K, V>* root)//printing level wise
	{
		if (root == NULL) return;
		queue<node<K, V>*> q;
		q.push(root);
		while (!q.empty())//if bst is not empty then proceed
		{
			node<K, V>* front = q.front();
			q.pop();
			Printing.push_back(make_pair(front->key, front->value));
			if (front->left != NULL)
				q.push(front->left);
			if (front->right != NULL)
				q.push(front->right);
		}
	}
	~SpecialBST()//destructor
	{
		Destroy(root);
	}
	void Destroy(node<K, V>*& Node)//destructor working post order
	{
		if (Node)
		{
			Destroy(Node->left);
			Destroy(Node->right);
			delete Node;
		}
	}
	node<K, V>* FindSuccessor(node<K, V>* root)//Finds successor
	{
		node<K, V>* curr = root;
		while (curr && curr->left != NULL)
		{
			curr = curr->left;
		}
		return curr;
	}
	void InorderPrint()//prints data in sorted order
	{
		if (root != NULL)
		{
			InorderPrint(root);
		}
		else cout << "\nEmpty BST\n";
		cout << endl;
	}
	void InorderPrint(node<K, V>*& newN)//prints data in sorted order
	{
		if (newN && newN->left)
		{
			InorderPrint(newN->left);
		}
		if (newN)
		{
			cout << newN->key << "\t";
		}
		if (newN != NULL && newN->right != NULL)
		{
			InorderPrint(newN->right);
		}
	}
	void PostorderPrint()//prints data in post order
	{
		if (root != NULL)
		{
			PostorderPrint(root);
		}
		else cout << "\nEmpty BST\n";
		cout << endl;
	}
	void PostorderPrint(node<K, V>*& newN)//prints data in post order
	{

		if (newN && newN->left)
		{
			PostorderPrint(newN->left);
		}
		if (newN != NULL && newN->right != NULL)
		{
			PostorderPrint(newN->right);
		}
		if (newN)
		{
			cout << newN->key << "\t";
		}
	}
};
template <class K, class V>
void printVector(vector<pair<K,V>>* Printing)
{
	cout << endl;
	for (int i = 0; i < Printing->size(); i++)
	{
		cout << "  Roll Number: " << Printing->at(i).first << "\n" << Printing->at(i).second << "\n";
	}
	cout << endl;
}
template <class K, class V>
class attributes
{public:
	string fname, lname , dept;
	float cgpa = 0.0;
	int batch = 0;
	void Insert(string f, string l, int b, string d, float gpa)//constructor
	{
		fname = f;
		lname = l;
		dept = d;
		batch = b;
		cgpa = gpa;
	}
	friend ostream& operator<<(ostream& out, const attributes& a)//overloaded << function for class V
	{
		out << "  First Name : " << a.fname << endl;
		out << "  Last Name  : " << a.lname << endl;
		out << "  Batch      : " << a.batch << endl;
		out << "  Department : " << a.dept << endl;
		out << "  CGPA       : " << a.cgpa << endl;
		return out;
	}
};
template <class K, class V>
class StudentList
{
public:
	SpecialBST<K, attributes<K, V>> sb;
	attributes<K, V> at;
	StudentList(){}
	bool InsertNewStudent(int rollNumber, string firstName, string lastName, int batch, string department, float cgpa)//Inserts new student at the given roll number
	{
		at.Insert(firstName, lastName, batch, department, cgpa);
		bool flag= sb.insert(rollNumber, at);
		if (flag == true)
		{
			cout << "New Student Inserted\n";
		}
		else cout << "Student Already Exists\n";
		return flag;
	}
	bool Delete(int rn)//deletes an existing student's data by his/her roll number
	{
		bool flag=sb.Delete(rn);
		if (flag == true)
		{
			cout << "Roll Number Deleted     : " << rn <<"\n";
		}
		else cout << "Roll Number Not Found\n";
		return flag;
	}
	void search(int rn)//searches an existing student by his/her roll number
	{
		sb.search(rn);
	}
	bool updateStudent(int oldRollNumber, int newRollNumber, string newFirstName, string newLastName, int newBatch, string newDepartment, float newCgpa)//deletes an existing entry and replaces it
	{
		bool flag = sb.Delete(oldRollNumber);
		if (flag == true)
		{
			cout << "Old Roll Number Deleted : "<< oldRollNumber <<"\n";

			at.Insert(newFirstName, newLastName,newBatch, newDepartment, newCgpa);
			flag = sb.insert(newRollNumber, at);
			if (flag == true)
			{
				cout << "New Roll Number Inserted: "<<newRollNumber <<"\n";
			}
			else cout << "DUPLICATE OF NEW ROLL NUMBER EXISTS\n";
		}
		else cout << "OLD ROLL NUMBER DOESNOT EXIST\n";
		return flag;
	}
	void printAllStudents()
	{
		printVector(sb.getvaluesinorder());//prints roll numbers and attributes
	}
};

int main()
{
	StudentList<int, string> stl;
	stl.InsertNewStudent(007, "James", "Bond", 1953, "British Secret Service", 3.8);
	stl.InsertNewStudent(221, "Sherlock", "Holmes", 1887, "Consulting Detective", 4.0);
	stl.InsertNewStudent(66, "Darth", "Sidious", 1980, "Galactic Republic", 3.9);
	stl.InsertNewStudent(11, "Jane", "Hopper", 2016, "Telekinesis", 2.1);
	stl.InsertNewStudent(9000, "Son", "Goku", 1984, "Extraterrestrial", 1.7);
	stl.InsertNewStudent(99, "Walter", "White", 2008, "Chemistry", 3.9);
	system("cls");
	cout << "------------------------Original List------------------------\n";
	stl.printAllStudents();
	stl.Delete(11);
	stl.updateStudent(99, 96, "Jesse", "Pinkman", 2008, "Cooking", 2.3);
	cout << "\n------------------------Updated List------------------------\n";
	stl.printAllStudents();
	return 0;
}