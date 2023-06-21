#include<iostream>
using namespace std;
template<class T>
class node// making doubly linked list based stack
{
public:
    T data;
    class node<T>* prev;
    class node<T>* next;
    node()//initialization
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
    node(T a)//initialization
    {
        data = a;
        next = NULL;
        prev = NULL;
    }
};
template<class T>
class UndoStack
{
public:
    node<T>* head = NULL;
    node<T>* top = NULL;
    int count = 0;
    void push(T a)
    {
        node<T>* newN = new node<T>(a);
        if (isEmpty())//for first element
        {
            head = newN;
            top = newN;
        }
        else//for every other element after that
        {
            newN->next = NULL;
            newN->prev = top;
            top->next = newN;
            top = newN;
        }
        count++;
        if (count > 5)//updating stack if it goes beyond the limit 
        {
            node<T>* oldN = head;
            head->next->prev = NULL;
            head = oldN->next;
            delete oldN;
        }
    }
    void pop()
    {
        node<T>* newN = top;
        if (isEmpty())
            cout<<"Empty Stack\n";
        else if (top == head)//deleting the only existing element
        {
            top = NULL;
            head = NULL;
            delete newN;
        }
        else//deleting top element
        {
            top->prev->next = NULL;
            top = newN->prev;
            delete newN;
        }
    }
    bool isEmpty()//for checking if stack if empty
    {
        if (head == NULL)
            return true;
        return false;
    }
   
    void print()
    {
        if (isEmpty())
            cout << "Empty Stack\n";
        else
        {
            node<T>* ptr = top;
            cout << "Elements of Stack :\n";
            while (ptr != NULL)
            {
                cout << ptr->data << "\t";
                ptr = ptr->prev;
            }
            cout << endl;
        }
    }
    ~UndoStack()//destructor
    {
        node<T>* temp1 = top;
        node<T>* temp2 = top;
        while (temp1 != NULL)
        {
            temp2 = temp1->prev;
            delete temp1;
            temp1 = temp2;
        }
        cout << "\nDestructor called\n";
    }
};
int main()
{
    UndoStack<int> us;
    us.push(2);
    us.push(4);
    us.push(6);
    us.push(8);
    us.push(10);
    cout << "---Original List---\n";
    us.print();
    us.push(12);
    us.push(14);
    cout << "---Adding more than limit in Original List---\n";
    us.print();
    return 0;
}