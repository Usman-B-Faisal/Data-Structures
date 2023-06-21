#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

template<class t>
class node//singly linked stack
{
public:
    int data;
    node<t>* next;
};

template<class t>
class Stack//stack
{
public:
    node<t>* top;//points at top most element of stack
    void push(t a)//adds new data
    {
        node<t>* newN = new node<t>();
        newN->data = a;
        newN->next = top;
        top = newN;
    }
    bool isEmpty()//checks if stack is empty
    {
        if (top == NULL)
            return true;
        return false;
    }
    void pop()//deletes top most element
    {
        node<t>* temp;
        if (top == NULL) {
            cout << "\nEmpty Stack\n" << endl;
        }
        else {
            temp = top;
            top = top->next;
            delete temp;
        }
    }
    void print()//prints data errors and results
    {
        node<t>* temp;
        if (top == NULL) {
            cout << "\nEmpty Stack";//
        }
        else
        {
            temp = top;
            while (temp != NULL)
            {
                cout << temp->data << "\t";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    ~Stack()//destructor
    {
        node<t>* temp1 = top;
        node<t>* temp2 = top;
        while (temp1 != NULL)
        {
            temp2 = temp1->next;
            delete temp1;
            temp1 = temp2;
        }
        cout << "\nDestructor called\n";
    }
};

template<class t>
class XML//class for checking if xml code is correct
{
    Stack<char> s1;
    int count = 0;
    int linec = 1;
    string line;
    char ele;
    ifstream in;
public:
    XML() //opens xml text file if it exists
    {
        in.open("xml.txt");
        if (!in)
        {
            cout << "\nFile Not Found!\n";
        }
    }
    void Main()//performs all the tasks
    {
        while (getline(in, line))//for inserting a line into c++ from xml text file
        {
            stringstream ls(line);//choosing individual elements from a line
            ls >> ele;
            if (ele == '<')//checking if start is correct
            {
                s1.push(ele);
                ls >> ele;
                if (ele == '?')//checking if its a prolog or not
                {
                    if (linec == 1);//checking if prolog is at line 1
                    {
                        s1.push(ele);
                        cout << "\nProlog Detected\n";

                        while (ele != '?' || ele != NULL)//checking if prolog has correct syntax
                        {
                            ls >> ele;
                        }
                        ls >> ele;
                        if (ele == '?')//closing of a prolog
                        {
                            s1.pop();
                            ls >> ele;
                            if (ele == '>')//checking if prolog closed correctly
                            {
                                s1.pop();
                            }
                            else cout << "\nError in Header...Missing '>'\n";//errors detected
                        }
                        else
                        {
                            cout << "\nError...prolog is missing '?'\n";//errors detected
                        }
                    }
                    else
                    {
                        cout << "\nError...Prolog should be on line 1\n";//errors detected
                    }
                }
                else if (ele == '!')//checking if it is a comment
                {
                    while (ele != NULL)//till the end of line
                    {
                        ls >> ele;
                        if (ele == '-')//checking if i fulfills comments criteria
                        {
                            s1.push(ele);
                            ls >> ele;
                            if (ele == '-')//checking if i fulfills comments criteria
                            {
                                s1.pop();
                                if (s1.isEmpty)
                                {
                                    cout << "\nComment Found\n";
                                }
                            }
                            else
                            {
                                cout << "\nError... Comment missing a '-'\n";//errors detected
                            }
                        }

                    }
                }
                else//checking if it is a tag
                {
                    cout << "\nTag Found\n";
                    while (ele != '>')//till the end of line
                    {
                        if (ele == NULL)//till the end of line
                        {
                            cout << "\nTag not properly closed...'>' missing \n";//Error detected
                        }
                        ls >> ele;//traversal
                    }
                }
            }
            else cout << "\nERROR Line Not Starting With '<'\n";
        }
        while (getline(in, line))//checking syntax od attributes
        {
            if (ele == '"')//for attributes names
            {
                if (atr(ele))
                {
                    cout << "\nFile has correnct attributes\n";//No error detected

                }
                else cout << "\nError...Missing a Quotation Mark\n";//error detected
            }
        }

    }
    bool atb(t a)//attribute fun that checks if the "" is used correctly
    {

        count++;
        if (count>1 && count % 2 == 0)//for even numbers pop will happen
        {
            s1.pop();
            count--;
        }
        else if (count == 1 || count % 2 != 0)//for oddnumbers push will happen
        {
            s1.push(a);
        }
        if (!s1.isEmpty())//checks if attribute was correct
            return false;
        else return true;
    }
};

int main()
{
    XML<char> x;
    x.Main();
    return 0;
}