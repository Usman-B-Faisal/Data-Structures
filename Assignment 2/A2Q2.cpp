#include<iostream>
using namespace std;
template<class T>
class node // making doubly linked list based stack
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
    node(T a)
    {
        data = a;
        next = NULL;
        prev = NULL;
    }
};
template<class T>
class Stack
{
public:
    node<T>* head = NULL;//will be used ahead for logically inverting the stack
    node<T>* top = NULL;//top of stack
    int totalsize = 0;
    int actualsize = 0;
    void push(T a)
    {
        if (totalsize == 0)
        {
            cout << "Enter Stack Size: ";
            cin >> totalsize;
        }
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
        actualsize++;
        if (actualsize == totalsize)//for increasing size of stack
        {
            totalsize = totalsize * 2;
            cout << "\nTOTAL SIZE INCREASED TO " << totalsize << endl;
        }
    }
    void pop()
    {
        node<T>* newN = top;
        if (isEmpty())
            cout << "Empty Stack\n";
        else if (top == head) //deleting the only existing element
        {
            top = NULL;
            head = NULL;
            delete newN;
        }
        else if (top->prev != NULL)//deleting while the stack is not logically inverted
        {
            top->prev->next = NULL;
            top = newN->prev;
            delete newN;
        }
        else//deleting while the stack is logically inverted
        {
            top->next->prev = NULL;
            top = newN->next;
            delete newN;
        }
    }
    bool isEmpty()//for checking if stack if empty
    {
        if (head == NULL)
            return true;
        return false;
    }
    void flipstack()//logically inverting stack
    {
        node<T>* temp;
        temp = top;
        top = head;
        head = temp;
    }
    void print()
    {
        if (actualsize < totalsize / 2)//for decreasing size of stack
        {
            totalsize = totalsize / 2;
            cout << "\nTOTAL SIZE DECREASED TO " << totalsize << endl;
        }
        if (isEmpty())
            cout << "Empty Stack\n";
        else if (head->prev == NULL)//printing while the stack is not logically inverted
        {
            node<T>* ptr = head;
            cout << "Elements of Stack :\n";
            while (ptr != NULL)
            {
                cout << ptr->data << "\t";
                ptr = ptr->next;
            }
            cout << endl;
        }
        else//printing while the stack is logically inverted
        {
            node<T>* ptr = head;
            cout << "Elements of Stack :\n";
            while (ptr != NULL)
            {
                cout << ptr->data << "\t";
                ptr = ptr->prev;
            }
            cout << endl;
        }
    }
    ~Stack()//destructor
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
    Stack<int> s;
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    s.push(10);
    cout << "---Original List---\n";
    s.print();
    s.pop();
    cout << "---Poping Top in Original List---\n";
    s.print();
    s.flipstack();
    cout << "---Reversed List---\n";
    s.print();
    s.pop();
    cout << "---Poping Top in Reversed List---\n";
    s.print();
    return 0;
}