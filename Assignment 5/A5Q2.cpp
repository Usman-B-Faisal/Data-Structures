//#include <iostream>
//#include <string>
//#include<fstream>
//#include<sstream>
//#include<cassert>
//using namespace std;
//
//const int EMPTY = 0;
//const int DELETED = 1;
//const int OCCUPIED = 2;
//
//template<class v>
//struct HashItem
//{
//	int key;
//	v value;
//	short status;
//	HashItem()
//	{
//		key = 0;
//		status = 0;
//		value;
//	}
//};
//
//template<class v>
//class HashMap
//{
//public:
//	HashItem<v>* hashArray;
//	int capacity;
//	int currentElements;
//	virtual int getNextCandidateIndex(int key, int i)
//	{
//		i = key % capacity;
//		return i;
//	}
//	HashMap()
//	{
//		currentElements = 0;
//		capacity = 10;
//		hashArray = new HashItem<v>[10];
//	}
//	HashMap(const int Capacity)
//	{
//		currentElements = 0;
//		capacity = Capacity;
//		hashArray = new HashItem<v>[capacity];
//	}
//	void insert(int k, HashItem<v> value)
//	{
//		int temp = k;
//		for (int index = k, count = 0;; index++, count++)
//		{
//			if (count == 0)
//				index = k % capacity;
//			else if (count >= 1)
//			{
//				temp = index;
//				index = getNextCandidateIndex(temp, 0);
//			}
//
//			float loadfactor = 0.75 * capacity;
//			if (currentElements >= loadfactor)
//			{
//				cout << "  Capacity Doubled\n";
//				doubleCapacity();
//			}
//			if ((hashArray[index].status == EMPTY) || (hashArray[index].status == DELETED))
//			{
//				hashArray[index] = value;
//				hashArray[index].status = OCCUPIED;
//				hashArray[index].key = k;
//				currentElements++;
//				cout << "  INSERTED\n";
//				break;
//			}
//		}
//	}
//
//	bool deleteKey(int key)
//	{
//		for (int i = 0; i < capacity; i++)
//		{
//			if (hashArray[i].status == OCCUPIED && hashArray[i].key == key)
//			{
//				hashArray[i].status = DELETED;
//				this->currentElements--;
//				cout << "  Deleted Key " << key <<" " << hashArray[i].value << endl;
//				return true;
//			}
//		}
//		return false;
//	}
//	v* get(int key)
//	{
//		for (int i = 0; i < this->capacity; i++)
//			if (hashArray[i].status == OCCUPIED && hashArray[i].key == key)
//			{
//				cout << "  Key Found: hashArray[" << i << "] = ";
//				return (&hashArray[i].value);
//			}
//
//		cout << "key not found.\n";
//		return nullptr;
//	}
//	void doubleCapacity()
//	{
//		HashItem<v>* temp = hashArray;
//		int c1 = 2 * capacity;
//		hashArray = new HashItem<v>[c1];
//		for (int i = 0; i < capacity; i++)
//		{
//			hashArray[i].value = temp[i].value;
//			hashArray[i].key = temp[i].key;
//			hashArray[i].status = temp[i].status;
//
//		}
//		capacity = c1;
//		delete[] temp;
//	}
//	void printmap()
//	{
//		cout << "\n------------Printing Data------------\n";
//		for (int i = 0; i < capacity; i++)
//		{
//			if (hashArray[i].status == 2)
//				cout << "   Index: " << i << " KEY: " << hashArray[i].key << " Value: " << hashArray[i].value << endl;
//		}
//		cout << "-------------------------------------\n";
//	}
//	~HashMap()
//	{
//		delete[] hashArray;
//		cout << " DESTRUCTOR CALLED\n";
//	}
//};
//template<class v>
//class QHashMap : public HashMap<v>
//{
//public:
//	int getNextCandidateIndex(int key, int i)
//	{
//		i = (key * key) % this->capacity;
//		return i;
//	}
//};
//template<class v>
//class DHashMap : public HashMap<v>
//{
//public:
//	int getNextCandidateIndex(int key, int i)
//	{
//		int first = key % this->capacity;
//		int second = 7 - (key % 7);
//		int index = (first + (i * second)) % this->capacity;
//		return index;
//	}
//};
//
//void populateHash(string filename, HashMap<string>* hash)
//{
//	ifstream in;
//	in.open(filename);
//	int size;
//	in >> size;
//	in.ignore();
//
//	while (size > 0)
//	{
//		string name;
//		getline(in, name);
//
//		int att = name.find(' ');
//		int Value = att + 1;
//		string _key = name.substr(0, att);
//		stringstream id(_key);
//		int ID = 0;
//		id >> ID;
//		name = name.substr(Value, name.size());
//		HashItem<string> a;
//		a.value = name;
//		hash->insert(ID, a);
//		size--;
//	}
//}
//int main()
//{
//	cout << "-------LINEAR PROBING------\n";
//	HashMap<string>* map = new HashMap<string>;
//	populateHash("students.txt", map);
//	cout << *map->get(9) << endl;
//	map->deleteKey(9);
//	//assert(map->get(9) == nullptr);
//	delete map;
//
//	cout << "\n-----Quadratic PROBING-----\n";
//	map = new DHashMap<string>;
//	populateHash("students.txt", map);
//	cout << *map->get(98)<<endl;
//	map->deleteKey(98);
//	//assert(map->get(98) == nullptr);
//	delete map;
//
//	cout << "\n-------Double PROBING------\n";
//	map = new DHashMap<string>;
//	populateHash("students.txt", map);
//	cout << *map->get(101) << endl;
//	map->deleteKey(101);
//	//assert(map->get(98) == nullptr);
//	delete map;
//
//	return 0;
//}