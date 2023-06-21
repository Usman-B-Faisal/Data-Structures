#include<iostream>
using namespace std;

class intervalheap
{
	int hsize;      //number of elements in heap; 
	int maxsize;    //size of the array
	int** h;
public:
	int l = 0;
	int r = 0;
	int index = 0;
	intervalheap(int s = 20)
	{
		maxsize = s;
		hsize = 0;
		h = new int* [2];
		h[0] = new int[maxsize];//store the lower end of closed interval 
		h[1] = new int[maxsize];//store the higher end of closed interval
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < maxsize; j++)
			{
				h[i][j] = -1;
			}
		}
	}
	void insert(int a)
	{
		if (hsize == 0)
		{
			h[0][0] = a;
			l++;
			hsize++;
		}
		else if (hsize == 1)
		{
			h[1][0] = a;
			if (h[0][0] > h[1][0])
			{
				swap(h[0][0], h[1][0]);
			}
			r++;
			hsize++;
		}
		else if (hsize % 2 == 0)
		{
			if(a!=-1)
			{
			h[0][l]=a;
			l++;
			}
			hsize++;
			minheap(l-1, 0);
		}
		else if (hsize % 2 != 0)
		{
			h[1][r]=a;
			r++;
			hsize++;
			if (h[0][l-1] > h[1][r-1])
			{
				swap(h[0][l-1], h[1][r-1]);
				minheap(l - 1, 0);
			}
			
			maxheap(r-1, 0);
		}
	}
	void minheap(int l1, int l2)//while calling minheap(l, l2)
	{
		l2 = (l1-1) / 2;//l1-1/2
		if (l1 <= 0)
			return;
		else if (h[0][l1] < h[0][l2])
		{
			swap(h[0][l1], h[0][l2]);
			l1 = l2;
			minheap(l1, l2);
		}
	}
	void maxheap(int r1, int r2)//while calling maxheap(r, r2)
	{
		r2 = (r1-1) / 2;
		if (r1 <= 0)
			return;
		else if ( h[1][r1] > h[1][r2])
		{
			swap(h[1][r1], h[1][r2]);
			r1 = r2;
			maxheap(r1, r2);
		}
	}
	void heapifyMax(int parent)
	{
		int largest = parent;
		int leftchild = 2 * parent + 1;
		int rightchild = 2 * parent + 2;

		if (leftchild < r-1 && h[1][leftchild] > h[1][largest])
			largest = leftchild;

		if (rightchild < r-1 && h[1][rightchild] > h[1][largest])
			largest = rightchild;

		if (largest != parent)
		{
			swap(h[1][parent], h[1][largest]);
			heapifyMax(largest);
		}
	}
	void heapifyMin(int parent)
	{
		int smallest = parent;
		int leftchild = 2 * parent + 1;
		int rightchild = 2 * parent + 2;

		if (leftchild < l - 1 && h[0][leftchild] < h[0][smallest])
			smallest = leftchild;

		if (rightchild < l - 1 && h[0][rightchild] < h[0][smallest])
			smallest = rightchild;

		if (smallest != parent)
		{
			swap(h[0][parent], h[0][smallest]);
			heapifyMin(smallest);
		}
	}
	void deleteMaxRoot()
	{
		h[1][0] = h[1][r - 1];
		h[1][r - 1] = -1;
		r--;
		heapifyMax(0);
	}
	void deleteMinRoot()
	{
		h[0][0] = h[0][l - 1];
		h[0][l - 1] = -1;
		l--;
		heapifyMin(0);
	}
	bool update(int oldData, int newData)
	{
		bool flag = 0;
		for (int i = 0; i < maxsize; i++)
		{
			if (h[0][i] == oldData)
			{
				h[0][i] = h[0][l - 1];
				h[0][l - 1] = -1;
				l--;
				heapifyMin(i);
				h[0][l] = newData;
				l++;
				hsize++;
				minheap(l - 1, 0);
				flag = 1;
				return flag;

			}
			else if (h[1][i] == oldData)
			{
				h[1][i] = h[1][r - 1];
				h[1][r - 1] = -1;
				r--;
				heapifyMax(i);
				h[1][r] = newData;
				r++;
				hsize++;
				if (h[0][l - 1] > h[1][r - 1])
				{
					swap(h[0][l - 1], h[1][r - 1]);
					minheap(l - 1, 0);
				}
				maxheap(r - 1, 0);
				flag = 1;
				return flag;
			}
		}
		if (flag == 0)
		{
			return flag;
		}
	}
	void swap(int& a, int& b)
	{
		int temp = b;
		b = a;
		a = temp;
	}
	void print()
	{
		cout << "Min Interval:\t";
		for (int i = 0; i < maxsize; i++)
		{
			if (h[0][i] != -1)
				cout << h[0][i] << "\t";
		}
		cout << "\nMax Interval:\t";
		for (int i = 0; i < maxsize; i++)
		{
			if (h[1][i] != -1)
				cout << h[1][i] << "\t";
		}
		cout << endl;
	}
	~intervalheap()
	{
		for (int i = 0; i < 2; i++)
		{
			delete[] h[i];
		}
		delete[] h;
	}
};
int main()
{
	intervalheap a;
	/*int num = 0;
	for (int i = 0;; i++)
	{
		cout << "Enter Value: ";
		cin >> num;
		if (num == -1)
			break;
		a.insert(num);
	}*/
	a.insert(2);
	a.insert(30);
	a.insert(3);
	a.insert(17);
	a.insert(4); 
	a.insert(15); 
	a.insert(4); 
	a.insert(12);
	a.insert(3);
	a.insert(11);
	a.insert(5);
	a.insert(10);
	a.insert(6);
	a.insert(15);
	a.insert(4);
	a.insert(10);
	a.insert(5);
	a.insert(11);
	a.insert(5);
	a.insert(9);
	a.insert(4);
	a.insert(7);
	a.insert(8);
	a.insert(8);
	a.insert(7);
	a.insert(9);
	/*a.insert(-1);
	a.insert(40);*/
	a.print();
	cout << "\n\nAfter Deleting Root:\n";
	a.deleteMaxRoot();
	a.deleteMinRoot();
	a.print();
	cout<<"\n\nUpdate: "<<a.update(4, 1)<<endl;
	a.print();
	return 0;
}
