//#include<iostream>
//#include<queue>
//#include<vector>
//using namespace std;
//
//template <class K, class V>
//class node
//{
//public:
//	V value;
//	K key;
//	node* left;
//	node* right;
//	//node()//Default Constructor
//	//{
//	//	value = NULL;
//	//	Key = NULL;
//	//	left = NULL;
//	//	right = NULL;
//	//}
//	//node(K k, V v)//Overloaded Constructor
//	//{
//	//	value = v;
//	//	Key = k;
//	//	left = NULL;
//	//	right = NULL;
//	//}
//};
//template <class K, class V>
//class SpecialBST
//{
//public:
//	node<K, V>* root;
//	bool stateofinsertion;
//	vector<pair<K, V>> Printing;
//	bool datafound;
//	SpecialBST()//CONSTRUCTOR  O(1)
//	{
//		stateofinsertion = false;
//		datafound = false;
//		root = NULL;
//	}
//	bool insert(K key, V value)//O(n)
//	{
//		stateofinsertion = false;
//		root = insert(root, key, value);
//		return stateofinsertion;
//	};
//	node<K, V>* insert(node<K, V>* root, K key, V value)//For First Node----O(logn)
//	{
//		if (root == NULL)//For First Node
//		{
//			node<K, V>* newN = new node<K, V>;
//			newN->key = key;
//			newN->value = value;
//			newN->left = newN->right = NULL;
//			stateofinsertion = true;
//			return newN;
//		}
//		if (root->key == key)//Prevents Duplicate Data
//			return root;
//		if (key < root->key)//If key<root->key then right rotation is performed
//		{
//			node<K, V>* newN = insert(root->left, key, value);
//			root->left = newN->right;
//			newN->right = root;
//			return newN;
//		}
//		else//If key>root->key then left rotation is performed
//		{
//			node<K, V>* newN = insert(root->right, key, value);
//			root->right = newN->left;
//			newN->left = root;
//			return newN;
//		}
//	}
//	V* search(K key)//search function
//	{
//		datafound = false;
//		root = search(key, root);
//		if (datafound)
//		{
//			cout << "DATA FOUND\n"<<root->value;
//			 return &root->value;
//		}
//		else cout << "DATA NOT FOUND\n";
//		return NULL;
//	}
//	node<K, V>* search(K data, node <K, V>*& Node)//search function
//	{
//		if (Node == NULL)
//			return NULL;
//		if (Node->key == data)
//		{
//			datafound = true;
//			return Node;
//		}
//		else if (Node->key > data) // If key < root->key then right rotation is performed
//		{
//			node<K, V>* rec = search(data, Node->left);
//			if (rec == NULL) 
//			{
//				return Node;
//			}
//			Node->left = rec->right;
//			rec->right = Node;
//			return rec;
//		}
//		else // If key > root->key then left rotation is performed
//		{
//			node<K, V>* rec = search(data, Node->right);
//			if (rec == NULL)
//			{
//				return Node;
//			}
//			Node->right = rec->left;
//			rec->left = Node;
//			return rec;
//		}
//	}
//	bool Delete(K key)//O(logn)
//	{
//		datafound = false;
//		root = Delete(root, key);
//		return datafound;
//	}
//	node<K, V>* Delete(node<K, V>* root, K key) //deletes node and change the root by rotation---O(n)
//	{
//		if (root == NULL) 
//			return NULL;
//		if (key < root->key)
//		{
//			node<K, V>* newN = Delete(root->left, key);
//			if (datafound)
//			{
//				root->left = newN;
//				return root;
//			}
//			if (newN == NULL) 
//				return root;
//			root->left = newN->right;//change the root by right rotation
//			newN->right = root;
//			return newN;
//		}
//		else if (root->key < key)
//		{
//			node<K, V>* newN = Delete(root->right, key);
//			if (datafound) 
//			{
//				root->right = newN;
//				return root;
//			}
//			if (newN == NULL) 
//				return root;
//			root->right = newN->left;//change the root by left rotation
//			newN->left = root;
//			return newN;
//		}
//		else//deleting node
//		{
//			datafound = true;
//			if (root->right == NULL) 
//			{
//				node<K, V>* left = root->left;
//				delete root;
//				return left;
//			}
//			node<K, V>* GN = getSN(root->right);
//			root->key = GN->key;
//			root->value = GN->value;
//			root->right = Delete(root->right, GN->key);
//			return root;
//		}
//	}
//	void getPredecessor(node <K, V>* newN, K key)//finds parent node and returns it
//	{
//		while (newN->right != NULL)
//			newN = newN->right;
//		key = newN->key;
//	}
//	node<K, V>* getSN(node<K, V>* root)//finds smallest node->data and returns it
//	{
//		while (root != NULL && root->left != NULL)
//			root = root->left;
//		return root;
//	}
//	vector<pair<K,V>>* getvaluesinorder()//In order printing
//	{
//		Printing.clear();
//		InOrder(root);
//		return &Printing;         
//	}
//	void InOrder(node<K, V>* root)//In order printing
//	{
//		if (root == NULL) 
//			return;
//		InOrder(root->left);
//		Printing.push_back(make_pair(root->key, root->value));
//		InOrder(root->right);
//	}
//	vector<pair<K, V>>* getvalueslevelwise()//printing level wise
//	{
//		Printing.clear();
//		levelwise(root);
//		return &Printing;
//	}
//	void levelwise(node<K, V>* root)//printing level wise
//	{
//		if (root == NULL) 
//			return;
//		queue<node<K, V>*> q;
//		q.push(root);
//		while (!q.empty())//if bst is not empty then proceed
//		{
//			node<K, V>* front = q.front();
//			q.pop();
//			Printing.push_back(make_pair(front->key, front->value));
//			if (front->left != NULL)
//				q.push(front->left);
//			if (front->right != NULL)
//				q.push(front->right);
//		}
//	}
//	~SpecialBST()//destructor
//	{
//		Destroy(root);
//	}
//	void Destroy(node<K, V>*& Node)//destructor working post order
//	{
//		if (Node)
//		{
//			Destroy(Node->left);
//			Destroy(Node->right);
//			delete Node;
//		}
//	}
//	node<K, V>* FindSuccessor(node<K, V>* root)//Finds successor
//	{
//		node<K, V>* curr = root;
//		while (curr && curr->left != NULL)
//		{
//			curr = curr->left;
//		}
//		return curr;
//	}
//	void InorderPrint()//prints data in sorted order
//	{
//		if (root != NULL)
//		{
//			InorderPrint(root);
//		}
//		else cout << "\nEmpty BST\n";
//		cout << endl;
//	}
//	void InorderPrint(node<K, V>*& newN)//prints data in sorted order
//	{
//		if (newN && newN->left)
//		{
//			InorderPrint(newN->left);
//		}
//		if (newN)
//		{
//			cout << newN->key << "\t";
//		}
//		if (newN != NULL && newN->right != NULL)
//		{
//			InorderPrint(newN->right);
//		}
//	}
//	void PostorderPrint()//prints data in post order
//	{
//		if (root != NULL)
//		{
//			PostorderPrint(root);
//		}
//		else cout << "\nEmpty BST\n";
//		cout << endl;
//	}
//	void PostorderPrint(node<K, V>*& newN)//prints data in post order
//	{
//
//		if (newN && newN->left)
//		{
//			PostorderPrint(newN->left);
//		}
//		if (newN != NULL && newN->right != NULL)
//		{
//			PostorderPrint(newN->right);
//		}
//		if (newN)
//		{
//			cout << newN->key << "\t";
//		}
//	}
//};
//template <class K, class V>
//void printingVector(vector<pair<K,V>>* Printing)//Prints key and values in sorted by roll number order
//{
//	cout << endl;
//	for (int i = 0; i < Printing->size(); i++) 
//	{
//		cout << "  Roll Number: " << Printing->at(i).first << "\n" << Printing->at(i).second << "\n";
//	}
//	cout << endl;
//}
//template <class K, class V>
//class attributes
//{public:
//	string fname, lname , dept;
//	float cgpa = 0.0;
//	int batch = 0;
//	void Insert(string f, string l, int b, string d, float gpa)//constructor
//	{
//		fname = f;
//		lname = l;
//		dept = d;
//		batch = b;
//		cgpa = gpa;
//	}
//	friend ostream& operator<<(ostream& out, const attributes& a)//overloaded << function for class V
//	{
//		out << "  First Name : " << a.fname << endl;
//		out << "  Last Name  : " << a.lname << endl;
//		out << "  Batch      : " << a.batch << endl;
//		out << "  Department : " << a.dept << endl;
//		out << "  CGPA       : " << a.cgpa << endl;
//		return out;
//	}
//};
//template <class K, class V>
//class StudentList
//{
//public:
//	SpecialBST<K, attributes<K, V>> sb;
//	attributes<K, V> at;
//	StudentList(){}
//	bool InsertNewStudent(int rollNumber, string firstName, string lastName, int batch, string department, float cgpa)//Inserts new student at the given roll number
//	{
//		at.Insert(firstName, lastName, batch, department, cgpa);
//		bool flag= sb.insert(rollNumber, at);
//		if (flag == true)
//		{
//			cout << "New Student Inserted\n";
//		}
//		else cout << "Student Already Exists\n";
//		return flag;
//	}
//
//	void search(int rn)//searches an existing student by his/her roll number
//	{
//		 sb.search(rn);
//	}
//
//	bool Delete(int rn)//deletes an existing student's data by his/her roll number
//	{
//		bool flag=sb.Delete(rn);
//		if (flag == true)
//		{
//			cout << "Roll Number Deleted     : " << rn <<"\n";
//		}
//		else cout << "Roll Number Not Found\n";
//		return flag;
//	}
//	bool updateStudent(int oldRollNumber, int newRollNumber, string newFirstName, string newLastName, int newBatch, string newDepartment, float newCgpa)//deletes an existing entry and replaces it
//	{
//		bool flag = sb.Delete(oldRollNumber);
//		if (flag == true)
//		{
//			cout << "Old Roll Number Deleted : "<< oldRollNumber <<"\n";
//
//			at.Insert(newFirstName, newLastName,newBatch, newDepartment, newCgpa);
//			flag = sb.insert(newRollNumber, at);
//			if (flag == true)
//			{
//				cout << "New Roll Number Inserted: "<<newRollNumber <<"\n";
//			}
//			else cout << "DUPLICATE OF NEW ROLL NUMBER EXISTS\n";
//		}
//		else cout << "OLD ROLL NUMBER DOESNOT EXIST\n";
//		return flag;
//	}
//	void printAllStudents()
//	{
//		printingVector(sb.getvaluesinorder());//prints roll numbers and attributes
//	}
//};
//
//int main()
//{
//	StudentList<int, string> stl;
//	char Operation;
//	int rn=0, b=0, nrn=0;
//	string f, l, d;
//	float c;
//begin:
//	cout << "Press I to insert a new student:\nPress D to delete a student:\nPress S to search a student by roll number:\nPress U to update the data of a student:\nPress P to print all students sorted by roll number:\nPress E to exit:\n=>";
//	cin >> Operation;
//	if (Operation == 'I' || Operation == 'i')//Insertion
//	{
//		system("cls");
//		cout << "Enter Roll Number : ";
//		cin >> rn; 
//		cout << "Enter First Name  : ";
//		cin >> f;
//		cout << "Enter Last Name   : ";
//		cin >> l;
//		cout << "Enter Batch Number: ";
//		cin >> b;
//		cout << "Enter Department  : ";
//		cin >> d;
//		cout << "Enter C.G.P.A     : ";
//		cin >> c;
//		stl.InsertNewStudent(rn, f, l, b, d, c);
//		stl.printAllStudents();
//	}
//	else if (Operation == 'D' || Operation == 'd')//Deletion
//	{
//		system("cls");
//		cout << "Enter Roll Number of the student you want to delete the data of: ";
//		cin >> rn;
//		stl.Delete(rn);
//		stl.printAllStudents();
//	}
//	else if (Operation == 'S' || Operation == 's')//Searching
//	{
//		system("cls");
//		cout << "Enter Roll Number of the student you want to search: ";
//		cin >> rn;
//		stl.search(rn);
//
//	}
//	else if (Operation == 'U' || Operation == 'u')//Updating
//	{
//		system("cls");
//		cout << "Enter Roll Number of the student you want to Update the data of: ";
//		cin >> rn;
//		cout << "Enter New Roll Number : ";
//		cin >> nrn;
//		cout << "Enter First Name  : ";
//		cin >> f;
//		cout << "Enter Last Name   : ";
//		cin >> l;
//		cout << "Enter Batch Number: ";
//		cin >> b;
//		cout << "Enter Department  : ";
//		cin >> d;
//		cout << "Enter C.G.P.A     : ";
//		cin >> c;
//		stl.updateStudent(rn, nrn, f, l, b, d, c);
//		cout << "\n------------------------Updated List------------------------\n";
//		stl.printAllStudents();
//	}
//	else if (Operation == 'E' || Operation == 'e')//Exiting
//	{
//		goto exit;
//	}
//	else if (Operation == 'P' || Operation == 'p')//Printing in sorted order
//	{
//		system("cls");
//		stl.printAllStudents();
//	}
//	else
//	{
//		cout << "\nError Invalid Input...\n\n";
//	}
//	goto begin;
//	exit:
//	return 0;
//}