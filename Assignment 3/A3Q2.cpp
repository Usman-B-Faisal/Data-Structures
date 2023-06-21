//#include<iostream>//RADIX SORT FOR STRING AND INT
//#include<string>
//using namespace std;
//
//template<class t>
//class node
//{
//public:
//	t data;
//	node<t>* next;
//	node()//o(1)
//	{
//		data = NULL;
//		next = NULL;
//	}
//	node(t d)//o(1)
//	{
//		data = d;
//		next = NULL;
//	}
//};
//template<class t>
//class Queue
//{
//public:
//	node<t>* head = NULL;
//	node<t>* tail = NULL;
//	Queue() {};//o(1)
//	int size = 0;
//	int divisor = 1;// for int
//	int stringsize = 1;//for string
//	void enqueue(t Data)//o(1) inserts data at tail
//	{
//		node<t>* newN = new node<t>(Data);
//		if (head == NULL)
//		{
//			head = newN;
//			tail = newN;
//			size++;
//		}
//		else
//		{
//			node<t>* curr = head;
//			newN->next = tail->next;
//			tail->next = newN;
//			tail = newN;
//			size++;
//		}
//	}
//	void dequeue()//o(1) removes node from start
//	{
//		node<t>* temp = head;
//		head = head->next;
//		delete temp;
//		size--;
//	}
//	int Size()//o(1) returns size of queue
//	{
//		return size;
//	}
//	t front()//o(1) returns data of head
//	{
//		return head->data;
//	}
//	t rsort()//o(1) radix sort algorithm for int
//	{
//		t data = ((head->data) / divisor) % 10;
//		divisor = divisor * 10;
//		return data;
//	}
//	int rsort1(int size, string Data)//o(1) radix sort algorithm for string
//	{
//		if (stringsize <= size)
//		{
//			char letter = Data[size-stringsize];//to select index e.g for last index size-stringsize = size-1
//			int Ascii = letter;
//			stringsize++;
//			return Ascii;
//		}
//		else printf("\n---error---\n");
//	}
//	bool isEmpty()//for checking if stack if empty o(1)
//	{
//		if (head == NULL)
//			return true;
//		return false;
//	}
//	~Queue()//o(n) destructor
//	{
//		node<t>* temp1 = head;
//		node<t>* temp2 = head;
//		while (temp1 != NULL)//o(n)
//		{
//			temp2 = temp1->next;
//			delete temp1;
//			temp1 = temp2;
//		}
//	}
//	void print() const//O(n)
//	{
//		node<t>* temp = head;
//		if (head == NULL)//When there is no Data
//		{
//			cout << "\nList is Empty!!!\n";
//		}
//		for (int i = 0; temp != NULL; i++)//Printing Data
//		{
//			cout << temp->data << "\t";
//			temp = temp->next;
//		}
//	}
//};
//template <class t>
//void rsint(Queue<t>*& q, Queue<t>*& q1, int& N, int& m, int k)
//{
//	int idigit = 0;
//	if (k==0)//o(n)
//	{
//		for (int i = 0; i < N; i++)//Entering data in q and q1
//		{
//			int data = 0;
//			cout << "Enter data of Queue " << i << ":";
//			cin >> data;
//			q[i].enqueue(data);
//			idigit = q[i].rsort();
//			q1[idigit].enqueue(data);
//		}
//	}
//	else if (k>0)//o(n)
//	{
//		for (int i = 0; i < N; i++)
//		{
//			idigit = q[i].rsort();
//			q1[idigit].enqueue(q[i].head->data);
//		}
//	}
//	for (int i = 0, j = 0; i < m; i++)//o(n^2)
//	{
//		while (!q1[i].isEmpty())
//		{
//			q[j].dequeue();
//			q[j].enqueue(q1[i].head->data);
//			q1[i].dequeue();
//			j++;
//		}
//	}
//}
//void startint()
//{
//	int N = 0, size;
//	cout << "Enter no of keys to be sorted(N): ";
//	cin >> N;
//	cout << "Enter max size of a single key (e.g:420 has max size 3): ";
//	cin >> size;
//	int m = 10;
//	int idigit = 0;
//	Queue<int>* q = new Queue<int>[N];
//	Queue<int>* q1 = new Queue<int>[m];
//	for(int k=0;k<size;k++)//o(k)
//	rsint(q,q1,N,m,k);
//	cout << "Sorted Integers:\t";
//	for (int i = 0; i < N; i++)//o(n)
//	q[i].print();
//	delete[] q;
//	delete[] q1;
//}
//template <class t>
//void rsString(Queue<t>*& q, Queue<t>*& q1, int& N, int& m, int k, int size)
//{
//	int idigit = 0;
//	if (k == 0)//o(n)
//	{
//		for (int i = 0; i < N; i++)
//		{
//			string data;
//			cout << "Enter data of Queue " << i << ":";
//			cin >> data;
//			q[i].enqueue(data);
//			idigit = q[i].rsort1(size, data);
//			q1[idigit].enqueue(data);
//		}
//	}
//	else if (k > 0)//o(n)
//	{
//		for (int i = 0; i < N; i++)
//		{
//			idigit = q[i].rsort1(size, q[i].head->data);
//			q1[idigit].enqueue(q[i].head->data);
//		}
//	}
//	for (int i = 0, j = 0; i < m; i++)//o(n^2)
//	{
//		while (!q1[i].isEmpty())
//		{
//			q[j].dequeue();
//			q[j].enqueue(q1[i].head->data);
//			q1[i].dequeue();
//			j++;
//		}
//	}
//}
//void startString()
//{
//	int N = 0, size = 0;
//	cout << "Enter no of keys to be sorted(N): ";
//	cin >> N;
//	cout << "Enter size of a single key (e.g:abc has size 3 no more no less):";
//	cin >> size;
//	int m = 256;
//	int idigit = 0;
//	Queue<string>* q = new Queue<string>[N];
//	Queue<string>* q1 = new Queue<string>[m];
//	for (int k = 0; k < size; k++)//o(k)
//		rsString(q, q1, N, m, k, size);
//	cout << "Sorted String:\t";
//	for (int i = 0; i < N; i++)//o(n)
//		q[i].print();
//	delete[] q;
//	delete[] q1;
//}
//int main()
//{
//	cout << "----------------------------------------Radix Sort For Integer----------------------------------------\n";
//	startint();
//	cout << "\n----------------------------------------Radix Sort For String----------------------------------------\n";
//	startString();
//	return 0;
//}